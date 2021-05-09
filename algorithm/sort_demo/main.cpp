#include "SortTestHelp.h"
#include "sort.h"
int main()
{
    int m = 1000000;
    int *arr1 = sortTestHelp::GernerateRandomArray(m,0,m);
    int *arr2 = sortTestHelp::CopyIntArray(arr1, m);
    int *arr3 = sortTestHelp::CopyIntArray(arr1, m);
    int *arr4 = sortTestHelp::CopyIntArray(arr1, m);
    int *arr5 = sortTestHelp::CopyIntArray(arr1, m);
    int *arr6 = sortTestHelp::CopyIntArray(arr1, m);
    int *arr7 = sortTestHelp::CopyIntArray(arr1, m);
    sortTestHelp::TestSort("Quick Soet", QuickSort, arr2, m);
    sortTestHelp::TestSort("Quick Sort2", QuickSort2, arr3, m);
    sortTestHelp::TestSort("Quick 3 Way Sort", Quick3WaySort, arr4, m);
    sortTestHelp::TestSort("MaxHeap1", HeapSort1, arr5, m);
    sortTestHelp::TestSort("MaxHeap2", HeapSort2, arr6, m);
    sortTestHelp::TestSort("MaxHeap3", HeapSort3, arr7, m);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    // int n = 10;
    // int *arr = sortTestHelp::GernerateRandomArray(n,0,n);
    // sortTestHelp::PrintArray(arr,n);
    // HeapSort3(arr, n);
    // sortTestHelp::PrintArray(arr,n);
    // return 0;
}