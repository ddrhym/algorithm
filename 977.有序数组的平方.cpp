/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30100
 *
 * [977] 有序数组的平方
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
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sorted(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;
        int cur = nums.size() - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                sorted[cur] = nums[left] * nums[left];
                cur -= 1;
                left += 1;
            } else if (abs(nums[left]) <= abs(nums[right])) {
                sorted[cur] = nums[right] * nums[right];
                cur -= 1;
                right -= 1;
            }
        }
        return sorted;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

