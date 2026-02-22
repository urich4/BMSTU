#include <stdio.h>
int main()
{
    FILE *f1;
    char string[80];
    f1 = fopen("test.txt", "r");
    while (fgets(string, 80, f1) != nullptr)
        puts(string);
    return 0;
}
