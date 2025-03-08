/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30100
 *
 * [1329] 将矩阵按对角线排序
 */

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <string>
#include <list>
using std::vector;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
using std::string;
using std::list;
// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // 矩阵的行
        int m = mat.size();
        // 矩阵的列
        int n = mat[0].size();

        std::unordered_map<int, std::list<int>> diagonals;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diagonalID = i - j;
                diagonals[diagonalID].push_back(mat[i][j]);
            }
        }

        // 从数组末尾删除元素效率比较高
        for (auto& diagonal: diagonals) {
            diagonal.second.sort(std::greater<int>());
        }

        // 把结果填充回原始的二维矩阵
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::list<int>& diagonal = diagonals[i - j];
                mat[i][j] = diagonal.back();
                diagonal.pop_back();
            }
        }
        return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

