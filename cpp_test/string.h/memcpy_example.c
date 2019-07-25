#include <stdio.h>
#include <string.h>
// Copy block of memory
struct
{
    char name[40];
    int age;
} person, person_copy;
struct
{
    char name[40];
    double age;
} S1;
struct
{
    int a;
    char name[40];
    double age;
} S2;

int main()
{
    printf("sizeof(S1): %d\n", sizeof(S1));
    printf("sizeof(S2): %d\n", sizeof(S2));

    char myname[] = "Pierre de Fermat";
    /* using memcpy to copy string: */
    memcpy(person.name, myname, strlen(myname) + 1);
    person.age = 46;
    printf("sizeof(person): %d\n", sizeof(person));
    /* using memcpy to copy structure: */
    memcpy(&person_copy, &person, sizeof(person));
    printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

    getchar();
    return 0;
}