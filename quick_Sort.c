#include <stdio.h>
#include <time.h>

int partition(int arr[], int strt, int end) {
    int pivot = arr[end];
    int idx = strt - 1; 

    for (int j = strt; j < end; j++) {
        if (arr[j] < pivot) {
            idx++;
            int temp = arr[idx];
            arr[idx] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[idx + 1];
    arr[idx + 1] = arr[end];
    arr[end] = temp;
    return (idx + 1);
}

void quickSort(int arr[], int strt, int end) {
    if (strt < end) {
        int pi = partition(arr, strt, end);
        quickSort(arr, strt, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double CPU_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", CPU_time_used);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}