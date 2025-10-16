
# OSINT
https://virelia-water.it.com/
https://crt.sh/?q=virelia-water.it.com

54484d7b5375357373737d.virelia-water.it.com

Hex code: 54484d7b5375357373737d
flag


commits
`-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA512

Please confirm system integrity at 03:00 UTC.
`-----BEGIN PGP SIGNATURE-----`

`iQFQBAEBCgA6FiEEiN7ee3MFE71e3W2fpPD+sISjEeUFAmhZTEQcHGFsZXJ0c0B2`
`aXJlbGlhLXdhdGVyLml0LmNvbQAKCRCk8P6whKMR5ZIUCADM7F0WpKWWyj4WUdoL`
`6yrJfJfmUKgJD+8K1neFosG7yaz+MspYxIlbKUek/VFhHZnaG2NRjn6BpfPSxfEk`
`uvWNIP8rMVEv32vpqhCJ26pwrkAaUHlcPWqM4KYoAn4eEOeHCvxHNJBFnmWI5PBF`
`pXbj7s6DhyZEHUmTo4JK2OZmiISP3OsHW8O8iz5JLUrA/qw9LCjY8PK79UoceRwW`
`tJj9pVsE+TKPcFb/EDzqGmBH8GB1ki532/1/GDU+iivYSiRjxWks/ZYPu/bhktTo`
`NNcOzgEfuSekkQAz+CiclXwEcLQb219TqcS3plnaO672kCV4t5MUCLvkXL5/kHms`
`Sh5H`
`=jdL7`
`-----END PGP SIGNATURE-----`
`
gpg --verify signed-alert.txt
8DDEE7B30513BD5EDD6D9FA4F0FEB084A311E50


gpg --search-keys alerts@virelia-water.it.com
flag
`gpg --search-keys alerts@virelia-water.it.com`
`gpg: data source: https://185.125.188.27:443`
`(1)	Ghost (THM{h0pe_th1s_k3y_doesnt_le4d_t0_m3}) <solstice.tech.ops@gmail.`
	`DarkPulse (THM{h0pe_th1s_k3y_doesnt_le4d_t0_m3}) <alerts@virelia-water`
	 `2048 bit RSA key F8ED5BC28874364F, created: 2025-06-23`
`Keys 1-1 of 1 for "alerts@virelia-water.it.com".  Enter number(s), N)ext, or Q)uit > q`


Osint 1:
Gathering information about about `https://virelia-water.it.com/`
URL takes us to a simple website with not alot going on. 

Running dig get's us the following:
; ANSWER SECTION:
virelia-water.it.com.	1695	IN	CNAME	virelia-water.github.io.
virelia-water.github.io. 3495	IN	A	185.199.111.153

Searching for the url on github reveals the following repo's:
`https://github.com/SanTzu/uplink-config`
`https://github.com/solstice-tech1/staging-panel`
`https://github.com/solstice-tech1/ot-auth-mirror`
`https://github.com/virelia-water`

Within ``https://github.com/solstice-tech1/ot-auth-mirror``
we find the following "https://54484d7b5375357373737d.==virelia-water.it.com==/reset"
54484d7b5375357373737d is the hex encoded flag for OSINT 1 


Osint 3
`https://github.com/virelia-water/compliance` contains the source code for the `https://virelia-water.it.com/` site.
Inspecting commits we find the following:
https://github.com/virelia-water/compliance/commit/bf80b28d73cdbbccaa37c34633de98cd00e7b236

Which gives us:
`From: DarkPulse &lt;alerts@virelia-water.it.com&gt;<br>`
`Add comment`
`More actions`
        `Date: Mon, 15 Jun 2025 02:15:00 +0000<br`
        `Subject: Scheduled OT Calibration`
      `</div>Add commentMore actions`
      `<pre>`
`-----BEGIN PGP SIGNATURE-----`

`iQFQBAEBCgA6FiEEiN7ee3MFE71e3W2fpPD+sISjEeUFAmhZTEQcHGFsZXJ0c0B2`
`aXJlbGlhLXdhdGVyLml0LmNvbQAKCRCk8P6whKMR5ZIUCADM7F0WpKWWyj4WUdoL`
`6yrJfJfmUKgJD+8K1neFosG7yaz+MspYxIlbKUek/VFhHZnaG2NRjn6BpfPSxfEk`
`uvWNIP8rMVEv32vpqhCJ26pwrkAaUHlcPWqM4KYoAn4eEOeHCvxHNJBFnmWI5PBF`
`pXbj7s6DhyZEHUmTo4JK2OZmiISP3OsHW8O8iz5JLUrA/qw9LCjY8PK79UoceRwW`
`tJj9pVsE+TKPcFb/EDzqGmBH8GB1ki532/1/GDU+iivYSiRjxWks/ZYPu/bhktTo`
`NNcOzgEfuSekkQAz+CiclXwEcLQb219TqcS3plnaO672kCV4t5MUCLvkXL5/kHms`
`Sh5H`
`=jdL7`
`-----END PGP SIGNATURE-----`

