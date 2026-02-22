#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
    // здесь продолжайте программу
    puts("Enter words:");
    char n[100][100];
    int c = 0;
    do {
        cin >> n[c];
        c++;
    } while (n[c - 1][strlen(n[c - 1]) - 1] != '.');
    puts("List words:");
    for (int i = 0; i < c; ++i){
        n[i][strlen(n[i]) - 1] = '\0';
        cout << n[i] << ' ';
    }
    puts("\nFind words:");
    for (int i = 1; i < c; i += 2){
        if (strlen(n[i]) > 3) cout << n[i] << ' ';
    }
    return 0;
}
