#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void wr(char str[], char substr[], FILE* f2){
    int l = strlen(str);
    char n[5];
    for (int i = l - 5; i < l - 1; i++){
        n[i - l + 5] = str[i];
    }
    if (strstr(n, substr)){
        fputs(str, f2);
        fputs("\n", f2);
    }
}

void show(char s[]){
    char str[100];
    FILE *file = fopen(s, "r");
    while (fgets(str, 100, file)){
        printf("%s", str);
    }
    fclose(file);
    puts("-----------------------------------------------------");
}




int main()
{
    char f[] = "C:/Users/user/Documents/dz32/F.txt", g[] ="C:/Users/user/Documents/dz32/F1.txt";
    FILE* f1 = fopen(f, "r"), *f2 = fopen(g, "w");
    char string[200], year[5];
    fgets(year, 5, stdin);


    while (fgets(string, 200, f1) != nullptr)
        wr(string, year, f2);
    fclose(f1);
    fclose(f2);

    show(f);
    show(g);
    return 0;
}
