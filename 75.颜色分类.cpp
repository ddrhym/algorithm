/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30100
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int p0 = 0; 
        int p = 0;
        int p2 = nums.size() - 1;

        while (p <= p2) {
            if (nums[p] == 0) {
                swap(nums, p0, p);
                p0 += 1;
            } else if (nums[p] == 2) {
                swap(nums, p2, p);
                p2 -= 1;
            } else if (nums[p] == 1) {
                p += 1;
            }

            if (p < p0) {
                p = p0;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j]; 
        nums[j] = tmp;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

