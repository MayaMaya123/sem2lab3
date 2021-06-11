//
// Created by Майя Флейшер on 10.06.2021.
//
#include <iostream>
#ifndef SEM2LAB3_QUEUE_H
#define SEM2LAB3_QUEUE_H
#include "BinaryTree.h"

template<class T, class K>
class Queue {
private:
    BinaryTree<T, K> *binaryTree;
public:
    //конструктор: пустая очередь
    Queue(){
        binaryTree = new BinaryTree <T, K>();
    }

    //создаем очередь из существующего дерева
    explicit Queue(const BinaryTree<T, K> &other_tree){
        binaryTree = new BinaryTree<T, K>(other_tree);
    }
    //копирующий конструктор
   Queue(const Queue<T, K> &other_tree){
        binaryTree = new BinaryTree<T, K> (*other_tree.binaryTree);
    }
    //деструктор
    ~Queue(){
        delete binaryTree;
    }
    Queue<T, K> &operator = (const Queue<T, K> &other_tree){
        delete this;
        binaryTree = new BinaryTree<T, K>(other_tree.binaryTree);
        return  *this;
    }

void AddElement(T key, K value) {
    (this->binaryTree)->AddNode(key, value);
    }
void Delete(T key) {
    (this->binaryTree)->DeleteElement(key);
    }
    //если true то элемент есть есои false то элемента нет, поэтому bool
    bool Search(T key){
        bool result = binaryTree->SearchNode(key);
        return result;
    }


    Queue<T, K> *Map(K(*function)(K)){
        BinaryTree<T, K> *ptr = binaryTree->Map(function);
        auto *res = new Queue<T, K>(*ptr);
        return res;
    }

    Queue<T, K> where (bool(*function)(T)){
        BinaryTree<T, K> *ptr = binaryTree->Where(function);
        auto * result = new Queue<T, K>(*ptr);
        return result;
    }

    // найти value по ключу
    K FindValueByKey(T key){
        K result;
        result = binaryTree->GetValueKey(key);
        return result;
    }
};
#endif //SEM2LAB3_QUEUE_H
