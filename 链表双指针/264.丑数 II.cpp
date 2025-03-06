/*
 * @lc app=leetcode.cn id=264 lang=cpp
 * @lcpr version=30100
 *
 * [264] 丑数 II
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n + 1);
        int count = 1;
        int p_2 = 1;
        int p_3 = 1;
        int p_5 = 1;

        int val_2 = 1;
        int val_3 = 1;
        int val_5 = 1;

        while (count <= n) {
            ans[count] = std::min({val_2, val_3, val_5});
            if (ans[count] == val_2) {
                val_2 = 2 * ans[p_2];
                p_2 += 1;
            }
            if (ans[count] == val_3) {
                val_3 = 3 * ans[p_3];
                p_3 += 1;
            }
            if (ans[count] == val_5) {
                val_5 = 5 * ans[p_5];
                p_5 += 1;
            }
            count += 1;
        }
        return ans[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

