/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30100
 *
 * [543] 二叉树的直径
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
    int diameter = -1;

    int diameterOfBinaryTree(TreeNode* root) {
        getPath(root);
        return diameter;
    }

    // 计算当前子树里最长的路径
    int getPath(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftPath = getPath(root->left);
        int rightPath = getPath(root->right);
        diameter = std::max(diameter, leftPath + rightPath);
        return std::max(leftPath, rightPath) + 1;
    } 
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

