/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30005
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        std::string res = "";
        for (int i = 0; i < s.length(); i++) {
            std::string s1 = findPalindrome(s, i, i);
            std::string s2 = findPalindrome(s, i, i + 1);
            res = res.length() < s1.length() ? s1 : res;
            res = res.length() < s2.length() ? s2 : res;
        }
        return res;
    }

    std::string findPalindrome(std::string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l -= 1;
            r += 1;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

