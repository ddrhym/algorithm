/*
 * @lc app=leetcode.cn id=933 lang=cpp
 * @lcpr version=30100
 *
 * [933] 最近的请求次数
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
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end



/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping", "ping"][[], [1], [100], [3001], [3002]]\n
// @lcpr case=end

 */

