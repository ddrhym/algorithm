/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30100
 *
 * [450] 删除二叉搜索树中的节点
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
    // 对于删除来说, 如果是叶子节点, 可直接删除
    // 如果只有一个子节点，判断该节点的方位
    // 如果有两个子节点, 需要找到大于它的最小节点, 然后替换
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            TreeNode *minNode = getMin(root->right);
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        } else if (root->val < key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode *getMin(TreeNode *root) {
        TreeNode *cur = root;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

