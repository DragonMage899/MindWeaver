### Shared Memory
![[Pasted image 20250907101330.png]]


### Shift to Multi Core Architecture. 
increasing clock speeds -> over heating
instead focus on multi core architecture.
Thus we need to exploit parallelism to improve performance.
This is a challenge because modern systems are inherently asynchronous.
i.e.) thread can be delayed unpredictably by events like cache misses, interrupts and preemption 


### Multiprocessor Programming 
**Principles:** Computability
**Practise:** Performance 

### Model Summary
- Multiple Threads (processes)
- Single Shared Memory
- Objects Live in Memory
- Unpredictable asynchronous delays

### Fundamental problems

#### Basic problems
- Threads can't see what other threads are doing
	- Need explicit communication for co ordination
- Message passing also doesn't work
	- Recipient might not be listening or even there at all
	- Communication must be persistent and non transient 
- Interrupts are also non ideal
	- Senders sets a bit in receivers memory space to say "I want access"
	- Receiver resets the bit when it's ready for sender to proceed
		- But just one bit is not possible,
		- Is this bit old or new
		- Thus we need a bit for each request
		- ...
		- But then we need an unlimited amount of bits to handle all potential requests
- Flag Principe
	- Possible starvation
	- Possible dead lock (both raised)


#### Mutual Exclusion
- Only one thread can access a shared resource at a time.
	- Properties of a correct mutual exclusion program:
		- Mutual exclusion in critical section
		- Dead Lock Free
		- Starvation Free

#### Producer Consumer Problem
- Co ordination of threads that produce and consume data
	- Consumers should not access data before data is produced.
	- Producers should not overwrite data before data is consumed.

#### Readers-Writers Problem
- Multiple threads share resources.
- Only one thread to write at a time.
	- Some solutions can be designed to not require waiting.
		- Typically use locks to enforce mutual exclusion
		- This results in waiting
		- But instead of designing a system where threads block each other
			- A reader simply takes a snapshot of memory
			- Writers can still update memory concurrently without being blocked
	- Allows us to capture a view of several memory locations without preventing other threads from modifying them


### Harsh Realities of Parallelisation
Performance gains are limited by sequential portion
**Amdahl's Law**
- Even if a large portion of a program is parallelised, the un-parallelised sequential part will eventually dominate and limit the overall speedup

![[Pasted image 20250907113346.png]]
![[Pasted image 20250907113354.png]]

