#include <stdio.h>
#include <stdio_ext.h>

void add(int a[], int* n, int socannhap) {
    a[*n] = socannhap;
    ++(*n);
}

void output(int a[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void search(int a[], int n, int socannhap) {
    int check = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == socannhap) {
            check = 1;
        }

    }
    if (check) {
        printf("Value at: ");
        for (int i = 0; i < n; i++) {
            if (a[i] == socannhap) {
                printf("%d, ", i);
            }
        }
    } else {
        printf("No value found.\n");
    }
}

void remove1(int a[], int* n, int socannhap) {
    int check = 0;
    for (int i = 0; i <*n; i++) {
        if (a[i] == socannhap) {
            check = 1;
            for (int j = i; j < *n; j++) {
                a[j] = a[j + 1];
            }
            (*n)--;
            break;
        }
    }
    if (check == 0) {
        printf("No value found.\n");
    }
}

void removeAll(int a[], int* n, int socannhap) {
    int check = 0;
    for (int i = (*n) - 1; i >= 0; i--) {
        if (a[i] == socannhap) {
            check = 1;
            for (int j = i; j < *n - 1; j++) {
                a[j] = a[j + 1];
            }
            (*n)--;
        }
    }
    if (check == 0) {
        printf("No value found.\n");
    }
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
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
    printf("Sort the array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
}

void downArray(int a[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] > a[min_idx])
                min_idx = j;
        swap(a[min_idx], a[i]);
    }
    printf("Sort the array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
}

int main() {
    int chon;
    int a[] = {5, 7, 2, -4, 7};
    int n = sizeof (a) / sizeof (int);
    int socannhap;
    do {
        printf("\n1- Add a value\n"
                "2- Search a value\n"
                "3- Remove the first existence of a value\n"
                "4- Remove all existences of a value\n"
                "5- Print out the array\n"
                "6- Sort the array in ascending order (positions of elements are preserved)\n"
                "7- Sort the array in descending order (positions of elements are preserved)\n"
                "Others- Quit\n");
        printf("Choose : ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                printf("Input: ");
                scanf("%d", &socannhap);
                add(a, &n, socannhap);
                output(a, n);
                break;
            case 2:
                printf("Input: ");
                scanf("%d", &socannhap);
                search(a, n, socannhap);
                break;
            case 3:
                printf("Input: ");
                scanf("%d", &socannhap);
                remove1(a, &n, socannhap);
                output(a, n);
                break;
            case 4:
                printf("Input: ");
                scanf("%d", &socannhap);
                removeAll(a, &n, socannhap);
                output(a, n);
                break;
            case 5:
                output(a, n);
                break;
            case 6:
                upArray(a, n);
                break;
            case 7:
                downArray(a, n);
                break;
        }
    } while (0 < chon && chon < 8);
    return 0;
}