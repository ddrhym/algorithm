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
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;

        auto cmp = [](ListNode *p1, ListNode *p2) {return p1->val > p2->val;};
        std::priority_queue<ListNode*, vector<ListNode *>, decltype(cmp)>pq(cmp);

        for (ListNode* p: lists) {
            if (p != nullptr) {
                pq.push(p);
            }
        }

        while (!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();
            if (top->next != nullptr) {
                pq.push(top->next);
            }
            cur->next = top;
            top->next = nullptr;
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

