#include <iostream>
#include <unordered_map>
#include <vector>


template <typename K, typename V>
class Node {
    public:
        K key;
        V value;
        Node *next;
        Node *prev;
        Node(K key, V value): key(key), value(value), next(nullptr), prev(nullptr) {}
};


template <typename K, typename V>
class MyLinkedHashMap {
    public:
        MyLinkedHashMap() {
            head = new Node<K, V>(K(), V());
            tail = new Node<K, V>(K(), V());
            head->next = tail;
            tail->prev = head;
        }

        V get(K key) {
            if (map.find(key) == map.end()) {
                return V();
            }
            return map[key]->val;
        }

        void put(K key, V val) {
            if (map.find(key) == map.end()) {
                Node<K, V> *node = new Node<K, V>(key, val);
                addLastNode(node);
                map[key] = node;
                return;
            }

            map[key]->val = val;
        }

        void remove(K key) {
            if (map.find(key) == map.end()) {
                return;
            }
            Node <K, V> *node = map[key];
            map.erase(key);
            removeNode(node);
        }

        bool containsKey(K key) {
            return map.find(key) != map.end();
        }

        std::vector<K> keys() {
            std::vector<K> keyList;
            for (Node<K, V> *p = head->next; p != tail; p = p->next) {
                keyList.push_back(p->key);
            }
            return keyList;
        }

    private:
        Node<K, V> *head;
        Node<K, V> *tail;
        std::unordered_map<K, Node<K, V>*> map;

        void addLastNode(Node<K, V> *node) {
            Node<K, V> *prev = tail->prev;
            node->prev = prev;
            node->next = tail;

            prev->next = node;
            tail->prev = node;
        }

        void removeNode(Node<K, V> *node) {
            Node<K, V> *prev = node->prev;
            Node<K, V> *next = node->next;
            prev->next = next;
            next->prev = prev;
            node->next = nullptr;
            node->prev = nullptr;
        }
};