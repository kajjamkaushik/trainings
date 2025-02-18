//#include <iostream>
//using namespace std;
//// Defining a structure to represent a student
//struct Student {
//    char name[50];
//    int age;
//    float grade;
//};
//// Structure definition
//struct A {
//    int x;
//};
//// Function to increment values
//void increment(struct A a, struct A* b) {
//    a.x++;
//    b->x++;
//}
//
//// Defining structure
//typedef struct {
//    int a;
//} str1;
//
//// Another way of using typedef with structures
//typedef struct {
//    int x;
//} str2;
/////nested Structure Declaration 
//// Child structure declaration
//struct child {
//    int x;
//    char c;
//};
//
//// Parent structure declaration
//struct parent {
//    int a;
//    struct child b;
//};
//
//
////structure pointer
//struct Point {
//    int x, y;
//};
//
////self referential structres 
//struct node {
//    int data;
//    struct node* prev_link;
//    struct node* next_link;
//};
////to demonstrate use of Bit-fields
//// Space optimized representation of the date
//struct date {
//    // d has value between 0 and 31, so 5 bits
//    // are sufficient
//    int d : 5;
//
//    // m has value between 0 and 15, so 4 bits
//    // are sufficient
//    int m : 4;
//
//    int y;
//};
//int main() {
//    struct Student s1 = { "Rahul", 20, 18.5 };
//    // Traditional initialization of another structure
//    struct Student s2 = { "Vikas", 18, 22 };
//    // Accessing structure members
//    printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.grade);
//    printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.grade);
//    ///copy constructor 
//    // Create a copy of student s1
//    struct Student s1c = s1;
//    printf("Student 1 Name: %d\n", s1c.name);
//    printf("Student 1 Age: %d\n", s1c.age);
//    printf("Student 1 Grade: %c", s1c.grade);
//
//    ///passing Sturcture to functions 
//    struct A a = { 10 };
//    struct A b = { 10 };
//
//    // Passing a by value and b by pointer
//    increment(a, &b);
//
//    printf("a.x: %d \tb.x: %d", a.x, b.x);
//
//    // Creating structure variables using new names
//    str1 var1 = { 20 };
//    str2 var2 = { 314 };
//
//    printf("var1.a = %d\n", var1.a);
//    printf("var2.x = %d\n", var2.x);
//    ///nested Structre decalration and usage 
//
//    struct parent p = { 25, 195, 'A' };
//
//    // Accessing and printing nested members
//    printf("p.a = %d\n", p.a);
//    printf("p.b.x = %d\n", p.b.x);
//    printf("p.b.c = %c", p.b.c);
//    ///
//    /// structre Pointer
//    struct Point Z = { 1, 2 };
//
//    // ptr is a pointer to structure p
//    struct Point* ptr = &Z;
//
//    // Accessing structure members using structure pointer
//    printf("\n\nAccessing structre data members using pointers");
//    printf("%d %d", ptr->x, ptr->y);
//
//
//
//    ////self referntail strcutre mostly used for trees in DSA 
//    struct node ob1; // Node1
//
//    // Initialization
//    ob1.prev_link = NULL;
//    ob1.next_link = NULL;
//    ob1.data = 10;
//
//    struct node ob2; // Node2
//
//    // Initialization
//    ob2.prev_link = NULL;
//    ob2.next_link = NULL;
//    ob2.data = 20;
//
//    struct node ob3; // Node3
//
//    // Initialization
//    ob3.prev_link = NULL;
//    ob3.next_link = NULL;
//    ob3.data = 30;
//
//    // Forward links
//    ob1.next_link = &ob2;
//    ob2.next_link = &ob3;
//
//    // Backward links
//    ob2.prev_link = &ob1;
//    ob3.prev_link = &ob2;
//    printf("\nelf Referential strucres and accessing them");
//    // Accessing  data of ob1, ob2 and ob3 by ob1
//    printf("%d\t", ob1.data);
//    printf("%d\t", ob1.next_link->data);
//    printf("%d\n", ob1.next_link->next_link->data);
//
//    // Accessing data of ob1, ob2 and ob3 by ob2
//    printf("%d\t", ob2.prev_link->data);
//    printf("%d\t", ob2.data);
//    printf("%d\n", ob2.next_link->data);
//
//    // Accessing data of ob1, ob2 and ob3 by ob3
//    printf("%d\t", ob3.prev_link->prev_link->data);
//    printf("%d\t", ob3.prev_link->data);
//    printf("%d", ob3.data);
//
//    printf("Size of date is %lu bytes\n",
//        sizeof(struct date));
//    struct date dt = { 31, 12, 2014 };
//    printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
//    return 0;
//}
