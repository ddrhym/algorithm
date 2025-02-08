#include <iostream>
#include <vector>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(NULL) {}
};

// 输入一个数组，转换成一条单链表
ListNode *createLinkedList(std::vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

class DoubleListNode {
    public:
        int val;
        DoubleListNode *next, *prev;
        DoubleListNode(int x): val(x), next(NULL), prev(NULL) {}
};

DoubleListNode *createDoubleLinkedList(std::vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }

    DoubleListNode *head = new DoubleListNode(arr[0]);
    DoubleListNode *cur = head;
    for (int i = 1; i < arr.size(); i++) {
        DoubleListNode *newNode = new DoubleListNode(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}

int main() {
    ListNode *head = createLinkedList({1, 2, 3, 4, 5});
    for (ListNode *p = head; p != nullptr; p = p ->next) {
        std::cout << p -> val << std::endl;
    }
    return 0;
}