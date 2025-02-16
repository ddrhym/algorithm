/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30005
 *
 * [167] 两数之和 II - 输入有序数组
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> ans;
        int start = 0; 
        int end = numbers.size() - 1;
        while (start != end) {
            if (numbers[start] + numbers[end] == target) {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            } else if (numbers[start] + numbers[end] < target) {
                start = start + 1;
            } else {
                end = end - 1;
            }
        }
        return ans;
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

