#ifndef __LI_SORT_H__
#define __LI_SORT_H__

#include <iostream>
#include "SortTestHelp.h"
#include "MaxHeap.h"

template<typename T>
void SelectionSort(T *arr, int n)
{
    for(int i = 0; i < n -1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[min])
                std::swap(arr[i], arr[j]);
    }
}

template<typename T>
void InsertSort(T *arr, int n)
{
    for(int i = 1; i < n; i++)
        for(int j = i; j > 0 && arr[j-1] > arr[j] ;j--)
            std::swap(arr[j-1], arr[j]);
}

template<typename T>
void InsertSort_O1(T *arr, int n)
{
     for(int i = 1; i < n; i++){
        T temp = arr[i];
        int j = i;
        for(; j > 0 && arr[j-1] > temp;j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
     }
}

template<typename T>
void InsertSort(T *arr, int l, int r)
{
    for(int i = l; i <= r; i++)
    {
        int j = i;
        T e = arr[j];
        for(;j > l && arr[j -1] > e; j--)
        {
            arr[j] = arr[j-1]; 
        }
        arr[j] = e;
    }
}

template<typename T>
void BubbleSort(T *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i -1; j++)
            if(arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
}
template<typename T>
void BubbleSort_O1(T *arr, int n)
{
    int k = n -1;
    int flag = 0; 
    int pos = 0;
    for(int i = 0; i < n -1; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                flag = 1;
                pos = j;
            }
        }
            if(flag == 0)
                return;
            k = pos;
    }
}

template<typename T>
void HillSort(T* arr, int n)
{
    int h = 1;
    while (h < n/3)
        h = 3*h + 1;
    while (h >= 1)
    {
        for(int i = h; i < n ; i++)
            for(int j = i; j >= h && arr[j-h] > arr[j]; j-=h)
                std::swap(arr[j-h],arr[j]);
        h = h/3;
    }
    

}
template<typename T>
void HillSort_O1(T* arr, int n)
{
    int h = 1;
    while (h < n/3)
        h = 3*h + 1;
    while (h >= 1)
    {
        for(int i = h; i < n ; i++){
            T temp = arr[i];
            int j = i;
            for(; j >= h && arr[j-h] > temp; j-=h){
                arr[j] = arr[j-h];
            }
            arr[j] = temp;
        }
        h = h/3;
    }
    

}

//对[l,r]进行归并操作
template<typename T>
void __Merge(T* arr, int l, int mid, int r)
{
    int aux[r-l+1];
    int j = l;
    int k = mid + 1;
    for(int i = l; i <= r; i++)
    {
        if(j > mid)
        {
            aux[i - l] = arr[k];
            k++;
        }
        else if(k > r)
        {
            aux[i - l] = arr[j];
            j++;
        }
        else if(arr[j] < arr[k])
        {
            aux[i - l] = arr[j];
            j++;
        }
        else
        {
            aux[i - l] = arr[k];
            k++;
        }
    }
    for(int i = l; i <= r; i++)
        arr[i] = aux[i - l];
}

//对[l,r]进归并排序
template<typename T>
void __MergeSort(T* arr, int l, int r)
{
    if(r - l <= 15){
        InsertSort(arr, l, r);
        return;
    }
    int mid = (r - l)/2 + l;
    __MergeSort(arr, l, mid);
    __MergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        __Merge(arr, l, mid, r);
}

template<typename T>
void MergeSort(T* arr, int n)
{
    __MergeSort(arr, 0, n -1);
}


template<typename T>
void MergeSortBU(T *arr, int n)
{
    for(int sz = 1; sz <=n; sz+=sz)//子数组数目
        for(int i = 0; i < n - sz; i+=sz+sz)//子数组下标
            __Merge(arr, i, i+sz-1, std::min(i+sz+sz-1,n-1 ));
}
//对[l,r]进行partition操作
//__Parttition函数返回下标p使得arr[l,p-1]<arr[p],arr[p+1,r]>arr[p];
template<typename T>
int __Partition(T *arr, int l, int r)
{
    T v = arr[l];
    //arr[l+1..j] < v
    //arr[j+1...i-1] >v
   int j = l;
   for(int i = l + 1; i <=r; i++)
   {
       if(arr[i] < v)
       {
           std::swap(arr[j+1], arr[i]);
           j++;
       }
   }
   std::swap(arr[l], arr[j]);
   return j;
}

