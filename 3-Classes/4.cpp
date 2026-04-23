#include<iostream>
#include<string>
using namespace std;

// ============================================================================
// COMPREHENSIVE C++ TEMPLATES LEARNING TASKS
// ============================================================================
// This file covers both function templates and class templates.
// Master the concepts of generic programming with templates!
// ============================================================================

// ============================================================================
// TASK 1: BASIC FUNCTION TEMPLATES
// ============================================================================
// TODO: Create a function template called "add" that:
//   - Takes two parameters of the SAME generic type T
//   - Returns their sum
//   - Can work with int, float, double, etc.

template <typename T>
T add_1(T a, T b){
    return a + b;
}

// ============================================================================
// TASK 2: FUNCTION TEMPLATE WITH MULTIPLE TYPE PARAMETERS
// ============================================================================
// TODO: Create a function template called "compare" that:
//   - Takes two parameters of potentially different types
//   - Returns true if first is greater than second
//   - Works with different types: compare(5, 3.2), compare("a", "b"), etc.

template<typename T, typename U>
bool compare(T a, U b){
    return a > b;
}


// ============================================================================
// TASK 3: FUNCTION TEMPLATE SPECIALIZATION
// ============================================================================
// TODO: Create a specialized version of a function template:
//   - First, create a general template: template<typename T> void print(T value)
//   - Then specialize it for strings: template<> void print<string>(string value)
//   - The string version should print with quotes around it
//   - This demonstrates template specialization
template<typename T>
void print(T value){
    cout << value << endl;
}

template<>
void print<string>(string value){
    cout << "\"" << value << "\"" << endl;
}

// ============================================================================
// TASK 4: BASIC CLASS TEMPLATE
// ============================================================================
// TODO: Create a class template called "Box" that:
//   - Has a private member of generic type T
//   - Has a constructor that takes a value of type T
//   - Has a getter method: T getValue()
//   - Has a setter method: setValue(T value)

template<typename T>
class Box{
    private:
        T member;
    public:
        Box(T mem){
            member = mem;
        }
        T getValue(){
            return member;
        }
        void setValue(T value){
            member = value;
        }
};


// ============================================================================
// TASK 5: CLASS TEMPLATE WITH MULTIPLE TYPE PARAMETERS
// ============================================================================
// TODO: Create a class template called "Pair" that:
//   - Has TWO private members of different generic types (T and U)
//   - Has a constructor taking both values: Pair(T first, U second)
//   - Has getters: T getFirst() and U getSecond()
//   - Has setters: setFirst(T) and setSecond(U)
//   - Demonstrates template<typename T, typename U> class Pair

template<typename T, typename U>
class Pair{
    private:
        T elem1;
        U elem2;
    public:
        Pair(T first, U second){
            elem1 = first;
            elem2 = second;
        }
        T getFirst(){ return elem1; }
        U getSecond(){ return elem2; }
        void setFirst(T first){ elem1 = first;}
        void setSecond(U second){ elem2 = second;}
};


// ============================================================================
// TASK 6: CLASS TEMPLATE WITH MEMBER FUNCTION DEFINITIONS
// ============================================================================
// TODO: For your Box class template:
//   - Define constructor OUTSIDE the class: template<typename T> Box<T>::Box(T val) { ... }
//   - Define getValue() OUTSIDE: template<typename T> T Box<T>::getValue() { ... }
//   - Define setValue() OUTSIDE: template<typename T> void Box<T>::setValue(T val) { ... }
//   - Shows how to separate declaration from definition in templates

template<typename T>
class Box6{
    private:
        T item;
    public:
        Box6(T val);
        T getValue();
        void setValue(T val);
};


template<typename T>
Box6<T>::Box6(T val){ item = val;}

template<typename T>
T Box6<T>::getValue(){ return item;}

template<typename T>
void Box6<T>::setValue(T val){item = val;}



// ============================================================================
// TASK 7: CLASS TEMPLATE SPECIALIZATION
// ============================================================================
// TODO: Create a specialized version of your Box class for strings:
//   - template<> class Box<string> { ... }
//   - This specialized version should store the string in UPPERCASE
//   - Override the setter to convert input to uppercase
//   - This demonstrates full template specialization

template<>
class Box6<string>{
    private:
        string item;
    public:
        Box6(string val){
            for (char &x: val){
                x = toupper(x);
            }
            item = val;
        }
        void setValue(string val){
            for (char& x: val){
                x = toupper(x);
            }
            item = val;
        }
        string getValue(){
            return item;
        }
};


// ============================================================================
// TASK 8: NON-TYPE TEMPLATE PARAMETERS
// ============================================================================
// TODO: Create a class template called "Array" that:
//   - Takes TWO template parameters: typename T and int SIZE
//   - Has a fixed-size array member: T arr[SIZE];
//   - Has a method to set element: setElement(int index, T value)
//   - Has a method to get element: T getElement(int index) const

template<typename T, int SIZE>
class Array{
    private:
        T arr[SIZE];
    public:
        void setElement(int index, T value){
            arr[index] = value;
        }
        T getElement(int index){
            return arr[index];
        }
};

// ============================================================================
// TASK 9: TEMPLATE PARAMETER DEFAULTS
// ============================================================================
// TODO: Create a class template called "Container" that:
//   - Takes two template parameters: typename T and typename U
//   - Give U a default type: template<typename T, typename U = int>
//   - This means if you use Container<double>, U defaults to int
//   - Has members of both types

template<typename T, typename U = int>
class Container{
    private:
        T item1;
        U item2;
    public:
        Container(T first, U second){
            item1 = first;
            item2 = second;
        }
        T getItem1(){ return item1; }
        U getItem2(){ return item2; }
        void setItem1(T first){ item1 = first;}
        void setItem2(U second){ item2 = second;}
};

// ============================================================================
// TASK 10: FUNCTION TEMPLATE WITH CLASS TEMPLATE
// ============================================================================
// TODO: Create a function template called "printBox" that:
//   - Takes a Box<T> object as parameter (where Box is from Task 4)
//   - Prints its contents
//   - Works with ANY type T: printBox(Box<int>), printBox(Box<string>), etc.

template<typename T>
void printBox(Box<T> box){
    cout << box.getValue() << endl;
}


// ============================================================================
// TASK 11: TEMPLATE FUNCTION OVERLOADING
// ============================================================================
// TODO: Create multiple versions of a template function "process":
//   - template<typename T> void process(T value) - generic version
//   - template<> void process<int>(int value) - specialized for int
//   - template<> void process<double>(double value) - specialized for double
//   - Each should print different behavior

template<typename T>
void process(T value){
    cout << "unknown type" << endl;
}

template<>
void process<int>(int value){
    cout << "int" << endl;
}

template<>
void process<double>(double value){
    cout << "double" << endl;
}


// ============================================================================
// TASK 12: UNDERSTANDING TEMPLATE INSTANTIATION
// ============================================================================
// TODO: In this task, you'll understand how templates work:
//   - Create a function template that adds two numbers
//   - The compiler creates SEPARATE CODE for each type used
//   - Example: add<int>, add<double> are different functions at runtime
//   - You'll see this when you call add(5, 3) and add(5.5, 3.3)

template<typename T>
T add (T a, T b){
    cout << "Adding: " << typeid(T).name() << endl;
    return a+b;
}



// ============================================================================
// TASK 13: TEMPLATE INHERITANCE
// ============================================================================
// TODO: Create an inheritance hierarchy with templates:
//   - Create a base class template: template<typename T> class Animal { ... }
//   - Animal should have a virtual method: virtual void speak() = 0
//   - Create derived class template: template<typename T> class Dog : public Animal<T> { ... }
//   - Override speak() in Dog to print "Woof!"
//   - This shows templates can be inherited just like regular classes
template<typename T>
class Animal{
    public:
        virtual void speak() = 0;
};

template<typename T>
class Dog: public Animal<T>{
    public:
        void speak(){
            cout << "woof" << endl;
        };
};


// ============================================================================
// TASK 14: COMPARING TEMPLATE TYPES
// ============================================================================
// TODO: Create a function template called "isEqual" that:
//   - Takes two parameters of the same type T
//   - Returns true if they're equal
//   - Works with any type that supports operator==

template<typename T>
bool isEqual(T a, T b){
    return a == b;
}


// ============================================================================
// TASK 15: TEMPLATE WITH CONST AND REFERENCES
// ============================================================================
// TODO: Create a function template called "modify" that:
//   - Takes a reference parameter: template<typename T> void modify(T& value)
//   - Modifies the value (increment if number, add '!' if string, etc.)
//   - Takes a const parameter: template<typename T> void print_const(const T& value)
//   - Shows how const and references work with templates

template<typename T>
void modify(T &value){
    cout << "dunno" << endl;
}

template<>
void modify<string>(string &value){
    value += "!";
}

template<>
void modify<int>(int &value){
    value += 100;
}

template<typename T>
void print_const(const T& value){
    cout << value;
}



// ============================================================================
// TESTING SECTION - WRITE YOUR OWN TESTS IN MAIN()
// ============================================================================

int main(){
    // Test Task 1: Test basic function template
    // TODO: Call add<int>(5, 3)
    // TODO: Call add<double>(5.5, 3.2)
    // TODO: Let compiler deduce type: add(10, 20)
    cout << add_1<int>(5, 3) << endl;
    cout << add_1<double>(5.5, 3.2) << endl;
    cout << add_1(10, 20) << endl;



    // Test Task 2: Test function template with multiple types
    // TODO: Call compare(10, 5)
    // TODO: Call compare(3.5, 7.2)
    // TODO: Call compare("apple", "banana")
    cout << compare(10, 5) << endl;
    cout << compare(3.5, 7.2) << endl;
    cout << compare("apple", "banana") << endl;

    // Test Task 3: Test function template specialization
    // TODO: Call the general template print() with an int: print(42)
    // TODO: Call the specialized template print() with a string: print(string("hello"))
    // TODO: Observe the different behavior
    print(42);
    print(string("hello"));


    // Test Task 4: Test basic class template
    // TODO: Create Box<int> with value 100
    // TODO: Create Box<string> with value "hello"
    // TODO: Call getValue() on both
    // TODO: Call setValue() and verify changes

    Box<int> b4_0(100);
    Box<string> b4_1("hello");
    print(b4_0.getValue());
    print(b4_1.getValue());
    b4_0.setValue(100000);
    b4_1.setValue("AAAAA");
    print(b4_0.getValue());
    print(b4_1.getValue());


    // Test Task 5: Test class template with multiple types
    // TODO: Create Pair<int, string> with (42, "answer")
    // TODO: Create Pair<double, double> with (3.14, 2.71)
    // TODO: Call getters on both
    
    Pair<int, string> pair5(42, "answer");
    Pair<double, double> pair5_2 (3.14, 2.71);


    // Test Task 6: Test class template with external definitions
    // TODO: Verify that Box works with external member definitions
    // TODO: This should work if you defined Box members outside the class
    Box6<int> b6(123);
    print(b6.getValue());
    b6.setValue(456);
    print(b6.getValue());


    // Test Task 7: Test class template specialization
    // TODO: Create Box<string> and set it to "hello world"
    // TODO: Call getValue() - it should be uppercase "HELLO WORLD"
    // TODO: Demonstrates specialization behavior
    Box6<string> b7(string("hiasddasdsfakjdsfhadsk"));
    print(b7.getValue());
    b7.setValue(string("aaaaa"));
    print(b7.getValue());


    // Test Task 8: Test non-type template parameters
    // TODO: Create Array<int, 5> with SIZE=5
    // TODO: Set some elements: setElement(0, 10), setElement(1, 20)
    // TODO: Get elements back: getElement(0)
    // TODO: Try creating Array<int, 10> with different size
    Array<int, 5> ar8;
    ar8.setElement(0, 10);
    ar8.setElement(1, 20);
    print(ar8.getElement(0));
    print(ar8.getElement(1));

    // Test Task 9: Test template parameter defaults
    // TODO: Create Container<string> - U should default to int
    // TODO: Verify both members work (T and default U)
    Container<string> c9(string("hello"), 42);
    print(c9.getItem1());
    print(c9.getItem2());


    // Test Task 10: Test function template with class template
    // TODO: Create Box<int> b1(50)
    // TODO: Call printBox(b1) to print it
    // TODO: Create Box<double> b2(3.14)
    // TODO: Call printBox(b2)
    Box<int> b10_1(50);
    printBox(b10_1);
    Box<double> b10_2(3.14);
    printBox(b10_2);


    // Test Task 11: Test template function overloading
    // TODO: Call process(42) - should call int specialization
    // TODO: Call process(3.14) - should call double specialization
    // TODO: Call process(string("hello")) - should call generic version
    process(42);
    process(3.14);
    process(string("hello"));


    // Test Task 12: Test template instantiation
    // TODO: Call a template function with int: add(5, 3)
    // TODO: Call the same template function with double: add(5.5, 2.5)
    // TODO: Understand that TWO different functions exist at runtime
    add(5, 3);
    add(5.5, 2.5);


    // Test Task 13: Test template inheritance
    // TODO: Create Dog<int> (or use any type)
    // TODO: Create pointer to Animal<int> pointing to Dog
    // TODO: Call virtual speak() - should print "Woof!"
    Dog<int> dog;
    Animal<int>* animal = &dog;
    animal->speak();


    // Test Task 14: Test comparing template types
    // TODO: isEqual(10, 10) - should return true
    // TODO: isEqual(5, 8) - should return false
    // TODO: isEqual(string("hi"), string("hi")) - should return true
    cout << isEqual(10, 10) << endl;
    cout << isEqual(5, 8) << endl;
    cout << isEqual(string("hi"), string("hi")) << endl;


    // Test Task 15: Test template with const and references
    // TODO: Create int x = 5
    // TODO: Call modify(x) and check that x changed
    // TODO: Call print_const(x) - should work with const reference
    int x = 5;
    modify(x);
    cout << x << endl;
    const int t15 = 292199;
    print_const(t15);
    return 0;
}
