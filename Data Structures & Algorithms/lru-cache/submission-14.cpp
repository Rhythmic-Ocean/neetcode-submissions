struct Node {
    int key {};
    int val {};
    Node* prev {nullptr};
    Node* next {nullptr};
    Node(int k= 0, int v= 0, Node*  n= nullptr,Node*  p= nullptr): key {k}, val{v}, prev {p}, next {n} {}
};
class LRUCache {
   unordered_map <int, Node*> m_um {};
   int size {};
   int cap {};
   Node* head = new Node();
   Node* tail = new Node(); 
public:
    LRUCache(int capacity) {
       cap = capacity;
       m_um.reserve(capacity); 
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache(){
        Node* ptr {head};
        while(ptr!= nullptr){
            Node* cur = ptr;
            ptr = ptr->next;
            delete cur;
        }
    }
    
    void pluck(Node* item){
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }

    void putToHead(Node* item){
        item->next = head->next;
        item->next->prev = item;
        item->prev = head;
        head->next = item;
    }
    
    int get(int key) {
        if(!m_um.count(key)) return -1;
        Node* item = m_um[key];
        pluck(item);
        putToHead(item);
        return item->val;
    }
    
    void put(int key, int value) {
        if(m_um.count(key)) {
            m_um[key]->val = value;
            pluck(m_um[key]);
            putToHead(m_um[key]);
            return;
        }
        Node* item = new Node(key, value);
        if(size >= cap){
            Node* to_del = tail->prev;
            pluck(to_del);
            m_um.erase(to_del->key);
            delete to_del;
            --size;
        }
        m_um[key] = item;
        putToHead(item);
        ++size;
        return;
    }
};
