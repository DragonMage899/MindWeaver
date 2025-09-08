# 🐍 Python Crash Course for API Scanner Development

This quick reference is tailored to help you refresh your Python skills and build a custom API scanning tool.

---

## ✅ Primitive Data Types

```python
x = 10               # int
y = 3.14             # float
z = 1 + 2j           # complex
s = "hello"           # string
is_ready = True      # boolean
value = None         # NoneType
arr = [1, 2, 3]       # list
tpl = (1, 2, 3)       # tuple
st = {1, 2, 3}        # set
dct = {"key": "val"}  # dict
```

---

## ✅ Special String Operations

```python
s = "API Scanner"
s.lower(), s.upper(), s.strip(), s.split(), "-".join(["api", "scanner"])
f"Scanning {s}"
```

---

## ✅ Loop Exit Conditions

```python
for i in range(10):
    if i == 5:
        break

while True:
    if some_condition:
        break
```

---

## ✅ Object-Oriented Programming (OOP)

```python
class Scanner:
    def __init__(self, target):
        self.target = target

    def scan(self):
        print(f"Scanning {self.target}")

scanner = Scanner("https://api.example.com")
scanner.scan()
```

### 🔁 Compared to Java/C++

- Uses `__init__` instead of constructor name
- No access modifiers (`public`, `private`, etc.) — uses naming conventions
- `self` is like `this`
    

---

## ✅ Inheritance & Polymorphism

```python
class AuthScanner(Scanner):
    def __init__(self, target, token):
        super().__init__(target)
        self.token = token

    def scan(self):
        print(f"Scanning {self.target} with token {self.token}")

# Polymorphism
scanners = [Scanner("/a"), AuthScanner("/b", "abc")]
for s in scanners:
    s.scan()
```

### Abstract Base Class (Optional)

```python
from abc import ABC, abstractmethod

class BaseScanner(ABC):
    def __init__(self, target):
        self.target = target

    @abstractmethod
    def scan(self):
        pass
```

### Access Modifiers (Convention)

|Prefix|Meaning|
|---|---|
|`name`|public|
|`_name`|protected (by convention)|
|`__name`|private (name mangling)|

```python
class Thing:
    def __init__(self):
        self.public = 1
        self._protected = 2
        self.__private = 3
```

### Multiple Inheritance

```python
class Logger:
    def log(self, msg):
        print(f"[LOG] {msg}")

class APIHandler:
    def handle(self):
        print("Handling request")

class LoggingHandler(Logger, APIHandler):
    pass

handler = LoggingHandler()
handler.handle()
handler.log("done")
```

### Class, Static, and Instance Methods

```python
class Tool:
    tools_used = 0

    def __init__(self, name):
        self.name = name
        Tool.tools_used += 1

    def use(self):
        print(f"{self.name} used.")

    @classmethod
    def stats(cls):
        print(f"Tools used: {cls.tools_used}")

    @staticmethod
    def info():
        print("This is a scanning tool.")
```

### OOP Summary Table

|Feature|Python|Java/C++|
|---|---|---|
|Constructors|`__init__`|ClassName()|
|Inheritance|Implicit (`class A(B)`)|`extends`, `:`|
|Polymorphism|Dynamic, duck-typed|Must implement interfaces|
|Interfaces|`abc.ABC` module|Interfaces / Abstract base|
|Access Control|Naming conventions only|`private`, `protected`, etc|
|Method Overload|Not supported directly|Yes, by signature|

---

## ✅ Scope

```python
x = 10

def foo():
    x = 5
    print(x)  # local

foo()
print(x)      # global

def bar():
    global x
    x = 99
```

---

## ✅ Modules

```python
# mymodule.py
def greet():
    print("Hello")

# usage
import mymodule
mymodule.greet()
```

---

## ✅ JSON

```python
import json

json_str = json.dumps({"url": "https://api.example.com"})
data = json.loads(json_str)

with open("data.json") as f:
    content = json.load(f)
```

---

## ✅ Regex

```python
import re

text = "Authorization: Bearer abc123"
match = re.search(r"Bearer (\w+)", text)
if match:
    token = match.group(1)
```

---

## ✅ PIP

```bash
pip install requests
pip freeze > requirements.txt
pip install -r requirements.txt
```

---

## ✅ Exception Handling

```python
try:
    r = requests.get("https://example.com")
    r.raise_for_status()
except requests.RequestException as e:
    print("Error:", e)
finally:
    print("Done")
```

---

## ✅ Useful Web/API Imports

```python
import requests            # HTTP requests
import json                # JSON manipulation
import re                  # regex
import logging             # structured logs
from urllib.parse import urlparse  # parse URLs
import time                # rate limiting
import os                  # env variables
from concurrent.futures import ThreadPoolExecutor  # parallel scans

```

---

## ✅ Making Custom Requests

```python
# GET
res = requests.get("https://api.github.com/users/octocat")
data = res.json()

# POST with headers and payload
headers = {"Authorization": "Bearer token"}
payload = {"key": "value"}
res = requests.post("https://api.com", json=payload, headers=headers)

# Params
params = {"page": 1}
res = requests.get("https://api.com/items", params=params)
```

---

## ✅ Parsing Responses and Regex

```python
if res.ok:
    print(json.dumps(res.json(), indent=2))

tokens = re.findall(r"Bearer (\w+)", res.text)
```

---

## ✅ Rate Limiting

```python
for url in urls:
    requests.get(url)
    time.sleep(1)  # prevent overload
```

---

## ✅ URL Parsing

```python
parsed = urlparse("https://api.example.com/users?id=3")
print(parsed.scheme, parsed.netloc, parsed.path)
```

---

## ✅ Threaded Requests

```python
def scan_url(url):
    try:
        r = requests.get(url)
        print(f"{url}: {r.status_code}")
    except Exception as e:
        print(f"Error: {e}")

with ThreadPoolExecutor(max_workers=5) as ex:
    ex.map(scan_url, url_list)
```

---

## ✅ Constructors

```python
class Scanner:
    def __init__(self, target):
        self.target = target
```

---

## ✅ Program Entry Point

```python
def main():
    print("Running scanner")

if __name__ == "__main__":
    main()
```

---

## ✅ Special Files

| File          | Purpose                          |
| ------------- | -------------------------------- |
| `__init__.py` | Marks a directory as a package   |
| `__main__.py` | Allows `python -m package` usage |
| `__str__`     | String representation            |
| `__eq__`      | Equality override                |

---

## ✅ Secret Key Handling

### Environment Variable

```python
import os
api_key = os.getenv("API_KEY")
```

```bash
export API_KEY="your-secret"
```

### .env File (with `python-dotenv`)

```bash
# .env
API_KEY=super-secret
```

```python
from dotenv import load_dotenv
load_dotenv()
api_key = os.getenv("API_KEY")
```

### Secure Generation

```python
import secrets
secret = secrets.token_hex(16)
```

---

## ✅ Project Structure (Suggestion)

```
scanner/
├── __init__.py
├── __main__.py
├── core.py
├── config.py
├── modules/
│   ├── auth.py
│   └── headers.py
├── utils.py
└── requirements.txt
```

---

Let me know if you'd like a template to kickstart your scanner tool!