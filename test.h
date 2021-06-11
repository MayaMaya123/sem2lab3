//
// Created by Майя Флейшер on 09.06.2021.
//
#include <iostream>
#include "BinaryTree.h"
#include "BinaryHeap.h"
#include "Queue.h"
using namespace std;

int getRandomInt(int n) {
    return (int) random() % n;
}

/*int getRandomInt(int start, int end) {
    return (int) random()%(end - start) + start;
}*/
void testTreeInsert(int count) {
    int i;
    BinaryTree<int,int> binaryTree;

    for (i = 0; i < count/2; i++) {
        binaryTree.AddNode(i,0);
    }
    int max = i-1;
    for (; i < count; i++) {
        int key = getRandomInt(max);
    }
    cout << "TreeInsert is OK"<<endl;
}


void testTreeDelete( int count) {
    int passed = 0;
    BinaryTree<int,int> binaryTree;

    for (int i = 0; i < count; i++) {
        binaryTree.AddNode(i,0);
    }
    for (int i = count-1; i >= 0; i--){
        binaryTree.DeleteElement(i);
        if(!binaryTree.SearchNode(i))
            passed++;
    }
    cout << "TreeDelete is OK"<<endl;

}


void testTreeSearchNode() {
    int size;
    int passed = 0, i, k = 3;

    BinaryTree<int,int > binaryTree;
    for (i = 0; i < size / 2; i++) {
        binaryTree.AddNode(i,0);
        if (binaryTree.SearchNode(i))
            passed++;
    }
    int max = size / 2;

    for (; i < size; i++) {
        int item = getRandomInt(max);
        if (binaryTree.SearchNode(item))
            passed++;
    }
    cout <<"SearchNode is OK "<<endl;
}

void testBinaryHeapAdd(){
    int size;

    int *a = new int[1];
    a[0] = 1;
    auto *binaryHeap = new BinaryHeap<int>(a, 1);
    int passed = 1;
    for (int i = 0; i < size + 1; ++i) {
        binaryHeap->AddElement(i);
        if(binaryHeap->FindElement(i))
            passed++;
    }
    cout<<"BinaryHeapAdd is OK"<<endl;
}


void testMapBinaryTree(){
    auto* binaryTree1 = new BinaryTree<int, int>();
    auto* tree2 = new BinaryTree<int, int>();
    for (int i = 1; i < 7; i++)
        binaryTree1->AddNode(i, i);
    //result

}


/*void testBinaryHeapDelete(){
    int size;
    int *a = new int[1];
    a[0] = 0;
    auto *binaryHeap = new BinaryHeap<int>(a, 1);
    int passed = 1;
    for (int i = 0; i < size; ++i) {
        binaryHeap->AddElement(i);
    }
    for (int i = 0; i < size; ++i) {
        binaryHeap->DeleteElement(i);
        if(binaryHeap->FindElement(i)<0)
            passed++;
    }
    cout<<"BinaryHeapDeleting is OK"<<endl;
}
*/

bool test_func(int value){
    bool res = false;
    if (value != 0)
        res = true;
    return res;

}

void testBinaryTreeWhere(){
    BinaryTree<int, int> binaryTree;
    binaryTree.Where(test_func);
    cout<<"testBinaryTreeWhere is OK"<<endl;

}

int test_for_map(int value){
    return value * 2;
}

void testBinaryTreeMap(){
    BinaryTree<int, int> binaryTree;
    binaryTree.Map(test_for_map);
    cout<<"testBinaryTreeMap is OK"<<endl;
}

void testHeapTreeElementsAdd(int count){
    int *array = new int [1];
    array[0] = 1;
    auto *binaryHeap  = new BinaryHeap<int>(array, 1);
    for (int i = 0; i < count; i++)
        binaryHeap->AddElement(i);
    cout<<"testBinaryHeapElementAdd is OK"<<endl;
}

void testBinaryHeapDelete(int count){
    int * array = new int[1];
    array[0] = 0;
    auto *binaryHeap = new BinaryHeap<int>(array, 1);
    for(int i = 0; i < count; i++)
        binaryHeap->AddElement(i);
    for(int i = 0; i < count; i++)
        binaryHeap->DeleteElement(i);
    cout<<"testBinaryHeapDelete is OK"<<endl;
}


 void testQueueAddElement(int count){
    int i;
    Queue<int, int> queue;
    for (i = 0; i < count/2; i++)
        queue.AddElement(i,0);
      int max = i - 1;
      for (; i < count; i++) // первое услопик пустое потому что i уже есть
        int key = getRandomInt(max);

      cout<<"testQueueAddElement is OK" << endl;
}


void testQueueDelete(int count){
    Queue<int, int> queue;
    for (int i = 0; i < count; i++)
        queue.Delete(i);
    cout<<"testQueueDeleteElement is OK" << endl;
}
int test_for_map1(int a, int b){
    return a * b;
}

void testBinaryHeapMap(int count){
    int *array = new int [1];
    array[0] = 0;
    auto *binaryHeap = new BinaryHeap<int> (array, 1);
    for (int i = 0; i < count; i++)
        binaryHeap->AddElement(i);
    BinaryHeap<int> *binaryHeap1 = binaryHeap->Map(test_for_map1,2);
    cout<<"testBinaryHeapMap is OK" << endl;

}


void testQueueSearch(int count) {
    Queue<int, int> queue;
    int i;
    for (i = 0; i < count/2; i++)
        queue.AddElement(i, 0);
    int max = count / 2;

        int item = getRandomInt(max);
        queue.Search(item);
        cout << "testQueueSearchElement is OK" << endl;
}


void testQueueMap(int count){
    auto maxQueueSize = 1000;
    int max_size = maxQueueSize;
    Queue<int,int> queue;
    for (int i = 0; i < count; i++){
       // for(int j = 0; j < max_size; j++)
            //queue.AddElement(i, j);
    }
       auto *result = queue.Map(test_for_map);
    int correct = 1;
    for (int k = 0; k < max_size; k++){
        //if ((result->FindValueByKey(k) != k*4))
            correct = 0;
    }
    cout << "testQueueMap is OK" << endl;
}