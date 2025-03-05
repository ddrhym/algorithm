/*
 * @lc app=leetcode.cn id=773 lang=cpp
 * @lcpr version=30100
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        // 将2x3数组转化为BFS的起点
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                start = start + std::to_string(board[i][j]);
            }
        }

        std::queue<std::string> q;

        // 单纯的二维数组无法进行哈希，需要进行序列化
        std::unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();

                if (target == cur) {
                    return step;
                }

                // 将数字0和相邻的数字交换位置
                for (string neighbor: getNeighbors(cur)) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }

            step += 1;
        }
        return -1;
    }

    vector<string> getNeighbors(string board) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,0,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,4,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,1,2],[5,0,3]]\n
// @lcpr case=end

 */

