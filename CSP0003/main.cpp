#include <stdio.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void upArray(int a[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
            swap(a[min_idx], a[i]);
    }
}

void adda(int a[], int n, int addnum) {
    a[n] = addnum;
}

int main() {
    int n;
    int a[n];
    int addnum;
    printf("Please enter size of array:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("\nThe array after sorting: ");
    upArray(a, n);
    xuat(a, n);

    printf("\nPlease enter new value: ");
    scanf("%d", &addnum);
    adda(a, n, addnum);
    printf("New array: ");
    n++;
    upArray(a, n);
    xuat(a, n);
}