/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30005
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast != nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow += 1;
            }
            fast += 1;
        }

        while (slow != nums.size()) {
            nums[slow] = 0;
            slow += 1;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

