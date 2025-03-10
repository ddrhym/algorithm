/*
 * @lc app=leetcode.cn id=652 lang=cpp
 * @lcpr version=30100
 *
 * [652] 寻找重复的子树
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
    unordered_map<string, int> filter;
    vector<TreeNode *> res;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }

    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "#";
        }

        string left = serialize(root->left);
        string right = serialize(root->right);
        string myself = left + "," + right + "," + std::to_string(root->val);

        int freq = filter[myself];
        if (freq == 1) {
            res.push_back(root);
        }
        filter[myself] += 1;
        return myself;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,null,2,4,null,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,3,null,3,null]\n
// @lcpr case=end

 */

