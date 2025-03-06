/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30100
 *
 * [373] 查找和最小的 K 对数字
 */

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        auto cmp = [](vector<int>& v1, vector<int>& v2){return v1[0] + v1[1] > v2[0] + v2[1];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;

        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i], nums2[0], 0});
        }

        int count = 0;
        while (!pq.empty() && count < k) {
            vector<int> cur = pq.top();
            pq.pop();
            count += 1;
            res.push_back({cur[0], cur[1]});

            if (cur[2] + 1 < nums2.size()) {
                pq.push({cur[0], nums2[cur[2] + 1], cur[2] + 1});
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */

