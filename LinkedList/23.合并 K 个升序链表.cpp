/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30005
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        // 创建优先级队列
        auto cmp = [](ListNode *p1, ListNode *p2) {return p1->val > p2->val;};
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode *node: lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            cur->next = node;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

