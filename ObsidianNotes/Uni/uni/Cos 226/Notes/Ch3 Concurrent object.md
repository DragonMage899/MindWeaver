### Concurrency and Correctness
**Correctness** 
- Provides the right output for the given input.
- For concurrency correctness is a complex problem due to interleaving of operations from multiple threads.
- Liveness:  Something does eventually happen
- 

**Concurrent History**
- Sequence of method calls and return events from multiple threads on a shared object
- Challenge is to determine whether a given concurrent history is "correct"
- Use consistency models to provide ways of defining correctness for concurrent objects

### Consistency Models
- Defines what it means for a concurrent program to be correct
- Specifies how operations of threads should appear to be ordered

#### Sequential Consistency
- An execution is sequentially consistent if the result is the same as if all operations from all threads were executed by some single global sequential order.
- In this sequential sequential order, the operations of each individual thread must appear in the order specified by the thread's program code (program order)
- Hard to meet with modern hardware

#### Linearizbility
- Stronger and more practical correctness condition
- Every operation on a shared object appear to take effect instantaneously at some point between it's invocation and response.
- Instantaneous Point -> linearization point
- Linearizbility is a compositional property
	- if each object is linearizable then the system is linearizable 
	- Useful for building complex systems

#### Quiescent Consistency
- Weakest of the three
- whenever there are no pending operations (quiescent period)
	- The object behaves as if it were a sequential object
	- Doesn't guarantee a consistent view during period of active concurrency


#### Java Memory Model
- JMM set of rules that govern how threads interact in JAVA
![[Pasted image 20250907131900.png]]


Sequential vs Concurrent objects
![[Pasted image 20250907132300.png]]
![[Pasted image 20250907132328.png]]
![[Pasted image 20250907132338.png]]

![[Pasted image 20250907132427.png]]

![[Pasted image 20250907132511.png]]
![[Pasted image 20250907132529.png]]
![[Pasted image 20250907132547.png]]

![[Pasted image 20250907132943.png]]

![[Pasted image 20250907132959.png]]
![[Pasted image 20250907133013.png]]
![[Pasted image 20250907133020.png]]
![[Pasted image 20250907133037.png]]
![[Pasted image 20250907133059.png]]

![[Pasted image 20250907133123.png]]

![[Pasted image 20250907133225.png]]

![[Pasted image 20250907133243.png]]
![[Pasted image 20250907133251.png]]
![[Pasted image 20250907133301.png]]
![[Pasted image 20250907133325.png]]

![[Pasted image 20250907133336.png]]

![[Pasted image 20250907133346.png]]

![[Pasted image 20250907133355.png]]

![[Pasted image 20250907133433.png]]

![[Pasted image 20250907133501.png]]

![[Pasted image 20250907133614.png]]
![[Pasted image 20250907133626.png]]

![[Pasted image 20250907133641.png]]

![[Pasted image 20250907133657.png]]

![[Pasted image 20250907133718.png]]

![[Pasted image 20250907134238.png]]

![[Pasted image 20250907134251.png]]
![[Pasted image 20250907134300.png]]

![[Pasted image 20250907134323.png]]
![[Pasted image 20250907134330.png]]

![[Pasted image 20250907134344.png]]

![[Pasted image 20250907134406.png]]


![[Pasted image 20250907134422.png]]
![[Pasted image 20250907134434.png]]


![[Pasted image 20250907134452.png]]
![[Pasted image 20250907134501.png]]

![[Pasted image 20250907134540.png]]
![[Pasted image 20250907134546.png]]

![[Pasted image 20250907134941.png]]
![[Pasted image 20250907135024.png]]
![[Pasted image 20250907135047.png]]

![[Pasted image 20250907135100.png]]
![[Pasted image 20250907135109.png]]
![[Pasted image 20250907135258.png]]

![[Pasted image 20250907135305.png]]
![[Pasted image 20250907135314.png]]
![[Pasted image 20250907135408.png]]
![[Pasted image 20250907135422.png]]
![[Pasted image 20250907135430.png]]

![[Pasted image 20250907135451.png]]
![[Pasted image 20250907135504.png]]

![[Pasted image 20250907135527.png]]
