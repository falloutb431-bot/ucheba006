#include <stdexcept>

struct ListNode {
    int value;
    ListNode* prev;
    ListNode* next;

    ListNode(int v, ListNode* p, ListNode* n)
        : value(v), prev(p), next(n) {
    }
};

class List {
public:
    List()
        : m_head(new ListNode(0, nullptr, nullptr)),
        m_tail(new ListNode(0, m_head, nullptr)),
        m_size(0)
    {
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    ~List() {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() const {
        return m_size == 0;
    }

    unsigned long Size() const {
        return m_size;
    }

    void PushFront(int value) {
        auto newNode = new ListNode(value, m_head, m_head->next);
        m_head->next->prev = newNode;
        m_head->next = newNode;
        ++m_size;
    }

    void PushBack(int value) {
        auto newNode = new ListNode(value, m_tail->prev, m_tail);
        m_tail->prev->next = newNode;
        m_tail->prev = newNode;
        ++m_size;
    }

    int PopFront() {
        if (Empty()) {
            throw std::runtime_error("list is empty");
        }
        auto node = m_head->next;
        int ret = node->value;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --m_size;
        return ret;
    }

    int PopBack() {
        if (Empty()) {
            throw std::runtime_error("list is empty");
        }
        auto node = m_tail->prev;
        int ret = node->value;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --m_size;
        return ret;
    }

    void Clear() {
    
        auto current = m_head->next;
        while (current != m_tail) {
            auto toDelete = current;
            current = current->next;
            delete toDelete;
        }
        m_head->next = m_tail;
        m_tail->prev = m_head;
        m_size = 0;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};