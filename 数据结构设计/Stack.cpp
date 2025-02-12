#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>


template <typename E>
class MyLinkedListStack {
    private:
        std::list<E> list;
    public:
        void push(const E& val) {
            list.push_back(val);
        }

        E pop() {
            E value = list.back();
            list.pop_back();
            return value;
        }

        E peek() const {
            return list.back();
        }

        int size() const {
            return list.size();
        }
};



template <typename T>
class MyDynamicArrayStack {
    private:
        std::vector<T> list; 
    public:
        void push(const T& val) {
            list.pop_back(val);
        }

        T pop() {
            T topElement = list.back();
            list.pop_back();
            return topElement;
        }

        T peek() const {
            return list.back();
        }

        int size() const {
            return list.size();
        }
};