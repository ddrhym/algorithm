/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=30100
 *
 * [1260] 二维网格迁移
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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n = grid[0].size();
        int mn = m * n;
        k = k % mn;
        // 先把最后k个数字进行翻转
        reverse(grid, mn - k, mn - 1);
        // 把前mn - k 个数字进行翻转
        reverse(grid, 0, mn - k - 1);
        reverse(grid, 0, mn - 1);

        return grid;
    }

    // 通过一维数组的索引访问二维数组的元素
    int get(vector<vector<int>>& grid, int index) {
        int n = grid[0].size();
        int i = index / n;
        int j = index % n;
        return grid[i][j];
    }

    // 通过一维数组的索引修改二维数组的元素
    void set(vector<vector<int>>& grid, int index, int val) {
        int n = grid[0].size();
        int i = index / n, j = index % n;
        grid[i][j] = val;
    }

    // 翻转一维数组的索引区间的元素
    void reverse(vector<vector<int>>& grid, int i, int j) {
        while (i < j) {
            int temp = get(grid, i);
            set(grid, i, get(grid, j));
            set(grid, j, temp);
            i += 1;
            j -= 1;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

 */

