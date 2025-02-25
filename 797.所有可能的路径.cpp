/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=30005
 *
 * [797] 所有可能的路径
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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traverse(graph, 0);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int s) {
        path.push_back(s);
        int n = graph.size();
        if (s == n - 1) {
            res.push_back(vector<int>(path));
            path.pop_back();
            return;
        }

        for (int v: graph[s]) {
            traverse(graph, v);
        }

        path.pop_back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */

