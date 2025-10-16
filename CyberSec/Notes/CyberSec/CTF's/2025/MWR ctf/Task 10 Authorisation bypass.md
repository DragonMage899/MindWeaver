### What's the deal with IDOR?

**Insecure Direct Object References (IDOR)** are a common type of authorisation issue. At MWR, we don't like the term IDOR because we feel it doesn't adequately describe the vulnerability, so we rather call this an [authorisation bypass](https://www.mwrcybersec.com/whats-the-deal-with-idor). In an application, objects (such as files, database records, URLs, etc.) often have unique identifiers. When a user interacts with the application, these identifiers are often included in the URL or request parameters. If the application does not properly verify the user's permissions before granting access to these objects, an attacker can modify the identifier to access objects they should not be able to access.

Consider a web application where users can view their account details by accessing a URL like:

`https://example.com/account?id=12345`  

As you can see, the account details are bound to the direct object reference '12345'. If authorisation is improperly implemented, a user could simply change this value to gain access to another user's account details:

`https://example.com/account?id=12346`

dHJ1ZQ==

