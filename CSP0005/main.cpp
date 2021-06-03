#include <stdio.h>
#include <stdio_ext.h>

int main() {
    int n;
    char exit = 100;
    do {
        printf("Nhap so can in ra bang Cuu Chuong: ");
        do {
            scanf("%d", &n);
            if(n<1 || n>9){
            printf("Moi nhap lai tu 1-9: ");
        }
        } while (n < 1 || n > 9);
        for (int i = 0; i <= 10; i++) {
            printf("%d x %d = %d \n", n, i, n * i);
        }
        printf("ESC de thoat\n");
        exit = getchar();
        __fpurge(stdin);
    } while (exit != 27);
}