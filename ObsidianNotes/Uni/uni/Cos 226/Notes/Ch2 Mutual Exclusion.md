**Critical Section**
- Block of code that must be executed by at most one thread at a time.
- To ensure mutual exclusion a thread must first acquire a lock.

#### **Algorithms**
**LockOne**: 
- Simultaneous entry into critical section
![[Pasted image 20250907123010.png]]
**LockTwo**: 
- Deadlock, threads waiting for each other
![[Pasted image 20250907123021.png]]
**Peterson**: 
- Combines LockOne and LockTwo to solve issues
**Filter**: 
- Multi level approach to Peterson. Threads pass through rooms waiting rooms. 
- Can suffer from starvation]

**Fairness**
- All threads that want to enter the critical section will get a chance to do so.

#### Lamport's Bakery Algorithm
- Solution to n-thread mutual exclusion problem
	- Sol:
		- Thread takes a number form a shared counter
		- Thread will smallest numbers enter's critical section
		- FCFS algorithm 
- Algo
	- Two arrays: bool choosing and int number
	- choosing: Is thread in process of picking a number 
	- number: Ticket number for each thread
- Flow
	- When a thread wants to enter the critical section:
		- set it's choosing[i] flag to true
		- computes a ticket number (max(numbers) + 1)
		- set's choosing[i] to false
	- Entering Critical Section (check every other thread j)
		- wait if thread j is currently picking a number (choosing[j]  is true)
		- wait is thread j has a smaller ticket number or same number and thread has higher id
		- else enter
	- Exiting
		- reset number[i] to 0
- Details
	- Fairness
		- Starvation free since FCFS
	- Tie Breaking
		- same numbers still have a deterministic order (id)
	- Correctness
		- writes to numbers and choosing are atomic
	- Scalability
		- N threads

