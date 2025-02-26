/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30006
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode smaller_dummy(-1);
        ListNode not_smaller_dummy(-1);
        ListNode *cur = head;
        ListNode *smaller_cur = &smaller_dummy;
        ListNode *larger_cur = &not_smaller_dummy;

        while (cur != nullptr) {
            if (cur->val < x) {
                smaller_cur->next = cur;
                smaller_cur = smaller_cur->next;
            } else {
                larger_cur->next = cur;
                larger_cur = larger_cur->next;
            }
            ListNode *temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        smaller_cur->next = not_smaller_dummy.next;
        return smaller_dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */

