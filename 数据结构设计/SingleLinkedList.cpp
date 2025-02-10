#include <iostream>
#include <stdexcept>

template <typename E>
class MyLinkedList {
    private:
        class Node {
            E val;
            Node *next;
            Node(E val): val(val), next(nullptr) {}
        };

        Node *head;
        Node *tail;
        int size;
    public:
        MyLinkedList() {
            head = new Node(E());
            tail = head;
            this->size = 0;
        }

        void addFirst(E e) {
            Node *newNode = new Node(e);
            newNode->next = head->next;
            head->next = newNode;
            if (size == 0) {
                tail = newNode;
            }
            this->size += 1;
        }

        void addLast(E e) {
            Node *newNode = new Node(e);
            tail->next = newNode;
            tail = newNode;
            this->size += 1;
        }

        void add(int index, E element) {
            checkPositionIndex(index);
            if (index == size) {
                addLast(element);
            } else if (index == 0) {
                addFirst(element);
            } else {
                Node *newNode = new Node(e);
                Node *prev = head;
                for (int i = 0; i < index; i++) {
                    prev = prev->next;
                }
                newNode->next = prev->next;
                prev->next = newNode;
                this->size += 1;
            }
        }

        E removeFirst() {
            if (isEmpty()) {
                throw std::out_of_range("No elements to remove");
            }
            Node *first = head->next;
            head->next = first->next;
            if (size == 1) {
                tail = head;
            }
            size -= 1;
            E val = first->val;
            delete first;
            return val;
        }
    
        E removeLast() {
            if (isEmpty()) {
                throw std::out_of_range("No elements to remove");
            }
            Node *prev = head;
            while (prev->next != tail) {
                prev = prev->next;
            }

            E val = tail->val;
            delete tail;
            prev->next = nullptr;
            tail = prev;
            this->size -= 1;
            return val;
        }

        E remove(int index) {
            checkElementIndex(index);
            Node *prev = head;
            for (int i = 0; i < index; i++) {
                prev = prev->next;
            }

            Node *nodeToRemove = prev->next;
            prev->next = nodeToRemove->next;
            if (index == this->size - 1) {
                this->tail = prev;
            }
            this->size -= 1;
            E val = nodeToRemove->val;
            delete nodeToRemove;
            return val;
        }

        int size() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

    private:
        bool isElementIndex(int index) {
            return index >= 0 && index < size;
        }

        bool is PositionIndex(int index) {
            return index >= 0 && index <= size;
        }

        void checkElementIndex(int index) {
            if (!isElementIndex(index)) {
                throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(size));
            }
        }

        void checkPositionIndex(int index) {
            if (!isPositionIndex(index)) {
                throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(size));
            }
        }

        Node* getNode(int index) {
            Node *p = head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            return p;
        }
};