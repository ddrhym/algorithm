/*
 * @lc app=leetcode.cn id=297 lang=cpp
 * @lcpr version=30100
 *
 * [297] 二叉树的序列化与反序列化
 */

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <string>
#include <list>
#include <sstream>
using std::vector;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
using std::string;
using std::list;
using std::istringstream;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string SEP = ",";
    string NULLSYM = "#";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string sb;
        _serialize(root, sb);
        return sb;
    }

    void _serialize(TreeNode *root, string& sb) {
        if (root == nullptr) {
            sb.append(NULLSYM).append(SEP);
            return;
        }

        sb.append(std::to_string(root->val)).append(SEP);
        _serialize(root->left, sb);
        _serialize(root->right, sb);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> nodes;
        istringstream iss(data);
        string s;
        while (getline(iss, s, ',')) {
            nodes.push_back(s);
        }

        return _deserialize(nodes);
    }

    TreeNode* _deserialize(list<string>& nodes) {
        if (nodes.empty()) {
            return nullptr;
        }

        string first = nodes.front();
        nodes.pop_front();
        if (first == NULLSYM) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(first));
        root->left = _deserialize(nodes);
        root->right = _deserialize(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,null,4,5]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

