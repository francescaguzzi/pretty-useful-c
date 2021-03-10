#pragma once

void scanArray(int* arr, int size);
void printArray(int* arr, int size);
void swap(int* a, int* b);
void bubbleSort(int arr[], int dim);
void selectionSort(int arr[], int dim);
void merge(int* arr, int left, int center, int right);
void mergeSort(int* v, int left, int right);
void quickSort(int arr[], int first, int last);
void insertionSort(int arr[], int n);
void flip(int arr[], int i);
int findMax(int arr[], int n);
void pancakeSort(int* arr, int n);

/* TEST

int main() {

    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    "insert your sort here"(arr, n);
    printArray(arr, n);
    return 0;
}

*/