/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30100
 *
 * [143] 重排链表
 */

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <string>
using std::vector;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
using std::string;
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
    void reorderList(ListNode* head) {
        stack<ListNode *> s;
        ListNode *cur = head;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->next;
        }

        cur = head;

        while (!s.empty()) {
            ListNode *lastNode = s.top();
            s.pop();
            ListNode *next = cur->next;

            if (next == lastNode || lastNode->next == next) {
                lastNode->next = nullptr;
                break;
            }

            cur->next = lastNode;
            lastNode->next = next;
            cur = next;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

