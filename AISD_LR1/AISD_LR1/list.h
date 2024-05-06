#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class List {
private:
    T* elements;  // Массив элементов списка
    size_t capacity;   // Вместимость списка
    size_t initial_capacity; // Первоначальный размер вместимости
    size_t size;       // Текущее количество элементов в списке
    size_t last_operation_count;    // Отслеживание просмотренных элементов в операциях

    void resize(size_t new_capacity) {
        T* new_elements = new T[new_capacity];
        size_t i = 0;
        
        capacity = new_capacity;
        
        for (auto it = begin(); it != end(); it++, i++) {
            new_elements[i] = *it;
        }

        delete[] elements;
        elements = new_elements;
    }

public:
    // Конструктор
    List(size_t initial_capacity) : initial_capacity(initial_capacity), capacity(initial_capacity), size(0), last_operation_count(0) {
        try {
            elements = new T[capacity];
        }
        catch (const std::bad_alloc& e) {
            throw std::runtime_error("Не удалось выделить память для списка");
        }
        catch (const std::runtime_error& e) {
            cout << "Ошибка: " << e.what() << '\n';
        }
    }

    // Конструктор копирования
    List(const List& other) : initial_capacity(other.initial_capacity), capacity(other.capacity), size(other.size), last_operation_count(other.last_operation_count) {
        try {
            elements = new T[capacity];
            
            for (auto it = begin(), i = 0; it != end(); it++, i++) {
                *it = other.elements[i];
            }
        }
        catch (const std::bad_alloc& e) {
            throw std::runtime_error("Не удалось выделить память для списка ", e.what());
        }
    }

    // Деструктор
    ~List() {
        delete[] elements;
    }

    // Опрос размера списка
    size_t get_size() {
        return size;
    }

    size_t get_capacity() {
        return capacity;
    }

    // Очистка списка
    void clear() {
        delete[] elements;
        capacity = initial_capacity;
        elements = new T[capacity];
        size = 0;
    }

    // Проверка списка на пустоту
    bool is_empty() {
        return size == 0;
    }

    // Метод для запроса числа элементов, просмотренных в последней операции
    size_t get_last_operation_count() {
        return last_operation_count;
    }

    // Опрос наличия заданного значения
    bool contains(const T& value) {
        last_operation_count = 0;
        
        for (auto it = begin(); it != end(); it++) {
            last_operation_count++;
            if (*it == value) {
                return true;
            }
        }

        return false;
    }

    // Чтение значения с заданным номером в списке
    T& get(size_t index) {
        if (index >= size) throw out_of_range("Index out of bounds");
        return elements[index];
    }

    // Изменение значения с заданным номером в списке
    void set(size_t index, const T& value) {
        if (index >= size) throw out_of_range("Index out of bounds");
        auto it = ForwardIterator(elements + index);
        *it = value;
    }

    // Получение позиции в списке для заданного значения
    size_t index_of(const T& value) {
        size_t i = 0;

        for (auto it = begin(); it != end(); it++, i++) {
            if (*it == value) {
                return i;
            }
        }

        throw out_of_range("Not found");
    }

    // Включение нового значения
    void push_back(const T& value) {
        if (size == capacity) {
            resize(2 * capacity);
        }

        size++;
        auto it = rbegin();
        *it = value;
    }

    // Включение нового значения в позицию с заданным номером
    void insert(size_t index, const T& value) {
        if (index > size) throw out_of_range("Index out of bounds");
        if (size == capacity) resize(2 * capacity);

        ++size;

        for (auto it = rbegin(); it != ReverseIterator(elements + index); it--) {
            auto tmp_it = it;
            *it = *--tmp_it;
        }

        auto it = ForwardIterator(elements + index);
        *it = value;
        last_operation_count = size - index;
    }

    // Удаление заданного значения из списка
    bool remove(const T& value) {
        size_t index = index_of(value);
        
        if (index != -1) {
            erase(index);
            return true;
        }

        return false;
    }

    // Удаление значения из позиции с заданным номером
    void erase(size_t index) {
        if (index >= size) throw out_of_range("Index out of bounds");
        if (size <= capacity / 2 && capacity > initial_capacity) {
            resize(capacity / 2);
        }

        size--;

        for (auto it = ForwardIterator(elements + index); it != end(); it++) {
            auto tmp_it = it;
            *it = *++tmp_it;
        }

        last_operation_count = size - index;
    }

    // Метод для вывода на экран последовательности значений списка
    void display() {
        for (auto it = begin(); it != end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // Прямой итератор
    class ForwardIterator {
    private:
        T* cur; // Указатель на текущий элемент списка

    public:
        ForwardIterator(T* cur = nullptr) : cur(cur) {}

        T& operator*() {
            if (!cur) throw out_of_range("Iterator out of bounds");
            return *cur;
        }

        // Инкремент для перехода к следующему элементу
        ForwardIterator& operator++() { // Префиксный инкремент
            cur++;
            return *this;
        }

        ForwardIterator operator++(int) { // Постфиксный инкремент
            ForwardIterator tmp = *this;
            cur++;
            return tmp;
        }

        bool operator==(const ForwardIterator& other) const {
            return cur == other.cur;
        }

        bool operator!=(const ForwardIterator& other) const {
            return cur != other.cur;
        }
    };

    // Обратный итератор
    class ReverseIterator {
    private:
        T* cur; // Указатель на текущий элемент списка

    public:
        ReverseIterator(T* cur = nullptr) : cur(cur) {}

        T& operator*() {
            if (!cur) throw out_of_range("Iterator out of bounds");
            return *cur;
        }

        // Декремент для перехода к предыдущему элементу
        ReverseIterator& operator--() { // Префиксный декремент
            cur--;
            return *this;
        }

        ReverseIterator operator--(int) { // Постфиксный декремент
            ReverseIterator tmp = *this;
            cur--;
            return tmp;
        }

        bool operator==(const ReverseIterator& other) const {
            return cur == other.cur;
        }

        bool operator!=(const ReverseIterator& other) const {
            return cur != other.cur;
        }
    };

    // Методы класса List, возвращающие итераторы
    ForwardIterator begin() {
        return ForwardIterator(elements);
    }

    ForwardIterator end() {
        return ForwardIterator(elements + size);
    }

    ReverseIterator rbegin() {
        return ReverseIterator(elements + size - 1);
    }

    ReverseIterator rend() {
        return ReverseIterator(elements - 1);
    }
    
    bool is_forward_iterator_equal_to_end(ForwardIterator it) {
        return it == end();
    }

    bool is_reverse_iterator_equal_to_rend(ReverseIterator it) {
        return it == rend();
    }
};