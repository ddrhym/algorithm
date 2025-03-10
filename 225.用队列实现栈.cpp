/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30100
 *
 * [225] 用队列实现栈
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
class MyStack {
public:
    queue<int> q;
    int topval = -1;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topval = x;
    }
    
    int pop() {
        int size = q.size();
        for (int i = 0; i < size - 2; i++) {
            q.push(q.front());
            q.pop();
        }
        topval = q.front();
        q.push(q.front());
        q.pop();

        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return topval;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

