#include <iostream>
#include "test.h"
#include "BinaryTree.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    testTreeInsert(8);
    testTreeDelete(10);
    testTreeSearchNode();
    testBinaryTreeWhere();
    testBinaryTreeMap();
    testQueueAddElement(10);
    testQueueDelete(10);
    testQueueSearch(10);
    testQueueMap(10);
    testHeapTreeElementsAdd(10);
    testBinaryHeapDelete(10);
    testBinaryHeapMap(10);
    return 0;
}
