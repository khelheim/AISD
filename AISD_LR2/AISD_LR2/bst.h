#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <stack>

using namespace std;

template<typename Key, typename T>
class BSTree {
private:
    struct Node {
        Key key;
        T data;
        Node* left;
        Node* right;

        Node(const Key& key, const T& data, Node* left = nullptr, Node* right = nullptr)
            : key(key), data(data), left(left), right(right) {}
    };

    size_t size;
    Node* root;

    //Копирование
    Node* copy(Node* other) {
        if (!other) return nullptr;
        return new Node(other->key, other->data, copy(other->left), copy(other->right));
    }

    //Очистка дерева
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    //Поиск по ключу
    Node* search(Node* node, const Key& key) {
        if (!node) {
            return nullptr;
        }
        if (key == node->key) {
            return node;
        }
        else if (key < node->key) {
            return search(node->left, key);
        }
        else {
            return search(node->right, key);
        }
    }

    //Включение по ключу
    Node* insert(Node* node, const Key& key, const T& data, bool& inserted) {
        if (!node) {
            inserted = true;
            size++;
            return new Node(key, data);
        }
        if (key == node->key) {
            inserted = false;
            return node;
        }
        if (key < node->key) {
            node->left = insert(node->left, key, data, inserted);
        }
        else {
            node->right = insert(node->right, key, data, inserted);
        }
        return node;
    }

    //Удаление по ключу
    Node* remove(Node* node, const Key& key, bool& deleted) {
        if (!node) {
            deleted = false;
            return nullptr;
        }
        if (key < node->key) {
            node->left = remove(node->left, key, deleted);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key, deleted);
        }
        else {  // key == node->key
            deleted = true;
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            node->right = Del(node->right, node);
        }
        return node;
    }

    // Функция Del
    Node* Del(Node* node, Node* nodeToReplace) {
        if (node->left) {
            node->left = Del(node->left, nodeToReplace);
            return node;
        }
        nodeToReplace->key = node->key;
        nodeToReplace->data = node->data;
        Node* temp = node->right;
        delete node;
        size--;
        return temp;
    }

    //Получение высоты дерева
    int height(Node* node) {
        if (!node) return -1;
        return 1 + max(height(node->left), height(node->right));
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    Node* next(Node* node) {
        if (node->right) return findMin(node->right);
        Node* succ = nullptr;
        Node* curr = root;
        while (curr) {
            if (node->key < curr->key) {
                succ = curr;
                curr = curr->left;
            }
            else if (node->key > curr->key) {
                curr = curr->right;
            }
            else break;
        }
        return succ;
    }

    Node* prev(Node* node) {
        if (node->left) return findMax(node->left);
        Node* pred = nullptr;
        Node* curr = root;
        while (curr) {
            if (node->key > curr->key) {
                pred = curr;
                curr = curr->right;
            }
            else if (node->key < curr->key) {
                curr = curr->left;
            }
            else break;
        }
        return pred;
    }

public:
    //Конструктор
    BSTree() : root(nullptr), size(0) {}

    //Конструктор копирования
    BSTree(const BSTree& other) : size(other.size) {
        root = copy(other.root);
    }

    //Деструктор
    ~BSTree() {
        clear(root);
    }

    //Опрос размера дерева
    size_t get_size() {
        return size;
    }

    //Очистка дерева
    void clear() {
        clear(root);
        root = nullptr;
        size = 0;
    }

    //Проверка дерева на пустоту
    bool is_empty() const {
        return root == nullptr;
    }

    //Доступ на чтение/запись
    T* search(const Key& key) {
        Node* node = search(root, key);
        if (node == nullptr) {
            return nullptr;
        }
        else {
            return &node->data;
        }
    }
    //Включение данных с заданным ключом
    void insert(const Key& key, const T& data) {
        bool inserted = false;
        root = insert(root, key, data, inserted);
        if (!inserted) {
            cout << "Key already exists." << endl;
        }
        else {
            cout << "Key inserted." << endl;
        }
    }

    //Удаление данных с заданным ключом
    void remove(const Key& key) {
        bool deleted = false;
        root = remove(root, key, deleted);
        if (!deleted) {
            cout << "Key not found." << endl;
        }
        else {
            cout << "Key deleted." << endl;
        }
        size--;
    }

    //Формирование списка ключей по 
    void display_inorder() {
        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;
            inorder(node->left);
            cout << node->key << " (" << node->data << ") ";
            inorder(node->right);
            };
        inorder(root);
        cout << endl;
    }

    //Дополнительная операция - получение высоты дерева
    int height() {
        if (!size) {
            return 0;
        }
        return height(root);
    }

    //Вывести данные по ключу
    void show_data(const Key& key) {
        Node* node = search(root, key);
        if (node != nullptr) {
            cout << node->data << endl;
        }
        else {
            cout << "Key not found." << endl;
        }
    }
    //Изменить данные по ключу
    void change(const Key& key, T data) {
        Node* node = search(root, key);
        if (node != nullptr) {
            node->data = data;
            cout << "Data changed." << endl;
        }
        else {
            cout << "Key not found." << endl;
        }
    }
    //Вывести данные по *Node
    void show_node_data(Node* node) {
        cout << node->data << endl;
    }
    //Изменить данные по *Node
    void change_node_data(Node* node, T data) {
        node->data = data;
    }
    // Исправленный класс Iterator
    class Iterator {
        BSTree<Key, T>* p;  // Используем шаблонные типы и указатель на дерево

    public:
        Node* cur;

        Iterator(BSTree<Key, T>* tree = nullptr, Node* node = nullptr) : p(tree), cur(node) {}

        T& operator*() {
            if (!cur) throw std::out_of_range("Iterator out of bounds");
            return cur->data;
        }

        Iterator& operator++() {
            cur = p->next(cur);
            return *this;  // Используем возвращение по ссылке
        }

        Iterator& operator--() {
            cur = p->prev(cur);
            return *this;  // Используем возвращение по ссылке
        }

        bool operator==(const Iterator& other) {
            return cur == other.cur;
        }
    };

    // Исправленный класс ReverseIterator
    class ReverseIterator {
        BSTree<Key, T>* p;  // Используем шаблонные типы и указатель на дерево

    public:
        Node* cur;

        ReverseIterator(BSTree<Key, T>* tree = nullptr, Node* node = nullptr) : p(tree), cur(node) {}

        T& operator*() {
            if (!cur) throw std::out_of_range("Iterator out of bounds");
            return cur->data;
        }

        ReverseIterator& operator++() {
            cur = p->prev(cur);
            return *this;
        }

        ReverseIterator& operator--() {
            cur = p->next(cur);
            return *this;
        }

        bool operator==(const ReverseIterator& other) {
            return cur == other.cur;
        }
    };

    Iterator begin() { 
        return Iterator(this, findMin(root));
    }

    Iterator end() { 
        return Iterator(this, nullptr); 
    }

    ReverseIterator rbegin() { 
        return ReverseIterator(this, findMax(root));
    }
    
    ReverseIterator rend() { 
        return ReverseIterator(this, nullptr); 
    }

    bool is_iterator_equal_to_end(Iterator it) {
        return it == end();
    }

    bool is_reverse_iterator_equal_to_rend(ReverseIterator rit) {
        return rit == rend();
    }

};
