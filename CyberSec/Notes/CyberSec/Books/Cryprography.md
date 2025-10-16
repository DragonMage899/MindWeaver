**RSA**
Can be broken with feramts factorisation algorithm if primes are close (i.e. close to the square root of N)
N = pq

N = a^2 - b^2 (if a number, N,  is composite, a,b exists such that N is the difference of a^2 - b ^2)
    =(a+b)(a-b)
    a+b = p
    a-b = q

b^2 = a^2 - N
Need to now start guessing a
	Start somewhere around the square root of N and start moving up.
	do this since N = a^2 - b^2.
	Initial guess
		a = ceiling(sqrt(N))
		Then solve for b
		if b is a perfect square, return b
		else a++
	repeat until b is solved 
		If p and q are close this get's solved very quickly 
	p = a + b
	q = a - b
	p and q needs to prime
	n = p * q
	if n == N
		phiN = (p-1)(q-1)
		d = mod_inverse(e, phi_n) (e is given)
		If we have d, we can now sign things on behalf of that service and pretend to be them


# Block Cipher
works on clocks of data with a mode of operation
- mop -> technique to process a sequence of data blocks 

Use a encryption algorithm and decryption algorithm

K -> Key
P -> Plain text 
C -> Cipher text

Encryption algorithm: 
E(K,P) = C

Decryption algorithm: 
D(K,C) = P

Secure provided the key is secret.
More generally no patterns should between the input and output such that techniques such as frequency analysis are not applicable.
Following this the key should not be reversible from the cipher text.



#### AES
Comes from Rijndael algorithm

