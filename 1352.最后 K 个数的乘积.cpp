/*
 * @lc app=leetcode.cn id=1352 lang=cpp
 * @lcpr version=30100
 *
 * [1352] 最后 K 个数的乘积
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
class ProductOfNumbers {
public:
    vector<int> preProduct;
    ProductOfNumbers() {
        preProduct.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            // 如果添加的是0，则前面的元素积全部废了
            preProduct.clear();
            preProduct.push_back(1);
            return;
        }
        int n = preProduct.size();
        preProduct.push_back(preProduct[n - 1] * num);
    }
    
    int getProduct(int k) {
        int n = preProduct.size();
        // 不足k个元素，是因为最后k个元素存在0
        if (k > n - 1) {
            return 0;
        }
        return preProduct[n - 1] / preProduct[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end



/*
// @lcpr case=start
// ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"][[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]\n
// @lcpr case=end

 */

