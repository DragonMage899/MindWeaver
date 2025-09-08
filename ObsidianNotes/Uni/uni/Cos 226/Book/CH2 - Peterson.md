Critical Section
- Block of code that can be executed by only one thread at a time.

Well formed thread
- Each critical section is associated with a unique Lock Object.
- The thread calls the objects lock() method before entering the critical section.
- The thread calls unlock when leaving the critical section.

![[Pasted image 20250803162109.png]]

Freedom from starvation implies Deadlock freedom.

Mutual Exclusion is a safety property.
Deadlock freedom is a liveness property.


LockOne
```java
class LockOne implements Lock {
  private boolean[] flag = new boolean[2];
  public void lock() {
    int i = ThreadID.get();     // current thread's index: 0 or 1
    int j = 1 - i;              // other thread's index
    flag[i] = true;             // show interest in entering critical section
    while (flag[j]) {}         // wait while the other thread is interested
  }
  public void unlock() {
    int i = ThreadID.get();
    flag[i] = false;            // indicate done with critical section
  }
}

```
```
Possible deadlock:
If both threads set flag[i] = true before either reads the other’s flag, then:

    flag[0] == true

    flag[1] == true

    Both threads wait forever in their while (flag[j]) {} loops.
```

LockTwo
```java
class LockTwo implements Lock {
  private int victim;
  public void lock() {
    int i = ThreadID.get();
    victim = i;                // signal willingness to give way
    while (victim == i) {}     // wait while the other thread is not willing
  }
  public void unlock() {}
}

```
```
Possible deadlock:
If one thread runs much faster and reaches the while (victim == i) before the other thread even calls lock(), then:

    That thread will spin forever, since no one is there to "take the turn."

➤ Result: Deadlock occurs if one thread is too far ahead of the other.

---
After setting victim, the thread waits as long as victim equals its own ID.
The idea is that if both threads try to lock at about the same time, one thread’s assignment will override the other’s.

If both threads run concurrently, they effectively “negotiate” who goes first. For example, if thread 0 sets victim = 0 but then thread 1 quickly sets victim = 1, thread 0 sees that victim is no longer 0 and proceeds.



The flaw in LockTwo appears when one thread runs entirely ahead of the other. Consider this scenario:

    Thread i Runs Alone:
    If one thread (say thread 0) repeatedly or continuously calls lock() without being interrupted by the other thread, then:

        It writes victim = 0.

        Since the other thread (thread 1) never gets a chance to run and change victim, the condition while (victim == 0) remains true.

        Result: Thread 0 becomes stuck in the loop waiting for victim to change—a situation that will never happen because thread 1 isn’t there to update it.

    Deadlock Scenario:
    The algorithm assumes a level of concurrency. It requires both threads to participate (i.e., to update victim) to break the waiting loop. If that doesn't happen (as when one thread is too far ahead), the waiting thread will spin indefinitely, which is effectively a deadlock.


Deadlock Scenario:
The algorithm assumes a level of concurrency. It requires both threads to participate (i.e., to update victim) to break the waiting loop. If that doesn't happen (as when one thread is too far ahead), the waiting thread will spin indefinitely, which is effectively a deadlock.



```




Peterson Lock
```java
class Peterson implements Lock {
  private boolean[] flag = new boolean[2]; // intent to enter
  private int victim;                     // whose turn to wait

  public void lock() {
    int i = ThreadID.get();    // current thread
    int j = 1 - i;             // the other thread
    flag[i] = true;            // I'm interested
    victim = i;                // I let you go first
    while (flag[j] && victim == i) {} // wait if other is interested AND it's my turn to wait
  }

  public void unlock() {
    int i = ThreadID.get();
    flag[i] = false;           // I'm no longer interested
  }
}

```

```
	Mutual Exclusion	
At most one thread in the critical section at a time. Both flag[j] and victim == i must be true to block.

	Deadlock-Free	
The threads can’t both wait forever because the victim can’t be both 0 and 1 at the same time.

	Starvation-Free
No thread is permanently denied access. If one waits long enough, the other must eventually let it through.
```


```
Flow

two threads (Thread 0 and Thread 1) try to enter the critical section, either:
    1. At the same time.
    2. At different times.

Key Concepts Recap
    flag[i] = true: 
                 thread i wants to enter the critical section.
    
    victim = i: thread i says “you go first” — it’s willing to wait if the other                 thread also wants in.
    
    while (flag[j] && victim == i) {}: 
                 wait only if the other thread wants in (flag[j]) and it’s still                  your turn to wait (victim == i).

```

```
🧭 Flow of the Algorithm
🔁 Case 1: Both threads try to enter at the same time

Thread 0:

    Sets flag[0] = true → "I’m interested."

    Sets victim = 0 → "I’ll wait if you’re also interested."

    Checks while (flag[1] && victim == 0)
    → if flag[1] is true and victim == 0, Thread 0 waits.

Thread 1 (at the same time):

    Sets flag[1] = true

    Sets victim = 1

    Checks while (flag[0] && victim == 1)
    → if flag[0] is true and victim == 1, Thread 1 waits.

⚖️ Resolution:
Because victim was written last by one thread (say Thread 1), the other thread (Thread 0) sees victim != 0, so it exits the loop and enters the critical section.

Only one thread gets through.

Then, after the first thread exits and sets its flag to false, the second thread will see flag[j] == false and also proceed.

✅ Mutual exclusion and progress are guaranteed.
🕐 Case 2: Thread 0 runs fully before Thread 1 starts

Thread 0:

    flag[0] = true

    victim = 0

    flag[1] == false (Thread 1 hasn’t done anything yet), so the condition flag[1] && victim == 0 is false → Thread 0 enters the critical section.

Thread 1 starts later:

    flag[1] = true

    victim = 1

    Sees flag[0] == true and victim == 1, so it waits.

Thread 0 eventually finishes and sets flag[0] = false, so Thread 1 sees flag[0] == false and enters.

✅ Again: only one thread at a time, and both get a chance.
🔁 What the while Loop Does

while (flag[j] && victim == i) {}

Means:

    “Wait if the other thread is also interested, and you are the one who said you'd wait.”

If:

    The other thread is not interested → you go.

    You are not the victim → you go.

    Only if both are true do you wait.

🔚 Unlocking

When a thread finishes:

    It sets flag[i] = false.

    That tells the other thread: “I’m no longer interested,” allowing it to proceed if it was waiting.
```

![[Pasted image 20250803165255.png]]

