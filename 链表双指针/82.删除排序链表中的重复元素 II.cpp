/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30005
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        ListNode *slow = &dummy;
        ListNode *fast = head;

        while (fast != nullptr) {
            // 存在一段重复元素
            if (fast->next != nullptr && fast->val == fast->next->val) {
                // 跳过这段重复元素
                while (fast->next != nullptr && fast->val == fast->next->val) {
                    fast = fast->next;
                }
                fast = fast->next;

                if (fast == nullptr) {
                    slow->next = nullptr;
                }
            } else {
                slow->next = fast;
                fast = fast->next;
                slow = slow->next;
            }
            
        }

        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

