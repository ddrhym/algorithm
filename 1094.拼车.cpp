/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=30100
 *
 * [1094] 拼车
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 最多有1000个车站
        vector<int> nums(1001, 0);
        Difference df(nums);
        for (const auto& trip: trips) {
            // 乘客数量
            int val = trip[0];
            int i = trip[1];
            int j = trip[2] - 1;
            df.increment(i, j, val);
        }

        vector<int> res = df.result();
        for (int i = 0; i < res.size(); i++) {
            if (capacity < res[i]) {
                return false;
            }
        }
        return true;
    }

private:
    class Difference {
        vector<int> diff;
        public:
            Difference(vector<int>& nums) {
                diff.resize(nums.size());
                diff[0] = nums[0];
                for (int i = 1; i < nums.size(); i++) {
                    diff[i] = nums[i] - nums[i - 1];
                }
            }

            void increment(int i, int j, int val) {
                diff[i] += val;
                if (j + 1 < diff.size()) {
                    diff[j + 1] -= val;
                }
            }

            vector<int> result() {
                vector<int> res(diff.size());
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
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

