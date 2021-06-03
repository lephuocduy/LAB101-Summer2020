#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

void xuat(int a[], char str[]) {
    printf("Times of appearance for each character:\n");
    for (int j = 0; j < 52; j++)
        if (a[j] > 0)
            printf("\t%c: %d", str[j], a[j]);
    printf("\n-----------------------------------------------------\n");
    printf("Characters that appears the most:\n");
    int j;
    int x = a[0];
    for ( j = 0; j < 52; j++)
        if (x < a[j]) {
            x = a[j];
        }
    for (int j = 0; j < 52; j++)
    if (a[j] > x-1)
    printf("\t%c: %d", str[j], a[j]);
    printf("\nProgram continues to run if press enter, exit if press Esc.");
}

void dem(char s[]) {
    char str[52];
    strcpy(str, "abcdefghijklmpnoqrstuvxywzABCDEFGHIJKLMPNOQRSTUVXYWZ");
    int a[52] = {0};
    for (int i = 0; i < strlen(s); i++)
        for (int j = 0; j < 52; j++)
            if (s[i] == str[j]) a[j]++;
    xuat(a, str);

}

int main() {
    char s[50];
    char exit = 100;
    do {
        printf("Please enter string: ");
        fgets(s, sizeof (s), stdin);
        dem(s);
        exit = getchar();
        __fpurge(stdin);
    } while (exit != 27);
}