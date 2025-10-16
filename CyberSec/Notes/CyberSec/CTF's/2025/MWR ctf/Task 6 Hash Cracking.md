### What is hashing?

Hashing is a fundamental concept in computer science and cryptography. It involves taking input data (such as text, files, or passwords) and running it through a special mathematical function called a hash function. This function converts the input into a fixed-length binary output, which is usually represented with hex. Hash functions typically have the following characteristics:  

1. **Deterministic Output:** The hashing function will always produce the same output for the same provided input.
2. **Fixed Output Size:** Regardless of the size of the function's input, the hash function generates a hash output of a fixed length.
3. **One-Way Function:** Hashing is designed to be irreversible. It is easy to compute the hash value of an input, however, it is extremely difficult and infeasible to reverse-engineer the original input from the computed hash value.
4. **Avalanche Effect:** A small change in the input data should result in a significantly different hash output. This ensures that similar inputs produce vastly different hash outputs.

### Common Uses of Hashing:

- **Data Integrity:** Hashes are used to verify data integrity. By comparing the hash of received data with the original hash, one can determine if the original data has been altered or tampered with.
- **Password Storage:** Instead of storing passwords directly, systems store hashed versions of passwords. When a user enters a password, the system hashes it and compares the result with the stored hash for authentication.
- **Digital Signatures:** Hash functions play a crucial role in generating and verifying digital signatures, ensuring the authenticity of digital documents and transactions.

**So, what's the difference between this and encryption?** Hashing is a one-way mathematical function - once you've hashed something you can't reverse the process and recover the plaintext data from the hash. This is because all hash functions result in some degree of information loss as you are converting a variable length input into a fixed length output. Encryption on the other hand, is fully reversible and as long as you have the required information (algorithm, key, IV, etc) you can recover plaintext data from encrypted ciphertext.

## Hash Cracking:

Hash cracking refers to the process of recovering the original input data from its hash value. Although you can't directly reverse a hash function, there are other ways to recover the plaintext data from hashes. The process of hash cracking typically involves generating potential inputs, hashing them, and comparing the resulting hash values with the target hash until a match is found. This can be completed using one of the following:

- **Dictionary Attack:** An attacker could make use of pre-generated lists (dictionaries) of commonly used passwords to determine the corresponding hash when looking to crack an obtained hash. Dictionary lists incorporate commonly used passwords, and passwords obtained from data leaks.
- **Brute Force Attack:** In a brute force attack, the attacker systematically tries every possible combination of characters until the correct input that hashed to the target hash is found. This method is more time consuming and resource intensive if the password is complex or not in a dictionary.

**There are numerous tools which are built for the purposes of cracking hashes.** Some popular tools include:

- Hashcat
- John The Ripper

### Using hashcat to crack hashes:

**Hashcat** is a powerful command-line tool used for recovering passwords through hash cracking. It supports various algorithms and attack modes, making it versatile for different scenarios. If you're on Kali or using the AttackBox, Hashcat should already be installed.

#### Obtain Hashes:

To crack the hash, you need the hash value itself. Ensure you have the hash you want to crack saved in a file (a text file is sufficient). In this example, we will store a hash in a file called `hash.txt`.

#### Choose Attack Mode:

Hashcat offers various attack modes. The most common are dictionary-based attacks ("`-a 0`"), which makes use of a wordlist, and brute-force attacks ("`-a 3`"), which systematically attempts every possible combination. It is recommended for this that you make use of a wordlist based approach when cracking hashes. In addition to this flag, you should also take note that Hashcat requires that you specify the hash mode with the `-m` flag. This can be used to control which hash types Hashcat will crack. A full list of hash modes supported by Hashcat can be found [here](https://hashcat.net/wiki/doku.php?id=example_hashes).  

#### Prepare Wordlists:

For dictionary attacks, you will need to make use of a wordlist that contains potential passwords. Hashcat supports wordlists in plaintext format. A good wordlist to use for basic hash cracking is the rockyou.txt wordlist, which is a list of breached passwords from the [RockYou breach.](https://en.wikipedia.org/wiki/RockYou) On Kali, this can be found at the following location:  

```plaintext
/usr/share/wordlists/rockyou.txt.gz
```

The file may be compressed in a `.gz` archive and must first be extracted to allow it to be incorporated into a Hashcat command. To extract the file, run the following command in a terminal which is opened to the location of the file:

```plaintext
sudo gzip -d rockyou.txt.gz
```

####   

#### Run Hashcat:

Open your terminal. Use the following basic command structure to crack the hashes in your created "hash.txt" file:

```plaintext
hashcat -a <attack-mode> -m <hash-type> <hash-file> <wordlist-file>
```

Such that the command to crack an MD5 hash (`-m 0`) will look as follows:

```plaintext
hashcat -a 0 -m 0 hash.txt /usr/share/wordlists/rockyou.txt
```

---
 ﻿This will cause hashcat to run on the input hash, and if the hash's corresponding plaintext is contained within the wordlist, the hash will eventually successfully crack.
