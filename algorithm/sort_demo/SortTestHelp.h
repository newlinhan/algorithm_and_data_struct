#ifndef __SORT_Test_HELP__
#define __SORT_Test_HELP__

#include <iostream>
#include <cassert>

namespace sortTestHelp{
    int* GernerateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);

        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    int* GernerateNerlyOrderArray(int n, int swapTime)
    {
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;
        
        srand(time(NULL));
        int swapx = rand()%n;
        int swapy = rand()%n;
        std::swap(arr[swapx], arr[swapy]);
        return arr;
    }

    template<typename T>
    void PrintArray(T arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << arr[i];
            if(i != n-1)
                std::cout << " ";
        }
        std::cout << "\n";
    }

    template<typename T>
    void PrintArray(T arr[], int l, int r)
    {
        for(int i = l; i <=r; i++)
        {
            std::cout << arr[i];
            if(i != r)
                std::cout << " ";
        }
        std::cout << "\n";
    }

    template<typename T>
    bool IsSort(T arr[], int n)
    {
        for(int i = 0; i < n-1; i++)
            if(arr[i] > arr[i+1])
                return false;
        return true;
    }

    template<typename T>
    void TestSort(std::string name, void(*sort)(T*, int), T *arr, int n)
    {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(IsSort(arr, n));

        std::cout << name << " use " << double(endTime - startTime) / CLOCKS_PER_SEC << " s\n";
    }

    int* CopyIntArray(int *arr, int n)
    {
        int *copyArr= new int[n];
        std::copy(arr, arr+n, copyArr);
        return copyArr;
    }
}

#endif