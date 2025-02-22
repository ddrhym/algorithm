/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30005
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        std::unordered_map<char, int> need;
        std::unordered_map<char, int> window;
        std::vector<int> ans;

        for (char c: p) {
            need[c] += 1;
        }

        int left = 0; 
        int right = 0;
        int valid = 0;

        while (right < s.size()) {
            char c = s[right];
            right += 1;
            if (need.count(c)) {
                window[c] += 1;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    ans.push_back(left);
                }
                char d = s[left];
                left += 1;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid -= 1;
                    }
                    window[d] -= 1;
                }
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

