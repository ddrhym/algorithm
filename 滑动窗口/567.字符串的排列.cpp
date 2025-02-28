/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=30005
 *
 * [567] 字符串的排列
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
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> window;
        std::unordered_map<char, int> need;
        for (char c: s1) {
            need[c] += 1;
        }

        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s2.size()) {
            char next = s2[right];
            right += 1;

            // need需要这个字符串
            if (need.find(next) != need.end()) {
                window[next] += 1;

                if (window[next] == need[next]) {
                    valid += 1;
                }
            }
            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }

                // 将要离开滑动窗口的字符
                char d = s2[left];
                left += 1;

                if (need.find(d) != need.end()) {
                    if (window[d] == need[d]) {
                        valid -= 1;
                    }
                    window[d] -= 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */

