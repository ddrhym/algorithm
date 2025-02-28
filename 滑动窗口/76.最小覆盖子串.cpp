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
        // 滑动窗口
        std::unordered_map<char, int> window;
        // 真实需要的字符和其对应的出现次数
        std::unordered_map<char, int> need;

        // 统计需要的字符和其对应的出现次数
        for (char c: t) {
            need[c] += 1;
        }

        int left = 0;
        int right = 0;
        
        // 记录最小覆盖子串的开始索引
        int start = 0;

        // 记录最小覆盖子串的长度
        int len = INT_MAX;

        // 表示已经满足出现次数的所有字符数量
        int valid = 0;

        while (right < s.size()) {
            char cur = s[right];

            // 扩大窗口右边界
            right += 1;

            // need需要这个字符
            if (need.find(cur) != need.end()) {
                window[cur] += 1;
                // 判断该字符出现的次数是否和need需要的次数相同
                if (window[cur] == need[cur]) {
                    valid += 1;
                }
            }

            // 窗口开始缩小
            while (valid == need.size()) {
                // 更新最小覆盖字串的开始和长度信息
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                // 将要移除的字符
                char left_char = s[left];
                left += 1;
                
                // 将要移除的元素是need需要的元素
                if (need.find(left_char) != need.end()) {
                    window[left_char] -= 1;
                    if (window[left_char] < need[left_char]) {
                        valid -= 1;
                    }
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

