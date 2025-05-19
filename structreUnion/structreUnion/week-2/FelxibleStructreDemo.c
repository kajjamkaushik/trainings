#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure with a single-element array instead of flexible array (Visual Studio workaround)
struct student {
    int stud_id;
    int name_len;
    int struct_size;
    char stud_name[1];  // Placeholder, actual size is allocated dynamically
};

// Memory allocation and initialization of structure
struct student* createStudent(int id, const char a[]) {
    int name_length = (int)strlen(a) + 1; // Ensure proper type conversion
    struct student* s = (struct student*)malloc(sizeof(struct student) + name_length - 1);  // -1 to avoid extra byte

    if (s == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    s->stud_id = id;
    s->name_len = name_length - 1;

    // Using strcpy_s for safer copying in Visual Studio
    strcpy_s(s->stud_name, name_length, a);

    // Assign structure size
    s->struct_size = sizeof(struct student) + name_length - 1;

    return s;
}

// Print student details
void printStudent(struct student* s) {
    printf("Student ID: %d\n"
        "Student Name: %s\n"
        "Name Length: %d\n"
        "Allocated Struct Size: %d bytes\n\n",
        s->stud_id, s->stud_name, s->name_len, s->struct_size);
}

enum day { sunday = 1, tuesday, wednesday, thursday, friday, saturday };

// Driver Code
int main() {
    struct student* s1 = createStudent(523, "Cherry");
    struct student* s2 = createStudent(535, "Sanjayulsha");

    printStudent(s1);
    printStudent(s2);

    // Correct type format specifier for size_t (Visual Studio may require %zu)
    printf("Size of struct student: %zu bytes\n", sizeof(struct student));
    printf("Size of struct pointer: %zu bytes\n", sizeof(s1));

    // Free allocated memory
    free(s1);
    free(s2);

    ///enum demo and usgae

    //enum day { sunday = 1, tuesday, wednesday, thursday, friday, saturday };

    enum day d = thursday;
    printf("The day number stored in d is %d", d);
    return 0;
}
