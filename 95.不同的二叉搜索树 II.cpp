/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=30100
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> res;
        if (lo > hi) {
            res.emplace_back(nullptr);
            return res;
        }

        // 穷举root的所有可能
        for (int root = lo; root <= hi; root++) {
            vector<TreeNode*> left = build(lo, root - 1);
            vector<TreeNode*> right = build(root + 1, hi);
            for (auto& leftTree: left) {
                for (auto& rightTree: right) {
                    TreeNode *head = new TreeNode(root);
                    head->left = leftTree;
                    head->right = rightTree;
                    res.emplace_back(head);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

