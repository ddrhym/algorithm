/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30100
 *
 * [80] 删除有序数组中的重复项 II
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
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int count = 0;

        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow += 1;
                nums[slow] = nums[fast];
            } else if (slow < fast && count < 2) {
                slow += 1;
                nums[slow] = nums[fast];
            }

            fast += 1;
            count += 1;
            if (fast < nums.size() && nums[fast] != nums[fast - 1]) {
                count = 0;
            }
        }
        return slow + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

