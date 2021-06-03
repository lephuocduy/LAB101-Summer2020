#include <stdio.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void upArray(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

void downArray(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] > arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int n;
    int a[n];
    printf("Please enter size of array:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("\nThe array sorted in ascending:");
    upArray(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("\nThe array sorted in descending:");
    downArray(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}