template<typename T>
void __QuickSort(T *arr, int l, int r)
{
    if(l >= r)
        return;

    int p = __Partition(arr, l, r);
    __QuickSort(arr, l, p-1);
    __QuickSort(arr, p+1, r);
}

template<typename T>
void QuickSort(T* arr, int n)
{
    __QuickSort(arr, 0, n-1);
}

template<typename T>
int __Partition2(T* arr, int l, int r)
{
    //生成[l,r]的随机数
    int t = rand()%(r - l + 1) + l;
    std::swap(arr[t], arr[l]);

    T v = arr[l];
    //arr[l+1, i) < v
    //arr(j, r] > v
    int i = l + 1;
    int j = r;
    while (true)
    {
        while (i <= r && arr[i] < v) i++;
        while(j >= l && arr[j] > v)  j--;
        if(i >= j) break;
        std::swap(arr[i],arr[j]);
        i++;
        j--;    
    }
    std::swap(arr[l],arr[j]);
    return j;
}

template<typename T>
void __QuickSort2(T* arr, int l, int r)
{
    if(r - l <= 15)
    {
        InsertSort(arr, l, r);
        return;
    }

    int p = __Partition2(arr, l, r);
    __QuickSort2(arr, l, p-1);
    __QuickSort2(arr, p+1, r);
}

template<typename T>
void QuickSort2(T* arr, int n)
{
    srand(time(NULL));
    __QuickSort2(arr, 0, n-1);
}

template<typename T>
void __Quick3WaySort(T *arr, int l, int r)
{
    if(r - l <= 15)
    {
        InsertSort(arr, l, r);
        return;
    }

    std::swap(arr[l], arr[rand()%(r -l +1) + l]);

    T v = arr[l];
    int i = l + 1;
    int gt = r + 1;
    int lt = l;

    while (i < gt)
    {
        if(arr[i] < v)
        {
            std::swap(arr[lt+1], arr[i]);
            i++;
            lt++;
        }
        else if(arr[i] > v)
        {
            std::swap(arr[i], arr[gt-1]);
            gt--;
        }
        else{
            i++;
        }
            
    }
    std::swap(arr[l], arr[lt]);

    __Quick3WaySort(arr, l, lt-1);
    __Quick3WaySort(arr, gt, r);
    
}

template<typename T>
void Quick3WaySort(T *arr, int n)
{
    srand(time(NULL));
    __Quick3WaySort(arr, 0, n-1);
}


template<typename T>
void HeapSort1(T *arr, int n)
{
    MaxHeap<T> heap(n);
    for(int i = 0; i < n; i++)
        heap.insert(arr[i]);
    for(int i = n-1; i >= 0; i--)
        arr[i] = heap.exatrctMax();
}

template<typename T>
void HeapSort2(T *arr, int n)
{
    MaxHeap<T> heap(arr, n);
    for(int i = n-1; i >= 0; i--)
        arr[i] = heap.exatrctMax();
}

template<typename T>
void __ShiftDown(T* arr, int k, int count)
{
    //当左孩子存在
    while (2*k +1 <= count)
    {
        int j = 2*k+1;
        //当右孩子存在且大于左孩子时
        if(j+1 <= count && arr[j+1]>arr[j])
            j = j+1;
        if(arr[j] < arr[k])
            break;
        
        std::swap(arr[j], arr[k]);
        k = j;
    }
    
}

template<typename T>
void HeapSort3(T *arr, int n)
{
    //堆化
    for(int i = (n -2)/2; i >= 0; i --)
        __ShiftDown(arr, i, n-1);


    //将堆转化为有序数组
    for(int i = 0; i < n - 1; i++)
    {
        std::swap(arr[0], arr[n-1-i]);
        __ShiftDown(arr, 0, n-2-i);
    }
}
#endif