#include <stdio.h>

void heapify(int arr[], int here, int n) {
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max = here;
    if (left < n && arr[left]<arr[max])
        max = left;
    if (right < n && arr[right]<arr[max])
        max = right;

    if (max != here) {
        int tmp = arr[here];
        arr[here] = arr[max];
        arr[max] = tmp;
        heapify(arr, max, n);
    }
}

void buildHeap(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
        /*for (int j = 0; j <n; j++)
            printf("%d ", arr[j]);
        printf("\n\n");*/
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int treeSize = n - 1; treeSize >= 0; treeSize--) {
        int tmp = arr[0];
        arr[0] = arr[treeSize];
        arr[treeSize] = tmp;
        heapify(arr, 0, treeSize);

        /*printf("%d step!\n", 8 - treeSize);
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n\n");*/
    }
}

int main() {
    int arr[8] = { 12,70,30,20,55,25,40,50 };
 
    heapSort(arr, 8);

    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    printf("\n");
}