
Minman prune
For max plays update alpha then check is a<=b
For min plays update beta and check if a<=b

a = -inf
b = inf
initially (worst possible options)

this level (max's) alpha will be mins beta (one lvl up), this will get passed down to the next subtree of min down

only update alpha and beta after you evaluate and choose (so for the parent one)