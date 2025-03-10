# Focused on c++11 and beyond topics
https://www.learncpp.com -> CH22 start

# c++11
## Smart Pointers And Move Semantics
- https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/

### Pointers
**Ordinary Pointer**
    Resource* ptr = new Resource();
    //do stuff with ptr
    delete ptr;
    - can be a pain to manage

Automatic destruction can be achieved by managing the pointers life cycle with a class and overloading * and &
- Issues arise when assignment and function passes (when not passed in by ref, then get's deleted when it goes out of scope and when main ends) occurs as default is shallow
- Can be addressed by defining copy and assignment constructor to do nothing
- This creates a return problem though:
    Resource* r{ new Resource() }; //same as: Resource* r = new Resrouce()
    return Auto_ptr1(r); 
        -get's destroyed when out of scope
        -returning by reference is not possible
        -could return r but then we'll have t- manage it's life cycle
        -only option is to return Auto_ptr1 by value leads to shallow copies, duplicated pointers and crashes
- WE could also overload the copy and assignment for deep copies but this can be expensive both time and reousrse


### Move Semantics
- Getting the class to transfer ownership rather than making a copy
- Shift responsiblity from destination to the source

COPE REPRESENTS THE IDEA BUT HAS FAULTS
```
// A copy constructor that implements move semantics
	Auto_ptr2(Auto_ptr2& a) // note: not const
	{
		// We don't need to delete m_ptr here.  This constructor is only called when we're creating a new object, and m_ptr can't be set prior to this.
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}

	// An assignment operator that implements move semantics
	Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
```
res2 = res1;
Note that our overloaded operator= gave ownership of m_ptr from res1 to res2! Consequently, we don’t end up with duplicate copies of the pointer, and everything gets tidily cleaned up. 

SIDE NOTE: Deleting nullptr is okay, it does nothing

The above snippet has problems:
- passing by value causes resource to be moed into function scope and be destroyed once out of scope
accessing it then from the caller would cause a crash
- You can pass in a dynamic array but it won't be properly deallocated causing a leak
- Doesn't play well with stl since stl assumes copy not move
- causes other weird and hard to debug behaviour

In C++11, std::auto_ptr has been replaced by a bunch of other types of “move-aware” smart pointers: 
- std::unique_ptr
- std::weak_ptr
- std::shared_ptr




## Brace Initialization
    class Example {
    int a{};      // Initializes to 0
    double b{};   // Initializes to 0.0
    int* p{};     // Initializes to nullptr
};

class BadExample {
    int* p;  // Uninitialized! Could point to random memory.
};

BadExample obj;
std::cout << *(obj.p);  // Undefined behavior!

class GoodExample {
    int* p{};  // Initializes to nullptr safely
};

GoodExample obj;
if (obj.p == nullptr) {
    std::cout << "Pointer is safely initialized to nullptr!\n";
}

---
Resource* r{ new Resource() };
The {} is brace initialization, also known as uniform initialization (introduced in C++11). It is equivalent to:
Resource* r = new Resource();

For raw pointers (T*), {} and = behave the same way, so there’s no major difference in this case. However, brace initialization is generally safer and preferred because:

    It prevents narrowing conversions for integral and floating-point types.
    It ensures consistent syntax across different initialization cases.
    It can help avoid ambiguities with constructors that take a single argument.

```
#include <iostream>

class MyClass {
public:
    int x;
    double y;
};

int main() {
    MyClass obj{}; // Default-initialized with {}
    std::cout << obj.x << " " << obj.y; // ⚠️ Uninitialized (garbage values)
}
```

```
class MyClass {
public:
    int x;
    double y;
    
    // Constructor with parameters
    MyClass(int a, double b) : x(a), y(b) {}  
};

int main() {
    MyClass obj{42, 3.14};  // Calls MyClass(int, double)
    std::cout << obj.x << " " << obj.y;  // Output: 42 3.14
}
```

```
#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    Point p{10, 20};  // ✅ Aggregate initialization
    std::cout << p.x << " " << p.y;  // Output: 10 20
}
```

## Other notes

### R value reference

### Value Categories
- 5 = x is undefined from the compilers pov due to the value category

value category: property of an expression that 