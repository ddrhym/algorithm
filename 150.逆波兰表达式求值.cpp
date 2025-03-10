/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30100
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                if (token == "+") {
                    s.push(val1 + val2);
                } else if (token == "-") {
                    s.push(val2 - val1);
                } else if (token == "*") {
                    s.push(val1 * val2);
                } else if (token == "/") {
                    s.push(val2 / val1);
                }
            }
            else {
                s.push(std::stoi(token));
            }
        }
        return s.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

