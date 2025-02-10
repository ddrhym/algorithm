#include <iostream>
#include <stdexcept>

template <typename E>
class MyLinkedList {
    private:
        class Node {
            E val;
            Node *prev;
            Node *next;
            Node (E value): val(value), next(nullptr), prev(nullptr) {}
        };

        // 虚拟头尾节点
        Node *head;
        Node *tail;
        int size;

    public:
        MyLinkedList() {
            head = new Node(E());
            tail = new Node(E());
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        // 添加到最后
        void addLast(E e) {
            Node *newNode = new Node(e);
            Node *temp = this->tail->prev;
            temp->next = newNode;
            newNode->prev = temp;
            
            newNode->next = tail;
            tail->prev = newNode;

            this->size += 1;
        }

        void addFirst(E e) {
            Node *newNode = new Node(e);
            Node *temp = head->next;
            newNode->next = temp;
            temp->prev = newNode;

            head->next = newNode;
            newNode->prev = head;

            this->size += 1;
        }

        void add(int index, E element) {
            checkPositionIndex(index);
            if (index == size) {
                addLast(e);
            } else if (index == 0) {
                addFirst(element);
            } else {
                Node *p = getNode(index);
                Node *temp = p->prev;
                Node *newNode = new Node(element);
                
                temp->next = newNode;
                newNode->prev = temp;

                newNode->next = p;
                p->prev = newNode;
                this->size += 1;
            }
            
        }

        E removeFirst() {
            if (size < 1) {
                throw std::out_of_range("no elements to remove");
            }
            Node *x = head->next;
            Node *next = x->next;

            head->next = next;
            next->prev = head;

            x->next = NULL;
            x->prev = NULL;

            E ele = x->val;
            delete x;
            this->size -= 1;

            return ele;
        }

        E removeLast() {
            if (size < 1) {
                return std::out_of_range("no elements to remove");
            }
            Node *x = tail->prev;
            Node *prev = x->prev;
            prev->next = tail;
            tail->prev = prev;

            x->prev = NULL;
            x->next = NULL;

            E val = x->val;
            delete x;
            return val;
        }

        E remove(int index) {
            checkElementIndex(index);

            Node *x = getNode(index);
            Node *prev = x->prev;
            Node *next = x->next;

            prev->next = next;
            next->prev = prev;

            x->next = NULL;
            x->prev = NULL;

            E val = x->val;
            delete x;

            return val;
        }

        E get(int index) {
            checkElementIndex(index);
            Node *p = getNode(index);
            return p->val;
        }

        E getFirst() {
            if (size < 1) {
                throw std::out_of_range("No elements in the list");
            }
            return head->next->val;
        }

        E getLast() {
            if (size < 1) {
                throw std::out_of_range("No elements in the list");
            }
            return tail->prev->val;
        }

        E set(int index, E val) {
            checkElementIndex(index);
            Node *p = getNode(index);

            E oldVal = p->val;
            p->val = val;
            return oldVal;
        }

        int getSize() const {
            return this->size;
        }

        bool isEmpty() const {
            return size == 0;
        }

        void display() {
            std::cout << "size = " << size << std::endl;
            for (Node *p = head->next; p != tail; p = p->next) {
                std::cout << p->val << " <-> ";
            }

            std::cout << "null" << std::endl;
            std::cout << std::ednl;
        }

        ~MyLinkedList() {
            while (size > 0) {
                removeFirst();
            }

            delete head;
            delete tail;
        }

    private:
        Node *getNode(int index) {
            checkElementIndex(index);
            Node *p = this->head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            return p;
        }

        bool isElementIndex(int index) const {
            return index >= 0 && index < size;
        }

        bool isPositionIndex(int index) const {
            return index >= 0 && index <= size;
        }

        void checkElementIndex(int index) const {
            if (!isElementIndex(index)) {
                throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
            }
        }

        void checkPositionIndex(int index) const {
            if (!isPositionIndex(index)) {
                throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
            }
        }
};