/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30100
 *
 * [167] 两数之和 II - 输入有序数组
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;
        while (left < right) {
            int left_num = numbers[left];
            int right_num = numbers[right];
            int sum = left_num + right_num;

            if (sum < target) {
                while (left < right && numbers[left] == left_num) {
                    left += 1;
                }
            } else if (sum > target) {
                while (left < right && numbers[right] == right_num) {
                    right -= 1;
                }
            } else {
                res.push_back(left + 1);
                res.push_back(right + 1);

                while (left < right && numbers[left] == left_num) {
                    left += 1;
                }

                while (left < right && numbers[right] == right_num) {
                    right -= 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

