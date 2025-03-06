/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30100
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stack>
using std::stack;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;

        while (ptr1 != nullptr) {
            s1.push(ptr1->val);
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr) {
            s2.push(ptr2->val);
            ptr2 = ptr2->next;
        }

        ListNode dummy(-1);
        ListNode *cur = &dummy;

        int carry = 0;
        int val = 0;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            val = carry;
            if (!s1.empty()) {
                val += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }

            if (val >= 10) {
                val = val - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }

        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

