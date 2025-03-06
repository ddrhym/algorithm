/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30100
 *
 * [2] 两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        ListNode *list1 = l1;
        ListNode *list2 = l2;

        int carry = 0;

        while (list1 != nullptr || list2 != nullptr || carry > 0) {
            int val = carry;
            if (list1 != nullptr) {
                val += list1->val;
                list1 = list1->next;
            }

            if (list2 != nullptr) {
                val += list2->val;
                list2 = list2->next;
            }

            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            cur = cur->next;
        }

        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

