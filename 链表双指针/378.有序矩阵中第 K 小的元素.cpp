/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30100
 *
 * [378] 有序矩阵中第 K 小的元素
 */

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b) {return a[0] > b[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }

        vector<int> res;
        while (!pq.empty() && k > 0) {
            res = pq.top();
            pq.pop();
            k -= 1;
            if (res[2] + 1 < matrix.size()) {
                pq.push({matrix[res[1]][res[2] + 1], res[1], res[2] + 1});
            } 
        }
        return res[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */

