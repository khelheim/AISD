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

    Node* copy(Node* other);
    void clear(Node* node);
    Node* search(Node* node, const Key& key);
    Node* insert(Node* node, const Key& key, const T& data, bool& inserted);
    Node* remove(Node* node, const Key& key, bool& deleted);
    Node* Del(Node* node, Node* nodeToReplace);
    int height(Node* node);
    Node* findMin(Node* node);
    Node* next(Node* node);
    Node* prev(Node* node);
public:
    BSTree();
    BSTree(const BSTree& other);
    ~BSTree();
    size_t get_size();
    void clear();
    bool is_empty() const;
    T* search(const Key& key);
    void insert(const Key& key, const T& data);
    void remove(const Key& key); 
    void display_inorder();
    int height();
    void show_data(const Key& key);
    void change(const Key& key, T data);
    void show_node_data(Node* node);
    void change_node_data(Node* node, T data);
    class Iterator {
        BSTree<Key, T>* p;  // »спользуем шаблонные типы и указатель на дерево
    public:
        Node* cur;
        Iterator(BSTree<Key, T>* tree = nullptr, Node* node = nullptr);
        T& operator*();
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(const Iterator& other);
    };
    class ReverseIterator {
        BSTree<Key, T>* p;  // »спользуем шаблонные типы и указатель на дерево
    public:
        Node* cur;
        ReverseIterator(BSTree<Key, T>* tree = nullptr, Node* node = nullptr);
        T& operator*();
        ReverseIterator& operator++();
        ReverseIterator& operator--();
        bool operator==(const ReverseIterator& other);
    };
    Iterator begin();
    Iterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
    bool is_iterator_equal_to_end(Iterator it);
    bool is_reverse_iterator_equal_to_rend(ReverseIterator rit);
};