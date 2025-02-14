/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30005
 *
 * [160] 相交链表
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        int lenA = 0, lenB = 0;

        while (ptrA != nullptr) {
            ptrA = ptrA->next;
            lenA += 1;
        }

        while (ptrB != nullptr) {
            ptrB = ptrB->next;
            lenB += 1;
        }

        int diff = 0;
        if (lenA > lenB) {
            diff = lenA - lenB;
            ptrA = headA;
            ptrB = headB;
            for (int i = 0; i < diff; i++) {
                ptrA = ptrA->next;
            }
        } else {
            diff = lenB - lenA;
            ptrB = headB;
            ptrA = headA;
            for (int i = 0; i < diff; i++) {
                ptrB = ptrB->next;
            }
        }
        while (ptrA != nullptr && ptrB != nullptr) {
            if (ptrA == ptrB) {
                return ptrA;
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

