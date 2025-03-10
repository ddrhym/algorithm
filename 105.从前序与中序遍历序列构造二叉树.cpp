/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30100
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    // 表示preorder数组从begin到end都需要重新构建树
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int prebegin, int preend, int inbegin, int inend) {
        if (inbegin > inend || prebegin > preend) {
            return nullptr;
        }

        int val = preorder[prebegin];
        int index = -1;
        for (int i = inbegin; i <= inend; i++) {
            if (val == inorder[i]) {
                index = i;
                break;
            }
        }

        TreeNode *root = new TreeNode(val);

        int leftSize = index - inbegin;

        root->left = build(preorder, inorder, prebegin + 1, prebegin + leftSize, inbegin, index - 1);
        root->right = build(preorder, inorder, prebegin + leftSize + 1, preend, index + 1, inend);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

