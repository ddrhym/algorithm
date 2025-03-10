/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30100
 *
 * [71] 简化路径
 */

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <string>
#include <sstream>
using std::vector;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
using std::string;
using std::istringstream;
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        istringstream ss(path);
        string part;
        while (std::getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;
            }
            if (part == "..") {
                if (!parts.empty()) {
                    parts.pop_back();
                }
            } else {
                parts.push_back(part);
            }
        }

        string res;
        for (const auto&p: parts) {
            res += "/" + p;
        }

        return res.empty() ? "/" : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */

