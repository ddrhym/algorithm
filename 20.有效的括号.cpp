/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30100
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> left;
        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[') {
                left.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (left.empty()) {
                    return false;
                }
                char test = left.top();
                left.pop();
                if ((c == ')') && (test != '(')) {
                    return false;
                }
                if ((c == '}') && (test != '{')) {
                    return false;
                }
                if ((c == ']') && (test != '[')) {
                    return false;
                }
            }
        }
        return (left.empty());
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */

