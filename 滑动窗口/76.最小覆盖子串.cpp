/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30005
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        // 实际需要进行匹配的子串
        std::unordered_map<char, int> need;
        // 移动窗口中有的元素和其对应数量
        std::unordered_map<char, int> window;

        // 将需要匹配的子串放入need中进行统计
        for (char c: t) {
            need[c] += 1;
        }

        int left = 0, right = 0;
        int valid = 0;  // 记录window中的字符满足need条件的字符个数
        int start = 0, len = INT_MAX;   // 记录最小覆盖子串的起始索引和长度

        while (right < s.length()) {
            // 当前需要进入滑动窗口的元素
            char c = s[right];
            right += 1;

            // need中存在该元素
            if (need.count(c)) {
                window[c] += 1;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }

            // 判断窗口左侧是否需要收缩
            while (valid == need.size()) {
                // 新窗口如果小于原始窗口, 需要缩小窗口的大小
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                // 即将离开窗口的元素
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
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

