`hex_flag.append([str(hex(ord(c)))])`

For each char in flag:
- a = unicode int of passed on char
- b = hex of a
- c = 

```python
def scramble(L):
	A = L
	i = 2
	while (i < len(A)): # from 2 till len A
		A[i-2] += A.pop(i-1)
		A[i-1].append(A[:i-2])
		i += 1
	
	return L
```

pop: 
remove and return element at this position

append:
add to end of list

From pos 2 till end:
Pop the change from i-1 and add it to i-2
At i-1
- Append the slice of the list from 
	- beg
	- untill i-2
- to i-1

abcd


