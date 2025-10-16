# Web Cache
System that sits between origin server and user.

![[Pasted image 20250806145257.png]]

Cache key:
- Request identifier, concatenate elements of request to form a key.
- If incoming key matches saved key serve cached content.

Set up Cache Rules to determine what to cache.
Ideally static resources which don't change often. 
Dynamic content should not be caches in most cases as it may contain sensitive info.


Web Cache Deception attacks exploit how cache rules are applied.

Rule Types
Static file extension rules
- match file extension of expected type
- Target style sheets or js files

Static Directory rules
- Match url paths
- Target directories with static resources/

File Name rules
- Match file names
- Files that change rarely, robots.txt and favicon.ico

Custom Rules may also be implemented

# Constructing a Web cache deception attack
