//#include <stdio.h>
//union Data {
//    int i;
//    double d;
//    char c;
//};
//struct Student {
//    char name[50];
//    int age;
//    float grade;
//};
//
//
/////Anonymous strcures and unions
//
//struct A {
//    int i;
//    struct {
//        int ii;
//        char cc;
//    };
//};
//struct {
//            int ii;
//            char cc;
//        } anon;
////Anonymous Union in Local Scope
////Anonymous Union within a Structure
//struct Data1 {
//    int id;
//
//    // Anonymous union inside structure
//    union {
//        int i;
//        float f;
//    };
//};
//int main() {
//
//    // Create a union variable
//    union Data data;
//    // Store an integer in the union
//    data.i = 100;
//    printf("%d\t \n", data.i);
//        // Store a double in the union (this will
//          // overwrite the integer value)
//        data.d = 99.99;
//    printf("%.2f\t \n", data.d);
//        // Store a character in the union (this will
//          // overwrite the double value)
//        data.c = 'A';
//        printf("%c \t \n", data.c);
//        printf("Size: %d", (int)sizeof(data));
//
//    //can access the strcure elements all at a time 
//    // Create a structure variable
//        struct Student s1 = { "Geek", 20, 85.5 };
//
//        // Access structure members
//        printf("%s\n", s1.name);
//        printf("%d\n", s1.age);
//        printf("%.2f\n", s1.grade);
//        printf("Size: %d bytes", sizeof(s1));
//
//        //Anonymous Unions
//        // Define and name the anonymous union
//        struct A a;
//        a.i = 1;
//        a.ii = 20;
//        a.cc = 'C';
//
//        printf("%d %d %c", a.i, a.ii, a.cc);
//        /*Anonymous Structure Outside Nesting*/
//        /*struct {
//            int ii;
//            char cc;
//        } anon;*/
//
//        // Define and name the anonymous union
//        anon.ii = 20;
//        anon.cc = 'C';
//
//        printf("%d %c", anon.ii, anon.cc);
//
//        // Define an anonymous union
//        union {
//            int age;
//            float height;
//        } person;
//
//        // Assigning values to the members
//        person.age = 25;
//        printf("%d\n", person.age);
//
//        person.height = 5.5;
//        printf("%.2f", person.height);
//        /*Anonymous Union within a Structure*/
//        //struct Data {
//        //    int id;
//
//        //    // Anonymous union inside structure
//        //    union {
//        //        int i;
//        //        float f;
//        //    };
//        //};
//        struct Data1 data1;
//
//        data1.id = 1;
//        data1.i = 100;
//
//        printf("%d\n", data1.id);
//        printf("%d\n", data1.i);
//
//        data1.f = 5.5;
//        printf("%.1f", data1.f);
//
//    return 0;
//}
//
