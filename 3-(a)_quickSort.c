# include <stdio.h>

int partition(int arr[], int left, int right)
{
    int low = left;
    int high = right - 1;
    int pivot = right; 

    do {
        while (low <= right && arr[low] > arr[pivot])
        {
            low++; 
        }
        while (high >= left && arr[high] < arr[pivot]) 
        {
            high--; 
        }
        if (low < high) {
            int tmp = arr[low];
            arr[low] = arr[high];
            arr[high] = tmp;
        }
    } while (low < high);

    int tmp2 = arr[low];
    arr[low] = arr[pivot];
    arr[pivot] = tmp2;


    return low;

}

void quickSort(int arr[], int left, int right) {

    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}
void main() {

    int arr[8] = { 12,70,30,20,55,25,40,50 };

    quickSort(arr, 0, 7);


    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

