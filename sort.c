#include <stdio.h>
#include "sort.h"
#define MAX 100

void scanArray(int* arr, int size) {

    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int* arr, int size) {

    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int dim) {

    int i, j;
    for (i = 0; i < dim - 1; i++)

        for (j = 0; j < dim - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selectionSort(int arr[], int dim) {

    int i, j, min_idx;

    min_idx = 0;

    for (i = 0; i < dim - 1; i++) {
   
        for (j = i + 1; j < dim; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void merge(int* arr, int left, int center, int right) {

    // right = dim - 1 (not dim!!!)
    int temp_arr[MAX] = { 0 };
    int i = left;
    int j = center + 1;
    int k = 0;


    while (i <= center && j <= right) {
        if (arr[i] <= arr[j]) {
            temp_arr[k] = arr[i];
            i++;
        }
        else {
            temp_arr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= center) {
        temp_arr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp_arr[k] = arr[j];
        j++;
        k++;
    }

    for (k = left; k <= right; k++) {
        arr[k] = temp_arr[k - left];
    }
}

void mergeSort(int* arr, int left, int right) {

    int center;
    if (left < right) {
        center = (left + right) / 2;
        mergeSort(arr, left, center);
        mergeSort(arr, center + 1, right);
        merge(arr, left, center, right);
    }
}

void quickSort(int arr[], int first, int last) {

    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr, first, j - 1);
        quickSort(arr, j + 1, last);
    }
}

void insertionSort(int arr[], int n) {

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void flip(int arr[], int i) {

    int temp, start = 0;
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n) {

    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

void pancakeSort(int* arr, int n) {

    for (int curr_size = n; curr_size > 1; --curr_size) {

        int mi = findMax(arr, curr_size);
        if (mi != curr_size - 1) {

            flip(arr, mi);
            flip(arr, curr_size - 1);
        }
    }
}



