/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30100
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        // 将左子树作为右子树
        root->left = nullptr;
        root->right = left;

        TreeNode *p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

