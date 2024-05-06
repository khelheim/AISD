#pragma once

template<typename T>
class List {
private:
    T* elements;  // ������ ��������� ������
    size_t capacity;   // ����������� ������
    size_t initial_capacity; // �������������� ������ �����������
    size_t size;       // ������� ���������� ��������� � ������
    size_t last_operation_count;    // ������������ ������������� ��������� � ���������
    // ��������� ��������������� �������
    void resize(size_t new_capacity);
public:
    // �����������
    List(size_t initial_capacity);
    // ����������� �����������
    List(const List& other);
    // ����������
    ~List();
    // ����� ������� ������
    size_t get_size();
    // ����� ��������������� ������
    size_t get_capacity();
    // ������� ������
    void clear();
    // �������� ������ �� �������
    bool is_empty();
    // ����� ��� ������� ����� ���������, ������������� � ��������� ��������
    size_t get_last_operation_count();
    // ����� ������� ��������� ��������
    bool contains(const T& value);
    // ������ �������� � �������� ������� � ������
    T& get(size_t index);
    // ��������� �������� � �������� ������� � ������
    void set(size_t index, const T& value);
    // ��������� ������� � ������ ��� ��������� ��������
    size_t index_of(const T& value);
    // ��������� ������ ��������
    void push_back(const T& value);
    // ��������� ������ �������� � ������� � �������� �������
    void insert(size_t index, const T& value);
    // �������� ��������� �������� �� ������
    bool remove(const T& value);
    // �������� �������� �� ������� � �������� �������
    void erase(size_t index);
    // ����� ��� ������ �� ����� ������������������ �������� ������
    void display();

    // ������ ��������
    class ForwardIterator {
    private:
        T* cur; // ��������� �� ������� ������� ������
    public:
        ForwardIterator(T* cur = nullptr) : cur(cur) {}
        T& operator*();
        // ��������� ��� �������� � ���������� ��������
        ForwardIterator& operator++(); // ���������� ���������
        ForwardIterator operator++(int); // ����������� ���������
        bool operator==(const ForwardIterator& other) const;
        bool operator!=(const ForwardIterator& other) const;
    };
    // �������� ��������
    class ReverseIterator {
    private:
        T* cur; // ��������� �� ������� ������� ������
    public:
        ReverseIterator(T* cur = nullptr) : cur(cur) {}
        T& operator*()
        // ��������� ��� �������� � ����������� ��������
        ReverseIterator& operator--(); // ���������� ���������
        ReverseIterator operator--(int); // ����������� ���������
        bool operator==(const ReverseIterator& other) const;
        bool operator!=(const ReverseIterator& other) const;
    };

    // ������ ������ List, ������������ ���������
    ForwardIterator begin();
    ForwardIterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
};