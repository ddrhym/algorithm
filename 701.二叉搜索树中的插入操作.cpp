/*
 * @lc app=leetcode.cn id=701 lang=cpp
 * @lcpr version=30100
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode *prev;
        TreeNode *cur = root;
        bool isLeft = true;
        while (cur != nullptr) {
            if (val < cur->val) {
                prev = cur;
                cur = cur->left;
                isLeft = true;
            } else if (val > cur->val) {
                prev = cur;
                cur = cur->right;
                isLeft = false;
            }
        }
            if (isLeft) {
                prev->left = new TreeNode(val);
            } else {
                prev->right = new TreeNode(val);
            }
        return root;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [40,20,60,10,30,50,70]\n25\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3,null,null,null,null,null,null]\n5\n
// @lcpr case=end

 */