Searching for public keys related to `alerts@virelia-water.it.com`
with `gpg --search-keys alerts@virelia-water.it.com`
reveals the flag


# Web
10.10.155.21


# Rev1
## Auth1
strcspn -> return number of characters in a string before the matching second 

memcmp -> compare two blocks of memory
- <0 str1 < str2
- >0 str1 > str2
- 0 str1 == str2


Pass in some input
input goes through transform
after transform if input matches "0xefcdab8967452301"
return flag

transform
![[Pasted image 20250628114220.png]]

0x55 = 85(10)

'^' - > xor

input (passed in as a long)
cast char to a byte pointer
deference byte pointer (gives us actual bytes)
xor with 0x55

i.e xor each byte in the string with 0x55 
should return 0xefcdab8967452301

## Rev2
setvbuf
  `setvbuf(stdout,(char *)0x0,2,0);`
  `setvbuf(stdin,(char *)0x0,2,0);`

Change to no buffering
No buffer between user and code
Immediate interactions
code talks directly to kernel

read 31 bytes from the user

![[Pasted image 20250628131050.png]]
bruh

## Rev3
__libc_start_main
- prepare execution env

sockaddr
- Describe socket address

local_74 = socket(2,1,0);
**int socket(int** _domain_**, int** _type_**, int** _protocol_**);**
domain: **AF_INET** (ipv4)
type: **AF_LOCAL** tcp
protocol: 0, default protocol for domain+type

socketaddr1 port 80

port80_socket = listen(ipv4_tcp_socket,5);
5-> backlog
- maximum length to which the queue of pending connections for _sockfd_ may grow


size_of_data_to_socket = recv(socket1_descriptor,&data_duffer,12,256);


**ntohs**

checksum = local_68 & 0xffff | (uint)(dec_256 ^ standard_bytes) << 0x10;
lower 16 bits of ``local_64``
or with
256 xor standard_bytes
bitshift left by 10 buts 
or



Auth3:
The binary contains the code for processing a custom protocol.
Protocol format:
```
Header:
header_value ->16 bit value.
command_id -> needs to be 0x100 to unlock flag.
calculated_checksum -> checksum we calculate locally.
header_body_payload_id -> id for the payload, must match body_payload_id

Body:
body_payload_id->32 bit id, 
payload_size -> must be less than or equal to 0x20 (64)
```

The following checksum needs to pass for the packet to be valid:
`checksum = (header_payload_id & 0x0000FFFF) | ((command_id ^ header_value) << 16);`
c style operators

This is calculated locally and sent to the server where it's calculated again and compared to the header value.
Construct and send a valid packet to the server to unlock the flag

## Reversing 4
Takes in 3 params
`❯ ./jmpproc` 
`Process ID: 0`
`Skip bytes proc: 0`
`Process bound: 0`
`Procedure Error`

read_long
**ssize_t read(int** _fd_**, void** _buf_**[.**_count_**], size_t** _count_**);**
	**read**() attempts to read up to _count_ bytes from file descriptor _fd_
	       into the buffer starting at _buf_.

read(0,user_input,0x13);
0 -> stdin
0x13 -> 19

atol
- str to long int

`(*(code *)(&next_label + processID % 0x14))(skipBytes);`

Take process ID % 0x14 (20)
Add this to next label 

call function at this position with skipBytes as an arguement

rename
`(*(code *)(&next_label + index % 0x14))(arg)`

in next_label
`*(int *)(unaff_RBP + -0x2c) = *(int *)(unaff_RBP + -0x2c) << 1;`
unaff_RBP + -0x2c)
- some stack offset
- cast to int*
- derefence
- left shift by 1

Go to "base stack pointer + -0x2c" and left shit by one

repeat 7 times


`(*(code *)(&next_label2 + param_1 % 0x96))();`
function call
`(*(function_pointer_type *)(base_address + offset))();
`
just a jump

tldr:
Take an index and arg
`next_label` is a jump table
jump to `next_label` +index

rbp -> 

next label does 7 left shifts on rbp

next_label2 does 15 +2 and left shifts on rbp

nextlabel3 adds 150 to rbp

Then inspect rbp
- if (rbp - 44) == 1337
- print the flag

Goal:
Find the sequence of jumps that leads to (rbp - 44) == 1337

(gdb) x/wd $rbp - 0x2c
0x7fffffffe034: 0


left shift: multiply by 2

label1:
rbp = rbp * 14

label2
rbp = (rbp + 2) * 4;
- 15 times 
- 2.8 billion

label 3
rbp += 150


## Flow
processID picks a function pointer from the table starting at next_label
passes skipBytes as parameter