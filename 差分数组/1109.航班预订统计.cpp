/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 * @lcpr version=30100
 *
 * [1109] 航班预订统计
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n, 0);
        Difference df(nums);
        for (const auto& booking: bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            df.increment(i, j, val);
        }
        return df.result();
    }
private:
    class Difference {
        vector<int> diff;
        public:
            Difference(const vector<int>& nums) {
                diff.resize(nums.size());
                // 构造差分数组
                diff[0] = nums[0];
                for (int i = 1; i < nums.size(); i++) {
                    diff[i] = nums[i] - nums[i - 1];
                }
            }

            // 给区间[i, j]增加val
            void increment(int i, int j, int val) {
                diff[i] += val;
                if (j + 1 < diff.size()) {
                    diff[j + 1] -= val;
                }
            }

            vector<int> result() {
                vector<int> res(diff.size());
                // 根据差分数组结果构造结果数组
                res[0] = diff[0];
                for (int i = 1; i < diff.size(); i++) {
                    res[i] = res[i - 1] + diff[i];
                }
                return res;
            }
    };
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */

