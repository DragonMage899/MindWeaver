### Registers
- Simplest shared memory objects
- Abstraction for communication between threads
- Correctness is defined by consistency properties, each providing a different level of guarantee

#### Sage Register
- Weakest and most basic consistency model
- A read that does not overlap with a write is guaranteed to return the value of the most recent write
- If there is an overlap, any value in the allowed range can be read (even a value that was never written)

#### Regular Register
- A read that does not overlap with a write must return the value from the most recent complete write
- A read that overlaps with one or more writes must return either the value of the last completed write or the value of any overlapping writes
- No garbage values but still potentially incorrect value 

#### Atomic Registers
- Strongest register
- Linearizable
- Every operation on an atomic register appears to take effect simultaneously at a single point in time between invocation and it's response
	- Linearization point 
- All operations must appear in a single  global sequential order that respects real time order and non-overlapping operations
	- If A finishes before B starts then A appears before B in final sequential history

#### Register Construction
- Building more powerful registers from weaker ones
- **Wait-free**
	- Every method call completes in a finite number of steps, guaranteeing independent progress for each thread

#### Safe MRSW register
- Array of SRSW registers
- Single writer iterates through this array, writing new value to each reader's dedicated register one at a time
- Each reader in turn only reads from it's own location in the array

#### Regular Boolean MRSW Register
- More reliable regular register from safe register
- Use a single Safe MRSW register and a handshake protocol
- Write operation
	- Writer performs it's write then updates a handshake register to inform the readers that a new value has been written
- Read operation
	- Double reads performed
	- First reads v1, then checks handshake bit, then reads v1 again as v2
	- If the handshake bit is the same it returns v1
	- If the handshake bit changes it returns v2 (since a write happened)
- The double read ensures invalid value is not returned
- Adheres to def of regular register

#### MRSW Regular
- Generalisation of boolean version
- Use an array of SRSW registers
- The writer signals a change to a value by writing a new value to a specific register
- the readers observe and use this to read the correct value from another register
- Write
	- Write v to all registers in the array
	- Write to "turn" register (handshake)
- Read
	- reader j first reads "turn"
	- then reads array[j]
	- then reads turn
	- If turn changes, reader must reread array[j]

#### Atomic SRSW 
- Build an atomic SRSW from a regular SRSW register
- Requires the use of time stamps 
- Structure
	- Shared regular SRSW register that holds StampedValue objects
		- Value + Timestamp
- Write
	- Writer has a local timestamp
	- Increments and writes new StampedValue (new value + new timestamp) to the regular registers
- Read
	- Reader's perform a double read of StampedValue from the regular registers
	- Reads v1 then v2. If timesstamp matches the read is validelse loop till valid

#### Atomic MRSW 
Scale atomic property to multiple readers.
- Array of atomic SRSW registers
- Structure
	- 2D array a_table
		- each entry:
			- single reader, single writer register
- Write
	- Writer writes StampedValue the the diagnoal:
		- `a_table[i][i]` for all readers
		- Thus all readers have access to most recent value
- Read
	- dedicated reader j first reads own dedicated SRSW register 
		- `a_table[j][i]`
		- Ensures it see's most recent writer value
	- Then reads values from other readers registers `a_table[i][j]`
		- Finds max timestamp
		- Reader then updates it's own row to reflect current state

#### Atomic MRMW register
- Most powerfu and complex
- Structure
	- array of N MRSW registers
		- N -> amt of writers
- Write
	- writer i wants to write 
		- First reads all other writers registers to find StampedValue with highest timestamp
		- Creates a new StampedValue with timestamp = max + 1
		- Writes to it's own MRSW register a_table[i]
- Read operation
	- Read all atomic MRSW registers from all writers and return the StampedValue with the highest timestamp

