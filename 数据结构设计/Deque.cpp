#include <iostream>
#include <list>


template<typename E>
class MyListDeque {
    std::list<E> list;

public:
    // 从队头插入元素，时间复杂度 O(1)
    void addFirst(const E &e) {
        list.push_front(e);
    }

    // 从队尾插入元素，时间复杂度 O(1)
    void addLast(const E &e) {
        list.push_back(e);
    }

    // 从队头删除元素，时间复杂度 O(1)
    E removeFirst() {
        E firstElement = list.front();
        list.pop_front();
        return firstElement;
    }

    // 从队尾删除元素，时间复杂度 O(1)
    E removeLast() {
        E lastElement = list.back();
        list.pop_back();
        return lastElement;
    }

    // 查看队头元素，时间复杂度 O(1)
    E peekFirst() {
        return list.front();
    }

    // 查看队尾元素，时间复杂度 O(1)
    E peekLast() {
        return list.back();
    }
};
