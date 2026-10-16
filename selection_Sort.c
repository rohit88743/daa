#include <stdio.h>
#include <time.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start,end;
    double CPU_time_used;
    start=clock();
    selectionSort(arr, n);
    end=clock();
    CPU_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("%f seconds\n",CPU_time_used);
    printf("sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}