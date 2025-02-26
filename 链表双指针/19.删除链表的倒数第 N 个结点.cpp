/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30005
 *
 * [19] 删除链表的倒数第 N 个结点
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 删除倒数第n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // 找到倒数第n+1个节点
        ListNode *prev = findFromEnd(dummy, n + 1);
        prev->next = prev->next->next;
        return dummy->next;
    }

    ListNode *findFromEnd(ListNode *head, int k) {
        ListNode *p1 = head;
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }

        ListNode *p2 = head;
        while (p1 != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

