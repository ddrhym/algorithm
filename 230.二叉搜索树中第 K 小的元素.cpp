/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30100
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int res = -1;
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left);
        count -= 1;
        if (count == 0) {
            res = root->val;
        }
        traverse(root->right);
    }

    int count = 0;
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */

