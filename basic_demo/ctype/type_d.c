/*
isalnum  Check if character is alphanumeric (function )
isalpha  Check if character is alphabetic (function )
isblank  Check if character is blank (function )
iscntrl  Check if character is a control character (function )
isdigit  Check if character is decimal digit (function )
isgraph  Check if character has graphical representation (function )
islower  Check if character is lowercase letter (function )
isprint  Check if character is printable (function )
ispunct  Check if character is a punctuation character (function )
isspace  Check if character is a white-space (function )
isupper  Check if character is uppercase letter (function )
isxdigit  Check if character is hexadecimal digit (function )
Character conversion functions
tolower
Convert uppercase letter to lowercase (function )
toupper
Convert lowercase letter to uppercase (function )
*/
/* tolower example */
#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    char str[] = "Test String.\n";
    char c;
    while (str[i])
    {
        c = str[i];
        putchar(tolower(c));
        putchar(toupper(c));
        i++;
    }
    getchar();
    return 0;
}