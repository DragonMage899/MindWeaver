# OSI model
- p2p model
	- layers 4,5,6,7 only communicates to peers at destination

## Presentation layer
- Dresses up way to convey message (e.g. xml)

## Session layer 
- e.g. independent session management from communication

Database transactions: if completed commit else roll back
Similarly the session layer has the intention of allowing small roll backs instead of discarding the communication

## Transport
- TCP UDP QUICK
- use Port numbers to identify between processes

## Network (routing)
- Traffick flow from source router through intermediate routers until source is reached, then it starts travelling up the stack

## Data Link
 - Manages Physical (fibre/copper)

## Physical
- Physical connection between nodes