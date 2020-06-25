#pragma once
#include <iostream>

void mergeSort(int*, int);

/*
int main()
{
    int n;
    do {
        std::cout << "Input a positive integer for array size: ";
        std::cin >> n;
    } while (n < 1);

    int* arr = new int[n];

    std::cout << "Input " << n << " elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = n - 1; i >= 0; i--) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
*/

// IMPLEMENTATION

void merge(int* arr, int start, int m, int end)
{
    if (start >= end) {
        return;
    }

    const int ls = m - start + 1; // start-ic m elementneri qanaky (m - start + 1)
    const int rs = end - m; // (m + 1)-ic end elementenri qanaky (end - (m + 1) + 1) = (end - m)
    int* larr = new int[ls];
    int* rarr = new int[rs];

    int k = start;
    for (int i = 0; i < ls; ++i) {
        larr[i] = arr[k++];
    }
    for (int i = 0; i < rs; ++i) {
        rarr[i] = arr[k++];
    }

    // 2 sortavorvac zangvacneri arr-um miadzulelu (merge) algoritmy
    k = start;
    int i = 0;
    int j = 0;
    while (i < ls && j < rs) {
        arr[k++] = larr[i] >= rarr[j] ? larr[i++] : rarr[j++];
    }

    // ete zangvacneric mekum der tarrer en mnacel, avelacnum enq arr-um.
    if (i < ls) {
        do { // do-while qani vor arden arajin stugumy arel enq.
            arr[k++] = larr[i++];
        } while (i < ls);
    }
    else { // dzax zangvacy datarkvel er
        while (j < ls) {
            arr[k++] = rarr[j++];
        }
    }

    delete[] larr;
    delete[] rarr;
}

void mergeSort(int* arr, int start, int end)
{
    if (start < end) {
        int m = (end + start) / 2; // mijin kety
        mergeSort(arr, start, m);
        mergeSort(arr, m + 1, end);
        merge(arr, start, m, end);
    }
}

void mergeSort(int* arr, int n)
{
    if (arr && n > 1) {
        mergeSort(arr, 0, n - 1);
    }
}