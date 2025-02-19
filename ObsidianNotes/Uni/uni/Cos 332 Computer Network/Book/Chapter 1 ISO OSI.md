
# Intro
- Messages need to be sent over a network
- Routing of these messages and all of the intricacies regarding hardware and software variation have been resolved by dividing network functionality into layers
- Each layer presents of an abstract view of the layers below it 

#### OSI
- Open Systems Interconnection

Initially protocols were proprietary, thus building a network required purchasing with a single vendor.
OSI was created to rectify this
Maintained by ISO (actually meaning 'iso - the same as' form greek)
	ISO has national standard boards as members (sabs, bobs, nsi)


#### Protocol
- Set of conventions.
- Agreed upon way of doing things.
- Detailed description of rules to be followed when communicating.


# OSI Layers
Ideally:
- Each layer provides unique functionality
- Each layer provides services for the layer directly above
- Each layer uses services of the layer directly below it

Which is not always possible but for discussion sake and ideal world suffices

## Layer 7 - Application Layer
- Top Layer
- User Applications
	- sending mail, files, shh, browsing etc.
	- assigned a port
	- Application layer protocols are protocols that achieve some networking application-oriented goal
![[Pasted image 20250219100042.png]]
![[Pasted image 20250219100059.png]]
- Certain protocols may require the usage of state that can affect other user interactions

What should the application layer not implement?
- Message carrying medium (physical)
- Message routing

Application layer wants the layers below it to seem like a pipe running from one application layer component to the other. This pipe may end up connecting the sever and client so data may flow seamlessly 

e.g.) 
- Browser puts HTTP request in Pipe
- Web server responds with page through pipe
- This should happen without any consideration of what's happening in the lower layers

Now consider whether message sequence and data representation should form part of layer 7 or a lower layer


## Layer 6 - Presentation Layer
- Data representation varies between computers
	- translation from binary to some format
- This can cause communication issues
- Presentation layer can translate communications to the network standard both to and from allowing the application layer to use the standard of their choosing
- Only needs knowledge of network standard and app layer std
- 