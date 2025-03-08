/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30100
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s) {
        string sb;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // 判断一个字符是否为字母或数字
            if (isalnum(c)) {
                sb += tolower(c);
            }
        }

        int left = 0;
        int right = sb.size() - 1;
        while (left < right) {
            if (sb[left] != sb[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */

