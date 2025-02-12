#include <iostream>
#include <list>


template <typename T>
class MyLinkedListQueue {
    private:
        std::list<T> list;
    public:
        void push(const T& val) {
            this->list.push_back(val);
        }

        E pop() {
            E front = this->list.begin();
            this->list.pop_front();
            return front;
        }

        E peek() {
            return this->list.front();
        }
        
        int size() {
            return this->list.size();
        }
};


// 数组实现队列涉及到一个问题: 删除头部元素涉及到元素复制, 需要用环形数组实现