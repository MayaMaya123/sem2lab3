//
// Created by Майя Флейшер on 07.06.2021.
//
#include <stdlib.h>
#ifndef SEM2LAB3_BINARYTREE_H
#define SEM2LAB3_BINARYTREE_H
#include "IndexOutOfRange.h"
template <class T, class K>
class BinaryTree {
private:

    struct Node {
        T key;
        K value;
        Node *left_child = nullptr;
        Node *right_child = nullptr;
        int height = 1;

        int get_delta() {
            int h1;
            int h2;
            if (left_child == nullptr) {
                h1 = 0;
            } else h1 = left_child->heigh;
            if (right_child == nullptr) {
                h2 = 0;
            } else h2 = right_child;
            return h2 - h1;

        }

        void update_height() { // пересчитываем высоту
            int h1;
            int h2;
            if (left_child == nullptr) {
                h1 = 0;
            } else h1 = left_child->height;
            if (right_child == nullptr) {
                h2 = 0;
            } else h2 = right_child->height;

            if (h1 > h2) { height = h1 + 1; }//поиск наибольшего
            else height = h2 + 1;

        }

        Node *rotate_left() {
            Node *result = right_child;
            right_child = result->left_child;
            result->left_child = this;// this = node, из которого выщвана функция
            update_height();
            result->update_height();
            return result;
        }


        Node *rotate_right() {
            Node *result = left_child;
            left_child = result->right_child;
            result->right_child = this;
            update_height();
            result->update_height();
            return result;
        }

        Node *balance() {
            update_height();
            int delta = get_delta();
            if (delta < -1) {
                if (left_child != nullptr && left_child->get_delta() > 0) {
                    left_child = left_child->rotate_left;
                }
                return rotate_right();
            }
            if (delta > 1) {
                if (right_child != nullptr && right_child->get_delta() < 0) {
                    right_child = right_child->rotate_right();
                }
                return rotate_left();
            }
            return this;

        }

    };

    Node *root{};


public:

    BinaryTree() {
        root = nullptr;
    }

    void AddNode(T key, K value) {
        Node *parent = root;
        Node *ptr = root;
        auto newnode = new Node;
        newnode->key = key;
        newnode->value = value;
        newnode->left_child = nullptr;
        newnode->right_child = nullptr;

        if (ptr == nullptr)
            root = newnode;
        else {
            while (ptr != nullptr) {
                if (key < ptr->key) {
                    parent = ptr;
                    ptr = ptr->left_child;
                } else if (key > ptr->key) {
                    parent = ptr;
                    ptr = ptr->right_child;
                }
                else throw IndexOutOfRange();
            }
            if (key < parent->key) {
                parent->left_child = newnode;
            }
            if (key > parent->key) {
                parent->right_child = newnode;
            }
        }
    }

//поиск элемента по ключу
    T SearchNode(T key) {
        Node *temp_ptr;
        Node *search_ptr;
        temp_ptr = root;
        T result;
        while (temp_ptr != nullptr && search_ptr == nullptr) {
            if (key < temp_ptr->key) {
                temp_ptr = temp_ptr->left_child;
            } else if (key > temp_ptr->key) {
                temp_ptr = temp_ptr->right_child;
            } else
                { search_ptr = temp_ptr; }
        }
        if (search_ptr != nullptr) {
            result = search_ptr->value;
            return result;
        } else
            throw IndexOutOfRange();
    }

// удаление элемента по ключу Element=node
    void DeleteElement(T key) {
        Node *current_element = root;
        Node *parent = nullptr;
        if (root == nullptr) {
            return;
        }
        while (current_element && current_element->key != key) {
            parent = current_element;
            if (key < current_element->key) {
                current_element = current_element->left_child;
            } else
                current_element = current_element->right_child;
        }

        if (current_element->left_child == nullptr) {
            if (parent && parent->left_child == current_element) {
                parent->left_child = current_element->right_child;
            }
            if (parent && parent->right_child == current_element) {
                parent->right_child = current_element->right_child;
            }
            delete current_element;
            return;
        }

        if (current_element->right_child == nullptr) {
            if (parent == current_element && parent->left_child == current_element) {
                parent->left_child = current_element->right_child;
            }
            if (parent == current_element && parent->right_child == current_element) {
                parent->right_child = current_element->left_child;
            }
            delete current_element;
            return;
        }
    }

    Node *GetSubTree(K value, T key) {
        auto *node = SearchNode(value);
        auto *result = new BinaryTree<T, K>;
        result->AddNode(key, value);
        return result;
    }
    Node *FindNode(Node *node, T key){
        if (node == nullptr)
            return nullptr;
        if (key < node->key)
            return FindNode(node->left_child, key);
        if (key > node->key)
            return FindNode(node->right_child, key);
        else
            return node;
    }

    //найти значение по ключу
    T GetValueKey (T key){
        Node* node = FindNode(root, key);
        return node->value;
    }


    //map
   BinaryTree<T, K>* Map(T (function)(T)){ //возвращает результат функции function, примененной ко всем элементам

        auto *result = new BinaryTree<T, K>();
        result = ForMap(function, root, result);
        return result;
    }

    BinaryTree<T, K>* ForMap(T (function)(T), Node* pRoot, BinaryTree<T, K>* result){
        T key = key + 1;
        if (pRoot != nullptr) {
            result->AddNode(function(pRoot->value), key);
            result = ForMap(function, pRoot->left_child, result);
            result = ForMap(function, pRoot->right_child, result);
        }
        return result;
    }

    //where
    BinaryTree<T, K>*Where(bool(function)(T)){ //возращает значения, удовлетворяющие условию function
        auto* result = new BinaryTree<T, K>();
        result = ForWhere(function, root , result);
        return result;
    }


    BinaryTree<T, K>* ForWhere(bool(function)(T), Node* pRoot, BinaryTree<T, K>* result){
        T key = key + 1;
        if (pRoot != nullptr) {
            if (function(pRoot->value))
                result->AddNode(pRoot->value, key);
            result = ForWhere(function, pRoot->left_child, result);
            result = ForWhere(function, pRoot->right_child, result);
        }
        return result;
    }


};

#endif //SEM2LAB3_BINARYTREE_H
