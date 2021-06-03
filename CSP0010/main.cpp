#include <stdio.h>

void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Element[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int xoa(int a[], int &n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                for (int k = i; k < n; k++) {
                    a[k] = a[k + 1];
                }
                n--;
                i--;

            }

        }
    }
    return n;
}

int main() {
    int n;
    int a[100];
    printf("Please enter size of array:  ");
    scanf("%d", &n);
    nhap(a, n);
    printf("The original array: ");
    xuat(a, n);
    xoa(a, n);
    printf("\nThe array after removing duplicate elements: ");
    xuat(a, n);

}