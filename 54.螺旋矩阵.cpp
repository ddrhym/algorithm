/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30100
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int upper_bound = 0;
        int lower_bound = matrix.size() - 1;
        int left_bound = 0;
        int right_bound = matrix[0].size() - 1;

        int m = matrix.size();
        int n = matrix[0].size();

        while (res.size() < m * n) {
            if (upper_bound <= lower_bound) {
            for (int i = left_bound; i <= right_bound; i++) {
                res.push_back(matrix[upper_bound][i]);
            }
            }

            upper_bound += 1;

            if (left_bound <= right_bound) {
            for (int i = upper_bound; i<= lower_bound; i++) {
                res.push_back(matrix[i][right_bound]);
            }

            }

            right_bound -= 1;

            if (upper_bound <= lower_bound) {
            for (int i = right_bound; i >= left_bound; i--) {
                res.push_back(matrix[lower_bound][i]);
            }
            }

            lower_bound -= 1;

            if (left_bound <= right_bound) {
            for (int i = lower_bound; i >= upper_bound; i--) {
                res.push_back(matrix[i][left_bound]);
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
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

