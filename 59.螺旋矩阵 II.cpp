/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30100
 *
 * [59] 螺旋矩阵 II
 */

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using std::vector;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int upper_bound = 0;
        int lower_bound = n - 1;
        int left_bound = 0;
        int right_bound = n - 1;

        vector<vector<int>> res(n, vector<int>(n, 0));

        int count = 1;

        while (count <= n * n) {
            if (upper_bound <= lower_bound) {
                for (int i = left_bound; i <= right_bound; i++) {
                    res[upper_bound][i] = count;
                    count += 1;
                }
            }

            upper_bound += 1;

            if (left_bound <= right_bound) {
                for (int i = upper_bound; i<= lower_bound; i++) {
                    res[i][right_bound] = count;
                    count += 1;
                }
            }

            right_bound -= 1;

            if (upper_bound <= lower_bound) {
                for (int i = right_bound; i >= left_bound; i--) {
                    res[lower_bound][i] = count;
                    count += 1;
                }
            }

            lower_bound -= 1;

            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; i--) {
                    res[i][left_bound] = count;
                    count += 1;
                }
            }

            left_bound += 1;
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

