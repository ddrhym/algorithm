/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30008
 *
 * [509] 斐波那契数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        vector<int> memo(n + 1);
        memo[0] = 0;
        memo[1] = 1;
        // 动态转移方程
        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n];
    }

    // // 带备忘录的动态规划方法, 用于解决重复计算的问题
    // int process(vector<int>& memo, int n) {
    //     // base case
    //     if (n == 0 || n == 1) {
    //         return n;
    //     }

    //     // 已经计算过了，不需要再重复计算
    //     if (memo[n] != 0) {
    //         return memo[n];
    //     }

    //     memo[n] = process(memo, n - 1) + process(memo, n - 2);
    //     return memo[n];
    // }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

