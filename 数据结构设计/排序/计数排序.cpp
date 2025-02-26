#include <vector>
#include <climits>
#include <string.h>
using std::vector;


void sort(vector<int>& array) {
    int min = INT_MAX;
    int max = INT_MIN;

    // find the minimum and maximum value of the array
    for (int num: array) {
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }

    // 创建新的计数的数组
    int range = max - min + 1;
    vector<int> count(range);
    
    // 计数
    for (int num: array) {
        count[num - min] += 1;
    }

    // 累加数组
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // 从后往前遍历数组
    vector<int> sorted(array.size());
    for (int i = array.size() - 1; i >= 0; i--) {
        sorted[count[array[i] - min] - 1] = array[i];
    }

    memcpy(array.data(), sorted.data(), sorted.size() * sizeof(int));
}
