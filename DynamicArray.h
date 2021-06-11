//
// Created by Майя Флейшер on 09.06.2021.
#include <iostream>
#include "IndexOutOfRange.h"
#ifndef SEM2LAB3_DYNAMICARRAY_H
#define SEM2LAB3_DYNAMICARRAY_H

template<class T>
class DynamicArray {
private:
    T *array;
    int length; //размер массива

public:
    DynamicArray() {
        length = 0;
        array = nullptr;
    }



    //конструктор создания динамического массива из сущетсвующего

    DynamicArray(T *arr, int size) {
        array = new T[size];
        length = size;
        for (int i = 0; i < length; i++) {
            array[i] = arr[i];
        }
    }

// копирующий конструктор
    DynamicArray(DynamicArray<T> const &dynamicArray) {
        array = new T[dynamicArray.length];
        length = dynamicArray.length;
        for (int i = 0; i < length; i++) {
            array[i] = dynamicArray.array[i];
        }
    }

    T &operator[](int i) {   //перегружаем опреатор = get and set
        return array[i];
    }

    int GetLength() {
        return length;
    }
    //удаление массива
    /*
    void Delete(){
        if (array != nullptr && length !=0)
            delete[] array;
        array = nullptr;
        length = 0;
    }*/

    void Resize(int new_length) {
        if (new_length == 0) {
            delete[] array;
            array = nullptr;
            length = 0;
            return;
        }
        if (new_length == length)
            return;
        if (new_length < length) {
            T *smaller_array = new T[new_length];
            for (int i = 0; i < new_length; i++) {
                smaller_array[i] = array[i];
            }
            delete[] array;
            length = new_length;
            array = smaller_array;
            return;
        }
        if (new_length > length) {
            T *larger_array = new T[new_length];
            for (int i = 0; i < length; i++) {
                larger_array[i] = array[i];
            }
            delete[] array;
            length = new_length;
            array = larger_array;
            return;
        }
    }

    void Append(T value) {
        this->Resize(this->length + 1);
        array[length] = value;
    }
//вставить элемент массива
    void InsertAt(T item, int index) {
        if (index < 0 || index >=length)
            throw IndexOutOfRange();
        this->Resize(length + 1);
        for (int i = length - 2; i >= index; i--)
            array[i+1] = array[i];
        array[index] = item;
    }


};


#endif //SEM2LAB3_DYNAMICARRAY_H
