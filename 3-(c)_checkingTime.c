#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9000
#define SWAP(x,y,tmp) ((tmp)=(x), (x)=(y), (y)=(tmp))    

int arr[MAX_SIZE];    
int list[MAX_SIZE]; 

int n; 

clock_t start, finish, duration = 0;    

//--------------------���� ����----------------------
void selection_sort(int list[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[idx] >= arr[j])
            {
                idx = j;
            }
        }
        int temp = arr[idx];
        arr[idx] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}


//--------------------���� ����----------------------
void bubble_sort(int list[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//--------------------���� ����----------------------
void insertion_sort(int list[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = list[i];

        int j;
        for (j = i - 1; j >= 0 && list[j] < key; j--) {
            list[j + 1] = list[j];
        }

        list[j + 1] = key;
    }
}


//--------------------��������----------------------
int sort_arr[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
    int i = left, j = mid + 1, idx = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            sort_arr[idx++] = arr[j++];
        }
        else
        {
            sort_arr[idx++] = arr[i++];
        }
    }

    if (i <= mid)
    {
        for (int l = i; l <= mid; l++)
            sort_arr[idx++] = arr[l];
    }
    else
    {
        for (int l = j; l <= right; l++)
            sort_arr[idx++] = arr[l];
    }

    for (int i = left; i <= right; i++)
        arr[i] = sort_arr[i];
}
void merge_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);

    }
}

//--------------------������----------------------
int partition(int list[], int left, int right)
{
    int pivot = list[left];
    int tmp;
    int low = left;
    int high = right + 1;

    do {
        do
            low++;
        while (low <= right && list[low] < pivot);

        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) 
            SWAP(list[low], list[high], tmp);
    } while (low < high);

    SWAP(list[left], list[high], tmp);

    return high;
}
void quick_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}
//--------------------�� ����----------------------

void heapify(int arr[], int here, int n) {
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max = here;
    if (left < n && arr[left] < arr[max])
        max = left;
    if (right < n && arr[right] < arr[max])
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
    }
}

void heap_sort(int arr[], int n) {

    buildHeap(arr, n);

    for (int treeSize = n - 1; treeSize >= 0; treeSize--) {
        int tmp = arr[0];
        arr[0] = arr[treeSize];
        arr[treeSize] = tmp;
        heapify(arr, 0, treeSize);
    }
}
//�迭�� �ش��ϴ� �迭�� �����ϴ� �Լ�
void arrCopying(void)
{
    int i;
    for (i = 0; i < n; i++)
        list[i] = arr[i];
}

int main()
{

    n = MAX_SIZE;
    
    for (int i = 0; i < n; i++)
        arr[i] = rand() % MAX_SIZE;

    printf("*****���� �˰��� ���� Ƚ�� �� (n = %d)*****\n\n", n);

    //���� ����
    arrCopying();
    start = clock();
    selection_sort(list, n); //list �迭�� ��� ����
    finish = clock();

    duration = finish - start;
    printf("���� �˰��� ���� �ð� : %.3f msec\n\n", (float)duration / CLOCKS_PER_SEC);

    //���� ����
    arrCopying();
    start = clock();
    bubble_sort(list, n);
    finish = clock();

    duration = finish - start;
    printf("���� �˰��� ���� �ð� : %.3f msec\n\n", (float)duration / CLOCKS_PER_SEC);

    //���� ����
    arrCopying();
    start = clock();
    insertion_sort(list, n);
    finish = clock();
    
    duration = finish - start;
    printf("���� �˰��� ���� �ð� : %.3f msec\n\n", (float)duration / CLOCKS_PER_SEC);

    //���� ����
    arrCopying();
    start = clock();
    merge_sort(list, 0, n);
    finish = clock();
    
    duration = finish - start;
    printf("���� �˰��� ���� �ð� : %.3f msec\n\n", (float)duration / CLOCKS_PER_SEC);


    //�� ����
    arrCopying();
    start = clock();
    quick_sort(list, 0, n);
    finish = clock();
    
    duration = finish - start;
    printf("�� �˰��� ���� �ð� : %.3f msec\n\n", (float)duration / CLOCKS_PER_SEC);

    //�� ����
    arrCopying();
    start = clock();
    heap_sort(list, n);
    finish = clock();

    duration = finish - start;
    printf("�� �˰��� ���� �ð� : %.3f msec\n\n", (float)duration / CLOCKS_PER_SEC);

    return 0;
}

