
**Layer 6**
- Presentation
- Encoding and Decoding information for network representation
- As well as Eventual Destination Presentation 
- Sender and Receiver should have to to decode each other's messages 

# Representing Text

## Character Encoding
- Assign a numerical value to each character 

Ascii
A starts at 65
a starts at 97
![[Pasted image 20250516143504.png]]

EBCDIC
A -> 193

BNF: One way to represent syntax of a protocol
![[Pasted image 20250516152546.png]]

ASN.1 : Represent syntax of messages
- Works like a struct
- fields if the struct hold information relating to the record (name, id etc...)
- Types: SEQUENCE, SET, CHOICE
	![[Pasted image 20250516154238.png]]
	![[Pasted image 20250516154331.png]]
	
- ASN.1 abtract syntax
- Actual Encoding:
	![[Pasted image 20250516154500.png]]
	![[Pasted image 20250516154600.png]]
	![[Pasted image 20250516154613.png]]
	![[Pasted image 20250516154624.png]]

