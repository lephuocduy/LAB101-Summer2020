#include <stdio.h>
#include <stdio_ext.h>
const int MAX = 10;

void Input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\tElement %d=", i);
        scanf("%d", &a[i]);
    }
}

int SumEven(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum += a[i];
        }
    }
    return sum;
}

int SumOdd(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    int n;
    int a[MAX];
    do {
        printf("\nSum Even Old program");
        do{
        printf("\nEnter a number of element n= ");
        scanf("%d", &n);
        __fpurge(stdin);
        }while(n<0 || n>MAX );
        printf("\nInput elements:");
        printf("\n");
        Input(a, n);
        printf("\nSum of Even= %d", SumEven(a, n));
        printf("\nSum of Odd= %d", SumOdd(a, n));
        printf("\nEnter 0 to exit");
        __fpurge(stdin);
    } while (n != 0);
}

