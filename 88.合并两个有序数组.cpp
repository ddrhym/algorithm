/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=30100
 *
 * [88] 合并两个有序数组
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int p = nums1.size() - 1;

        while (ptr1 >= 0 && ptr2 >= 0) {
            if (nums1[ptr1] > nums2[ptr2]) {
                nums1[p] = nums1[ptr1];
                p -= 1;
                ptr1 -= 1;
            } else if (nums2[ptr2] >= nums1[ptr1]) {
                nums1[p] = nums2[ptr2];
                ptr2 -= 1;
                p -= 1;
            } 
        }

        while (ptr1 >= 0) {
            nums1[p] = nums1[ptr1];
            p -= 1;
            ptr1 -= 1;
        }

        while (ptr2 >= 0) {
            nums1[p] = nums2[ptr2];
            p -= 1;
            ptr2 -= 1;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */

