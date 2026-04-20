#include<iostream>
#include<string>
using namespace std;


void begintaskblock(int tasknum){
    cout << "=========== TASK " << tasknum << " ===========" << endl;
}

void endtaskblock(){
    cout << "============================================" << endl << endl << endl << endl;
}


// ============================================================================
// COMPREHENSIVE OOP AND CLASSES LEARNING TASKS
// ============================================================================
// This file contains tasks to help you master C++ classes and OOP concepts.
// Complete each task by writing code in the designated areas.
// No solutions provided - this is YOUR learning experience!
// ============================================================================

// ============================================================================
// TASK 1: BASIC CLASS DEFINITION AND CLASS MEMBERS
// ============================================================================
// TODO: Create a class called "Person" with:
//   - Two private data members: name (string) and age (int)
//   - A public function displayInfo() that prints name and age
// Note: You'll use this class in future tasks

class Person{
    private:
        string name = "";
        int age = 0;
    public:
        Person();
        Person(string name_, int age_);
        ~Person();
        Person(const Person& other);
        virtual void displayInfo(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
        string getName() const;
        int getAge() const;
        void setName(string n);
        void setAge(int a);
        friend void comparePeople(Person p1, Person p2);
        Person& setNameAndReturnThis(string name);
};

// ============================================================================
// TASK 2: CONSTRUCTORS AND DESTRUCTORS
// ============================================================================
// TODO: Add constructors to your Person class:
//   - A default constructor that initializes name to "Unknown" and age to 0
//   - A parameterized constructor that takes (string name, int age)
//   - A destructor that prints a message when a Person object is destroyed
//     Example: "Person [name] is being destroyed"

Person::Person(){
    age = 0;
    name = "Unknown";
}

Person::Person(string name_, int age_){
    age = age_;
    name = name_;
}

Person::~Person(){
    cout << "Person " << name << " is being destroyed" << endl << endl;
}


// ============================================================================
// TASK 3: ACCESS SPECIFIERS AND ENCAPSULATION
// ============================================================================
// TODO: Modify your Person class to demonstrate encapsulation:
//   - Keep name and age as PRIVATE
//   - Create PUBLIC getter methods: getName() and getAge()
//   - Create PUBLIC setter methods: setName(string) and setAge(int)
//   - In setAge(), add validation: age should be between 0 and 150
//     If invalid, print an error message and don't change the age

string Person::getName() const{
    return name;
}

int Person::getAge() const{
    return age;
}

void Person::setAge(int a){
    if ((a >= 0) && (a <= 150)) {
        age = a;
        cout << "age set to " << a << endl;
    } else {
        cout << "error, age must be between 0 and 150" << endl;
    }
}

void Person::setName(string n){
    name = n;
}


// ============================================================================
// TASK 4: FRIEND FUNCTIONS
// ============================================================================
// TODO: Create a friend function called comparePeople() in Person class:
//   - This function should take two Person objects as parameters
//   - It should compare their ages and print who is older
//   - Example output: "Alice is older than Bob"
//   - Declare it as: friend void comparePeople(Person p1, Person p2);

void comparePeople(Person p1, Person p2){
    if (p1.age > p2.age){
        cout << p1.name << " is older than " << p2.name << endl;
    } else if (p1.age == p2.age){
        cout << p1.name << " and " << p2.name << " are the same age" << endl;
    } else {
        cout << p2.name << " is older than " << p1.name << endl;
    }
}

// ============================================================================
// TASK 5: BASIC INHERITANCE
// ============================================================================
// TODO: Create a class called "Employee" that inherits from Person:
//   - Add a new PRIVATE data member: employeeID (int)
//   - Add a PUBLIC getter: getEmployeeID()
//   - Add a PUBLIC setter: setEmployeeID(int)
//   - Create a parameterized constructor that takes (name, age, employeeID)
//   - Override displayInfo() to show name, age, AND employeeID

class Employee : public Person {
    protected:
        int employeeID;
    public:
        int getEmployeeID() {return employeeID;}
        void setEmployeeID(int newid) {employeeID = newid;}
        Employee(string n, int a, int id){
            setName(n);
            setAge(a);
            employeeID = id;
        }
        void displayInfo(){
            cout << "Name: " << getName() << endl;
            cout << "Age: " << getAge() << endl;
            cout << "ID: " << employeeID << endl;
        }
};


// ============================================================================
// TASK 6: CONSTRUCTOR CHAINING (DELEGATION)
// ============================================================================
// TODO: In your Employee constructor:
//   - Call the Person parameterized constructor using initialization list
//   - Example syntax: Employee(string n, int a, int id) : Person(n, a) { ... }
//   - Initialize employeeID properly

// commented out to avoid redeclaration issues
// Employee::Employee(string n, int a, int id) : Person(n, a) {
//     employeeID = id;
// }

// ============================================================================
// TASK 7: PROTECTED ACCESS SPECIFIER
// ============================================================================
// TODO: Create a class called "Manager" that inherits from Employee:
//   - Change appropriate members in Person/Employee to PROTECTED if needed
//     (so derived classes can access them, but outsiders cannot)
//   - Add a PRIVATE data member: department (string)
//   - Add PUBLIC getter/setter for department
//   - Create a parameterized constructor
//   - Override displayInfo() to show all information including department

class Manager : public Employee {
    private:
        string department;
    public:
        Manager(string n, int a, int id, string dep) : Employee(n, a, id) {
            department = dep;
        }
        string getDepartment() {
            return department;
        }
        void setDepartment(string dep){
            department = dep;
        }
        void displayInfo(){
            cout << "Name: " << getName() << endl;
            cout << "Age: " << getAge() << endl;
            cout << "ID: " << getEmployeeID() << endl;
            cout << "Department: " << getDepartment() << endl;
        }
};

// ============================================================================
// TASK 8: MULTIPLE INHERITANCE
// ============================================================================
// TODO: Create two separate classes:
//   a) "Trainer" class with:
//      - PRIVATE member: specialization (string)
//      - PUBLIC getter/setter for specialization
//      - A PUBLIC function teach() that prints specialization info
//
//   b) Create a new class "TrainedEmployee" that inherits from BOTH Employee AND Trainer:
//      - Use proper syntax: class TrainedEmployee : public Employee, public Trainer
//      - Create a parameterized constructor that initializes all members
//      - Add a method called performRole() that calls both displayInfo() and teach()

class Trainer{
    private:
        string specialization;
    public:
        string getSpecialization() {return specialization;}
        void setSpecialization(string s) {specialization = s;}
        void teach() {cout << specialization << endl;}
};

class TrainedEmployee: public Employee, public Trainer {
    public:
        TrainedEmployee(string n, int a, int id, string sp) : Employee(n, a, id) {
            setSpecialization(sp);
        }
        void performRole(){
            teach();
            displayInfo();
        }
};

// ============================================================================
// TASK 9: VIRTUAL FUNCTIONS AND POLYMORPHISM
// ============================================================================
// TODO: Make the following methods VIRTUAL in base classes:
//   - Make displayInfo() virtual in Person class
//   - This allows derived classes (Employee, Manager, TrainedEmployee) 
//     to override it with their own implementations
//   - Polymorphism in action: when you call displayInfo() on a Person pointer
//     pointing to an Employee, it should call Employee's version, not Person's!

// no class definitions

// ============================================================================
// TASK 10: PURE VIRTUAL FUNCTIONS (ABSTRACT CLASSES)
// ============================================================================
// TODO: Create an abstract base class called "Worker":
//   - Add a pure virtual function: work() = 0
//   - Add a pure virtual function: calculateSalary() = 0
//   - Add a concrete member function: introduce() that prints "I am a worker"
//   - Note: You cannot create objects of abstract classes directly
//   - Later, you can make Employee inherit from Worker too (multiple inheritance!)

class Worker{
    virtual void work() = 0;
    virtual void calculateSalary() = 0;
    void introduce() { cout << "I am a worker" << endl;}
};

// ============================================================================
// TASK 11: POINTERS AND REFERENCES WITH CLASSES
// ============================================================================
// TODO: Write code to demonstrate pointers and references:
//   - Create a Person object and a pointer to it: Person* pPtr = &person;
//   - Access members using pointer: pPtr->getName()
//   - Create a reference to the Person: Person& pRef = person;
//   - Access members using reference: pRef.displayInfo()
//   - Demonstrate the difference between pointers and references

// no class definitions

// ============================================================================
// TASK 12: POLYMORPHIC BEHAVIOR WITH POINTERS
// ============================================================================
// TODO: Demonstrate polymorphism using pointers:
//   - Create pointers to base class (Person) pointing to derived objects (Employee, Manager)
//   - Call virtual functions through base class pointers
//   - Observe how the correct derived version is called at runtime
//   - This is dynamic polymorphism / late binding in action!


// ============================================================================
// TASK 13: CONST CORRECTNESS
// ============================================================================
// TODO: Add const versions of your methods:
//   - Modify getters to be const: int getAge() const;
//   - This ensures they don't modify the object state
//   - Try creating const objects: const Person p("Alice", 30);
//   - Try calling methods on const objects (only const methods allowed!)


// ============================================================================
// TASK 14: THIS POINTER
// ============================================================================
// TODO: In one of your classes:
//   - Use the 'this' pointer to return a reference to current object
//   - Example: Person& setName(string n) { this->name = n; return *this; }
//   - This allows method chaining: person.setName("Bob").displayInfo()

Person& Person::setNameAndReturnThis(string n){
    this->name = n;
    return *this;
}

// ============================================================================
// TASK 15: DEEP COPY AND COPY CONSTRUCTOR
// ============================================================================
// TODO: Add a copy constructor to Person class:
//   - Person(const Person& other);
//   - Copy all member variables from 'other' to the new object
//   - Print a message when copy constructor is called
//   - Test: Person p1("Alice", 30); Person p2 = p1; // Calls copy constructor

Person::Person(const Person& other){
    this->name = other.name;
    this->age = other.age;
    cout << "copied" << endl;
};

// ============================================================================
// TESTING SECTION - WRITE YOUR OWN TESTS IN MAIN()
// ============================================================================

void destructtest() {
    Person persontest("Destructaaa", -1);
}

int main(){
    // Test Task 1: Create a Person and call displayInfo()
    // TODO: Create a Person object and test it
    begintaskblock(1);
    Person person1;
    person1.displayInfo();

    endtaskblock();
    // Test Task 2: Test constructors and destructors
    // TODO: Create objects using different constructors
    // TODO: Create an object in a scope block {} to see destructor call
    begintaskblock(2);

    Person person2_1;
    person2_1.displayInfo();

    Person person2_2("bbb", 10);
    person2_2.displayInfo();

    destructtest();

    endtaskblock();
    // Test Task 3: Test encapsulation with getters/setters
    // TODO: Test valid age setting
    // TODO: Test invalid age setting (should reject or show error)
    begintaskblock(3);
    Person person3_1("name1", 10);
    person3_1.displayInfo();
    cout << person3_1.getAge() << endl;
    person3_1.setAge(10000);
    person3_1.setAge(77);
    person3_1.setName("grob");
    person3_1.displayInfo();
    
    endtaskblock();
    // Test Task 4: Test friend function
    // TODO: Create two Person objects and compare them using comparePeople()
    begintaskblock(4);
    comparePeople(person2_2, person3_1);

    endtaskblock();
    // Test Task 5: Test inheritance - Employee class
    // TODO: Create an Employee object with all parameters
    // TODO: Call displayInfo() on Employee
    begintaskblock(5);
    Employee employee5("bob", 20, 1234567);
    employee5.displayInfo();

    endtaskblock();
    // Test Task 6: Test constructor chaining
    // TODO: Verify that Person constructor was called through Employee
    begintaskblock(6);
    Employee employee6("aaaaa", 1, 123);

    endtaskblock();
    // Test Task 7: Test Manager class (multiple levels of inheritance)
    // TODO: Create a Manager object
    // TODO: Call displayInfo() to see all information
    begintaskblock(7);
    Manager manager7("name", 50, 1234, "business or something idk");
    manager7.displayInfo();

    endtaskblock();
    // Test Task 8: Test multiple inheritance with TrainedEmployee
    // TODO: Create a TrainedEmployee object
    // TODO: Call performRole() to test both functionalities
    // TODO: Be careful about accessing displayInfo() - which one gets called?
    //       (Hint: You might need to use Employee::displayInfo() or Trainer::displayInfo())
    begintaskblock(8);
    TrainedEmployee trainedemployee8("name", 30, 12345, "businebi");
    trainedemployee8.performRole();

    endtaskblock();
    // Test Task 9: Test polymorphism with virtual functions
    // TODO: Create a base class pointer: Person* ptr;
    // TODO: Make it point to different derived objects (Employee, Manager, etc.)
    // TODO: Call displayInfo() through the pointer - observe which version is called
    begintaskblock(9);
    Employee employee9("bob", 20, 1234567);
    Manager manager9("name", 50, 1234, "business or something idk");
    Person* ptr9;
    ptr9 = &employee9;
    ptr9->displayInfo();
    ptr9 = &manager9;
    ptr9->displayInfo();

    endtaskblock();
    // Test Task 10: Test abstract class (Worker)
    // TODO: Try to create a Worker object - should NOT compile!
    // TODO: Create an object of a concrete derived class instead
    begintaskblock(10);

    // Worker w; <- fails

    endtaskblock();
    // Test Task 11: Test pointers and references
    // TODO: Create a Person object
    // TODO: Create a pointer to it and use ->
    // TODO: Create a reference to it and use .
    // TODO: Modify through pointer/reference and see changes reflected
    begintaskblock(11);
    
    Person person11("name", 30);
    Person* ptr11 = &person11;
    ptr11->displayInfo();
    Person &person11ref = person11;
    person11ref.displayInfo();

    endtaskblock();
    // Test Task 12: Test polymorphic pointers with virtual functions
    // TODO: Create an array/vector of Person pointers
    // TODO: Point them to different derived objects
    // TODO: Call virtual functions in a loop - see polymorphism in action!
    begintaskblock(12);
    Person person12_1("1", 1), person12_2("2", 2), person12_3("3", 3);
    Person* people12[3];
    people12[0] = &person12_1;
    people12[1] = &person12_2;
    people12[2] = &manager9;
    for (int i = 0; i < 3; i++){
        people12[i]->displayInfo();
    }

    endtaskblock();
    // Test Task 13: Test const correctness
    // TODO: Create a const Person object
    // TODO: Try calling getters on it (should work)
    // TODO: Try calling non-const methods on it (should fail to compile)
    begintaskblock(13);

    const Person person13("nameaaa", 13);
    cout << person13.getAge() << endl;
    // person13.displayInfo(); doesnt compile

    endtaskblock();
    // Test Task 14: Test this pointer and method chaining
    // TODO: If you implemented it, test method chaining
    // TODO: Example: person.setName("NewName").displayInfo();
    begintaskblock(14);
    Person person14("g", 16);
    person14.setNameAndReturnThis("newawesomename").displayInfo();

    endtaskblock();
    // Test Task 15: Test copy constructor
    // TODO: Create a Person object p1
    // TODO: Create p2 = p1 to trigger copy constructor
    // TODO: Modify p1 and verify p2 is independent (deep copy works)
    begintaskblock(15);
    Person p15("Alice", 30);
    Person p15_1 = p15;
    p15.setName("not alice");
    p15.displayInfo();
    p15_1.displayInfo();

    endtaskblock();
    return 0;
}
