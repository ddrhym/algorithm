/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30100
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int>& inorder, vector<int>& postorder, int inbegin, int inend, int postbegin, int postend) {
        if (inbegin > inend || postbegin > postend) {
            return nullptr;
        }

        int val = postorder[postend];
        int index = -1;
        for (int i = inbegin; i <= inend; i++) {
            if (inorder[i] == val) {
                index = i;
                break;
            }
        }

        TreeNode *root = new TreeNode(val);
        int leftSize = index - inbegin;
        root->left = build(inorder, postorder, inbegin, index - 1, postbegin, postbegin + leftSize - 1);
        root->right = build(inorder, postorder, inbegin + leftSize + 1, inend, postbegin + leftSize, postend - 1);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

