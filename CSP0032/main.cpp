#include<stdio.h>
#include<stdio_ext.h>

int main() {
    int n;
    int Divide;
    int s = 0;
    char exit = 100;
    do {
        printf("\nSum Digit Program");
        printf("\nEnter an integer n=");
        scanf("%d", &n);
        if(n<0){
            n = n*(-1);
        }
        while (n != 0){
            Divide = n % 10;
            s += Divide;
            n /= 10;
        }
        printf("\nSum digit = %d", s);
        s=0;
        printf("\nESC to exit");
        exit = getchar();
    } while (exit != 27);
}