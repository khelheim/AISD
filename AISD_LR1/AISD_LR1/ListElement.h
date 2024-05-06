#pragma once

template<typename T>
class List {
private:
    T* elements;  // Массив элементов списка
    size_t capacity;   // Вместимость списка
    size_t initial_capacity; // Первоначальный размер вместимости
    size_t size;       // Текущее количество элементов в списке
    size_t last_operation_count;    // Отслеживание просмотренных элементов в операциях
    // Изменение вместительности массива
    void resize(size_t new_capacity);
public:
    // Конструктор
    List(size_t initial_capacity);
    // Конструктор копирования
    List(const List& other);
    // Деструктор
    ~List();
    // Опрос размера списка
    size_t get_size();
    // Опрос вместительности списка
    size_t get_capacity();
    // Очистка списка
    void clear();
    // Проверка списка на пустоту
    bool is_empty();
    // Метод для запроса числа элементов, просмотренных в последней операции
    size_t get_last_operation_count();
    // Опрос наличия заданного значения
    bool contains(const T& value);
    // Чтение значения с заданным номером в списке
    T& get(size_t index);
    // Изменение значения с заданным номером в списке
    void set(size_t index, const T& value);
    // Получение позиции в списке для заданного значения
    size_t index_of(const T& value);
    // Включение нового значения
    void push_back(const T& value);
    // Включение нового значения в позицию с заданным номером
    void insert(size_t index, const T& value);
    // Удаление заданного значения из списка
    bool remove(const T& value);
    // Удаление значения из позиции с заданным номером
    void erase(size_t index);
    // Метод для вывода на экран последовательности значений списка
    void display();

    // Прямой итератор
    class ForwardIterator {
    private:
        T* cur; // Указатель на текущий элемент списка
    public:
        ForwardIterator(T* cur = nullptr) : cur(cur) {}
        T& operator*();
        // Инкремент для перехода к следующему элементу
        ForwardIterator& operator++(); // Префиксный инкремент
        ForwardIterator operator++(int); // Постфиксный инкремент
        bool operator==(const ForwardIterator& other) const;
        bool operator!=(const ForwardIterator& other) const;
    };
    // Обратный итератор
    class ReverseIterator {
    private:
        T* cur; // Указатель на текущий элемент списка
    public:
        ReverseIterator(T* cur = nullptr) : cur(cur) {}
        T& operator*()
        // Декремент для перехода к предыдущему элементу
        ReverseIterator& operator--(); // Префиксный декремент
        ReverseIterator operator--(int); // Постфиксный декремент
        bool operator==(const ReverseIterator& other) const;
        bool operator!=(const ReverseIterator& other) const;
    };

    // Методы класса List, возвращающие итераторы
    ForwardIterator begin();
    ForwardIterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
};