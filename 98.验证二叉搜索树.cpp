/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30100
 *
 * [98] 验证二叉搜索树
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return process(root, nullptr, nullptr);
    }

    bool process(TreeNode *head, TreeNode *min, TreeNode *max) {
        if (head == nullptr) {
            return true;
        }

        if (min != nullptr && head->val <= min->val) {
            return false;
        }

        if (max != nullptr && head->val >= max->val) {
            return false;
        }

        return process(head->left, min, head) && process(head->right, head, max);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

