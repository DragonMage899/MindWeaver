
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
- A solution is to have a network standard, where all communications only encode this standard
	- Presentation layer can then translate communications to the network standard both to and from allowing the application layer to use the standard of their choosing
	- Only needs knowledge of network standard and app layer std
- This is unrealistic in modern times
	- Many alternative coding schemes that are not compatible with ascii are looked at for historical interests only
	- Application layer protocols deal with character encoding directly 
		- e.g. Accept-Charset: iso-8859-2, unicode-1-1
		- Then server would deny other charsets
	- Having a encoding layer would've been nice but it has some drawbacks
		- Some conversations are impossible
			- e.g. some encoding's only have latin characters 
- Another use for the presentation use could be date formatting 
- But in general the application later takes over this making the line of when to translate blurry
- Information Represenation
	- XML
	- HTML
	- MIME (Multipurpose Internet Mail Extensions)
	- RFC 822 (std for arpa)
- In practise presentation layer is included in application layer

## Layer 5 - Session Layer
- Provides session-oriented services
- Helps to establish maintain and terminate a session
- Dialogue control (who can say what when)
- Allows for parallel connections\
- Stores Auth
- In Actual usage the session layer refers to a series of steps taken by some application layer protocol 

## **Layer 4 - Transport Layer**
- Pipeline connecting layers 7, 6, and 5 to it's corresponding peer on the other network
- **Enables Process to Process Communication**
- Processes can communicate over the network without having to worry about lower layer details 
- Can also deal with reliable transmission and throttling 

##  Layer 3 - The Network Layer
- Routing 
- A client is typically never directly to a server, series of connections involved
- YOU -> ISP NETWORK -> SERVER ISP NETWORK -> SERVER
- Many ways to accomplish routing
	- pathfinder packet (expensive)
	- routing tables (in your router)
		- tells all non local network stuff to be forwarded to ISP router
		- ISP router points to client routers and Internet exchange router 
- router: computer connected to more than one network
	- can transmit messages between networks

## Layer 2 - Data Link Layer
- data delineation problem - when does a message end
	- end code could simply be part of a message by chance
- Nodes that are broadcasting may interfere with each other 
- Transmission errors occur and may need to be detected
	- Also verifies integrity of above data
- The data link layer is responsible for:
	- Adding some error checking code
	- Add Headers and Trailers
	- Hands message to physical layer
- Ethernet

# Layer 1 - Physical Layer
- Physical connection between nodes
- Medium type, Bit representation, type of plugs etcc
- Network topology considered at physical layer
- Signal, Environmental inteference


# Units of Data (Packets)
- Data consists of a header and payload (could be more)
![[Pasted image 20250323180929.png]]

# Standards
![[Pasted image 20250323181046.png]]
![[Pasted image 20250323181053.png]]
![[Pasted image 20250323181102.png]]
