## Limitations of RDMS
- **Poor representation of real world entities**
	- Normalization often leads to relations that to not correspond to their real world counter parts
	- Fragmentation of the real world
	- Information obtained with joins which is expensive to perform
	- Normalisation fragments real world relations into various tables, thus requiring joins to get the information back
- **Semantic Overloading**
	- Table is used to represent entities and relationships between them
	- Difficult to differentiate between relationships just by looking at schema
- **Impedance Mismatch**
	- Issues that arise when working with relational database from an oo pov
	- Paradigm clash
		- OOP -> objects with complex states and behaviours
		- RDMS -> flat, tabular rows
	- Extra work
		- Translate data back and forth between application objects and database rows
- **Limited Operations**
	- Fixed set of sql operations
	- Schema can't be changed easily
	- Can't make new/custom operations


## Core OODBMS Concepts
Implement db functionality from a oo pov

**Object Identity (OID)**
- Every object in the database has a unique OID
- immutable
- unlike a primary key which can be changed

**Encapsulation**
- Bundle object state + operations into a single object
- e.g.) student having a calculateGPA() function 

**Inheritance**
- subclass that inherits attributes and operations  
- Code re use init 

**Persistence**
- Objects stored permanently in db
- exists after the program terminates unlike transient objects
- serialisation

# JPA

