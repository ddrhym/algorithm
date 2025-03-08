/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=30100
 *
 * [724] 寻找数组的中心下标
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
    vector<int> preSum;
    int pivotIndex(vector<int>& nums) {
        preSum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (preSum[i] == (preSum[nums.size()] - preSum[i + 1])) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */

