//
// Created by Майя Флейшер on 09.06.2021.
//
#include "DynamicArray.h"

#ifndef SEM2LAB3_BINARYHEAP_H
#define SEM2LAB3_BINARYHEAP_H

template<class T>
class BinaryHeap {
private:
    DynamicArray<T> dynamicArray{};
    int heap_size{};
public:
    //упорядочивание двоичной кучи
    void heapify(int i) {
        int left_child;
        int right_child;
        int largest_child;

        while (true) {
            left_child = 2 * i + 1;
            right_child = 2 * i + 1;
            largest_child = i;

            if (left_child < heap_size && dynamicArray[left_child] > dynamicArray[right_child])
                largest_child = left_child;

            if (right_child < heap_size && dynamicArray[right_child] > dynamicArray[largest_child])
                largest_child = right_child;

            if (largest_child == i)
                break;

            int temp = dynamicArray[i];
            dynamicArray[i] = dynamicArray[largest_child];
            dynamicArray[largest_child] = temp;
            i = largest_child;
        }
    }


// конструктор (из статического массива делаем кучу)
    BinaryHeap(T *array, int size) {
        dynamicArray = DynamicArray<T>(array, size);
        heap_size = size;
        for (int i = heap_size / 2; i >= 0; i--)
            heapify(i);
    }

// динамический массив превращаем в кучу
    explicit BinaryHeap(const DynamicArray<T> &dynamicArray1) {
        dynamicArray = DynamicArray<T>(dynamicArray1);
        heap_size = dynamicArray.GetLength();
        for (int i = heap_size / 2; i >= 0;i--)
        heapify(i);
    }

// копирующий конструктор
    BinaryHeap(const BinaryHeap<T> &binaryHeap) {
        dynamicArray = DynamicArray<T>(binaryHeap.dynamicArray);
        heap_size = dynamicArray.GetLength();
    }

    void AddElement(T value) {
        dynamicArray.Append(value);
        int i = heap_size - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && dynamicArray[parent] < dynamicArray[i]) {
            int temp = dynamicArray[i];
            dynamicArray[i] = dynamicArray[parent];
            dynamicArray[parent] = temp;
            i = parent;
            parent = (i - 1) / 2;
        }
        heap_size++;
        for (int j = heap_size / 2; j >= 0; j--)
            heapify(j);
    }

    //возвращает индекс элемент
    int FindElement(T value) {
        for (int i = 0; i < heap_size; i++) {
            if (dynamicArray[i] == value)
                return i;
        }
        return -1;
    }



    int GetLevels() {
        int levels = 0;
        int i = heap_size;
        if (i == 0)
            return 0;
        while (i != 0) {
            levels++;
            i = (i - 1) / 2;
        }
        return levels;
    }

    void DeleteElement(int key) {
        for (int i = key; i < heap_size - 1; i++) {
            dynamicArray[i] = dynamicArray[i + 1];
        }
        heap_size--;
        for (int j = 0; j < GetLevels(); j++) {
            for (int k = 0; k < heap_size; k++)
                heapify(k);
        }

    }


BinaryHeap<T> *Map (T function(T, T), T item){
        T *arr = new T[heap_size];
        for (int i = 0; i < heap_size; i++)
            arr[i] = 0;
        DynamicArray<T> dynamicArray1 = DynamicArray<T> (arr, heap_size);
        for (int i = 0; i < heap_size;i++)
            dynamicArray1.InsertAt(dynamicArray[i], item);
        auto *binaryHeap = new BinaryHeap<T>(dynamicArray1);
    return binaryHeap;
    }
    //bool - потому что функция фильтр

    /*
BinaryHeap<T> *where (bool  function(T, T), T item) {
        DynamicArray<T> dynamicArray1 = DynamicArray<T>(dynamicArray);
        for (int i = 0; i < dynamicArray1.GetLength(); i++) {
            if (!function(dynamicArray1[i], item))
                dynamicArray1[i].Delete;
        }
        auto *binaryHeap = new BinaryHeap<T>(dynamicArray1);
        for (int i = binaryHeap->heap_size / 2; i >= 0; i--)
            binaryHeap->heapify(i);
        return binaryHeap;
    }

    DynamicArray<T> GetArray(){
        return dynamicArray;
    }

*/
    /*int getHeapSize(){
    return heap_size;
    }
*/

};


#endif //SEM2LAB3_BINARYHEAP_H
