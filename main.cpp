#include <bits/stdc++.h>
using namespace std;

// function to swap two elements
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// function to decide partition index
// last element is used as pivot
// place its correct position in sorted array
int partition(int array[], int init_idx, int end_idx) {
    int pivot = array[end_idx];
    int smaller_idx = init_idx - 1;

    for (int i = init_idx; i <= end_idx - 1; i++) {
        if (array[i] < pivot) {
            smaller_idx++;
            swap(&array[smaller_idx], &array[i]);
        }
    }
    swap(&array[smaller_idx + 1], &array[end_idx]);

    return (smaller_idx + 1);
}

// function to sort array by quick sort algorithm
// input1: array to be sorted
// input2: initial index
// input3: end index
void quick_sort(int array[], int init_idx, int end_idx) {
    if (init_idx < end_idx) {
        int part_idx = partition(array, init_idx, end_idx);
        quick_sort(array, init_idx, part_idx - 1);
        quick_sort(array, part_idx + 1, end_idx);
    }
}

// function to print array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int array[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Given array: ";
    print_array(array, size);

    quick_sort(array, 0, size - 1);

    cout << "\nSorted array: ";
    print_array(array, size);

    return 0;
}
