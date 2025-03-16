Dialect of Lisp

Char
- small size
- exclusive use of static scoping
- functions are first class entities
- typless
- simple syntax and semantics

**Scheme Interpreter**
- REPL
	- Read evaluate print loop
- interactive mode of repl
	- Reads expressions typed in by user
	- Displays resulting value
- Expressions interpreted by **EVAL** function
- Literals evaluate to themselves 
- Expressions can call functions
	- First evaluate each parameter expression is evaluated in no part order
	- Display resulting value
- ; -> comment

**Primitive Numeric Functions**
![[Pasted image 20250315110544.png]]
![[Pasted image 20250315110614.png]]
Def return
* * - 1
* + - 0

**Functions**
A scheme program is a collection of function definitions.
Functions follow a (func_name param1 param2) convention )

**lambda** 
- Nameless function
![[Pasted image 20250315111538.png]]
lambda has parameters (x) and (* x x)
- x : bound variable (will get bound to 7 in the above)

![[Pasted image 20250315111709.png]]
`(lambda bind list function) bindings`

**define**
- Bind name to a value or lambda expression
- creates named values not variables
- interpreted by eval in a different way to normal primitives
![[Pasted image 20250315114031.png]]

Binding name values
- Names can consist of letters, digits and special characters. must not begin with a digit

Binding lambda expressions
- don't need to explicitly say lambda
define list1 list2
- list1  - function prototype: func_name param1 param2 ...
- list2 - expressions to which the names are bound
![[Pasted image 20250315122818.png]]
![[Pasted image 20250315122835.png]]
![[Pasted image 20250315122844.png]]

![[Pasted image 20250315123033.png]]

 **Predicate functions**
 - returns a boolean value
 ![[Pasted image 20250315124113.png]]

boolean values:
`#t` or `#f`
- actually returns a non empty list if true
- emptylist eval to true, any other input is false


**Control flow**
- `if(pred_func then_expr else_expr)`
![[Pasted image 20250315125333.png]]
![[Pasted image 20250315161455.png]]


**List Functions**


**List functions slides**
![[Pasted image 20250315153545.png]]
![[Pasted image 20250315153836.png]]

![[Pasted image 20250315125449.png]]
![[Pasted image 20250315125456.png]]
![[Pasted image 20250315125508.png]]
![[Pasted image 20250315125514.png]]
![[Pasted image 20250315125521.png]]
![[Pasted image 20250315125530.png]]
![[Pasted image 20250315125539.png]]
![[Pasted image 20250315125547.png]]![[Pasted image 20250315125556.png]]
![[Pasted image 20250315125604.png]]
![[Pasted image 20250315125613.png]]
![[Pasted image 20250315125622.png]]
![[Pasted image 20250315125631.png]]


# code
`#lang racket`

`(define one 1)`
`; 1 innit`
`(display one)`

`(newline)`
`(* 3 7)`

`((lambda (x) (* x x)) 9)`

`(newline)`

`(define (square num) (* num num))`
`(square 5)`

## custom func`

![[Pasted image 20250315154445.png]]
`(define (member atm lis)`
`(cond`
`((null? lis) #f)`
`((eqv? atm (car lis)) #t)`
`(else (member atm (cdr lis)))`
`)`
`)`

![[Pasted image 20250315154454.png]]
`(define (equalsimp lis1 lis2)`
`(cond`
`((null? lis1) (null? lis2))`
`((null? lis2) #f)`
`((eqv? (car lis1) (car lis2))`
`(equalsimp(cdr lis1)(cdr lis2)))`
`(else #f)`
`)`
`)`

![[Pasted image 20250315154524.png]]
`(define (equal lis1 lis2)`
`(cond`
`((not (list? lis1))(eqv? lis1 lis2))`
`((not (list? lis2)) #f)`
`((null? lis1) (null? lis2))`
`((null? lis2) #f)`
`((equal (car lis1) (car lis2))`
`(equal (cdr lis1) (cdr lis2)))`
`(else #f)`
`)`
`)`


![[Pasted image 20250315154553.png]]

![[Pasted image 20250315154611.png]]
![[Pasted image 20250315154623.png]]
![[Pasted image 20250315154647.png]]
