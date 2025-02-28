/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30005
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        std::unordered_map<char, int> window;

        int res = 0;
        while (right < s.size()) {
            char c = s[right];
            right += 1;
            window[c] += 1;

            while (window[c] > 1) {
                char d = s[left];
                left += 1;
                window[d] -= 1;
            }

            res = std::max(res, right - left);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

