/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30008
 *
 * [46] 全排列
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
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> track;
        traverse(nums, track, used);
        return ans;
    }

    // 路径: 已经做出的选择
    // 选择列表: 当前可以做的选择
    // 结束条件: 到达最底层的决策树，无法再做选择的条件
    void traverse(vector<int>& nums, vector<int>& track, vector<bool>& used) {
        if (track.size() == nums.size()) {
            ans.push_back(track);
            return;
        }

        for (int i = 0 ; i < used.size(); i++) {
            if (used[i]) {
                continue;
            }

            track.push_back(nums[i]);
            used[i] = true;
            traverse(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

