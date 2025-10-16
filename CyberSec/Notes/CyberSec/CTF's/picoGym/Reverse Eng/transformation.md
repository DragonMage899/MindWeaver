#### Description

I wonder what this really is... [enc](https://mercury.picoctf.net/static/dd6004f51362ff76f98cb8c699510f23/enc) `''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])`


```python
''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])
```


join(a)
a = char(b + c) for i in range list length
- b + c is an int = d
- return char representation of d
- concatenate each char for each flag index

b = b3
- b1 = Get flag at index i
- b2 = left shift b1 by 8 
- b3 = get unicode int of char b2

c->
- c1 = Get flag in at index i + 1
- c2 = get unicode int of char c1

Functions
**join**
- stick together each list item and return the string.

**chr**
- returns char representation of each int

**ord**
- Returns unicode int of passed on char

**<<**
- left shift

**range(start, stop, step)**
- all ints


left shift 8 for every other letter
add the latter of the flag to the shifted value