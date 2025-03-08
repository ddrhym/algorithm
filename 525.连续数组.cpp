/*
 * @lc app=leetcode.cn id=525 lang=cpp
 * @lcpr version=30100
 *
 * [525] 连续数组
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
    int findMaxLength(vector<int>& nums) {
        // 将0理解为-1，就变成寻找前缀和中[i...j]范围内preSum[j] - preSum[i] = 0的坐标
        // 可以通过哈希表很快速的找到是否存在
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + (nums[i] == 0 ? -1 : 1);
        }

        // 前缀和到索引的映射，方便快速查找所需的前缀和 
        unordered_map<int, int> valToIndex;
        int res = 0;
        for (int i = 0; i < preSum.size(); i++) {
            // 这个前缀和还没有对应的索引，说明这个前缀和第一次出现，记录下来
            if (valToIndex.find(preSum[i]) == valToIndex.end()) {
                valToIndex[preSum[i]] = i;
            } else {
                // 这个前缀和已经出现过了，则找到一个和为0的子数组
                res = std::max(res, i - valToIndex[preSum[i]]);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,1,1,0,0,0]\n
// @lcpr case=end

 */

