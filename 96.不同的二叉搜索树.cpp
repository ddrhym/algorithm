/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30100
 *
 * [96] 不同的二叉搜索树
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
class Solution {
public:
    vector<vector<int>> memo;
    int numTrees(int n) {
        memo.resize(n + 1, vector<int>(n + 1, 0));
        return count(1, n, memo);
    }


    int count(int lo, int hi, vector<vector<int>>& memo) {
        if (lo > hi) {
            return 1;
        }

        if (memo[lo][hi] != 0) {
            return memo[lo][hi];
        }

        int num = 0;
        for (int i = lo; i <= hi; i++) {
            int left = count(lo, i - 1, memo);
            int right = count(i + 1, hi, memo);
            num += left * right;
        }
        memo[lo][hi] = num;
        return num;
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

