# include <stdio.h>
void insertionSort(int list[], int n) {
    for (int i = 1; i < n; i++) {
        int key = list[i];
        int j;
        for (j = i - 1; j >= 0 && list[j] < key; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
        /*printf("%d step!\n", i);
        for (int k = 0; k < 8; k++) {
            printf("%d ", list[k]);
        }
        printf("\n\n");*/
    }
}
void main() {
    int list[8] = { 12,70,30,20,55,25,40,50 };
    insertionSort(list, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}