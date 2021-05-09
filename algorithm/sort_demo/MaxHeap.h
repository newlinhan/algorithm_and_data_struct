#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__
#include <iostream>
#include <cassert>

template<typename Item>
class MaxHeap
{
private:
    Item *items;
    int _count;
    int _capacitiy;

    void siftUp(int k)
    {
        while(k > 1 && items[k/2] < items[k])
        {
            std::swap(items[k/2], items[k]);
            k = k/2;
        }
    }

    void siftDown(int k)
    {
        while(2*k <= _count)
        {
            int j = 2*k;
            if(j + 1 <= _count && items[j+1] > items[j])
                j = j + 1;
            if(items[k] > items[j])
                break;
            std::swap(items[k], items[j]);
            k = j; 
        }
    }

    void heapy()
    {
        for (int i = _count/2; i >=1; i--)
        {
            siftDown(i);
        }
        
    }

public:
    MaxHeap(int capacitiy)
    {
        _count = 0;
        _capacitiy = capacitiy;
        items = new Item[capacitiy + 1];
    }

    MaxHeap(Item *arr, int n)
    {
        items = new Item[n+1];
        for(int i = 0; i < n; i++)
            items[i + 1] = arr[i];
        _capacitiy = n;
        _count = n;
        heapy();
    }

    ~MaxHeap()
    {
        _count = 0;
        _capacitiy = 0;
        delete [] items;
    }

    int count() const {return _count;}
    
    int capacitiy() const {return _capacitiy;}

    void insert(Item t)
    {
        assert(_capacitiy >= _count);
        _count++;
        items[_count] = t;
        siftUp(_count);
    }

    Item exatrctMax()
    {
        assert(_count > 0);
        Item max = items[1];
        items[1] = items[_count];
        _count--;
        siftDown(1);
        return max;
    }
};

#endif