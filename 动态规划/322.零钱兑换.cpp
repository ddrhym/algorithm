/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30008
 *
 * [322] 零钱兑换
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
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount + 1, -100);
        return process1(coins, amount);
    }

    int process1(vector<int>& coins, int amount) {
        int dp[amount + 1];
        for (int i = 0; i < amount + 1; i++) {
            dp[i] = amount + 1;
        }

        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int& coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }

    // 表示要达到amount的数量最少需要使用的硬币数量 
    int process(vector<int>& coins, int amount) {
        int res = INT_MAX;
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }

        if (memo[amount] != -100) {
            return memo[amount];
        }

        for (int& coin: coins) {
            int subproblem = process(coins, amount - coin);
            if (subproblem == -1) {
                continue;
            }
            res = std::min(res, subproblem + 1);
        }

        // 把计算结果存入备忘录
        memo[amount] = (res == INT_MAX) ? - 1: res;
        return memo[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

