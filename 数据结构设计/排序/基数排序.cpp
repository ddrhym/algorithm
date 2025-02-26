#include <vector>
#include <cmath>
#include <climits>
#include <string.h>
using std::vector;


void radixSort(vector<int>& array) {
    int min = INT_MAX;
    for (int num: array) {
        min = std::min(min, num);
    }

    // 将所有元素转变为非负元素
    int offset = -min;
    for (int i = 0; i < array.size(); i++) {
        array[i] += offset;
    }

    int max = INT_MIN;
    for (int num: array) {
        max = std::max(max, num);
    }

    // 计算最大元素的位数
    int maxLen = 0;
    while (max > 0) {
        max /= 10;
        maxLen += 1;
    }

    // 从低位到高位，依次对每一位进行排序
    for (int k = 0; k < maxLen; k++) {
        countSort(array, k);
    }

    // 将所有元素转变为原来的值
    for (int num: array) {
        num -= offset;
    }
}

void countSort(vector<int>& array, int k) {
    vector<int> count(10, 0);
    
    // 对每个元素的第k位进行计数
    for (int num: array) {
        int digit = (num / static_cast<int>(std::pow(10, k))) % 10;
        count[digit] += 1;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // 按照第k位的值对元素进行排序
    std::vector<int> sorted(array.size());
    for (int i = array.size() - 1; i >= 0; i--) {
        int digit = (array[i] / static_cast<int>(std::pow(10, k))) % 10;
        sorted[count[digit] - 1] = array[i];
        count[digit] -= 1;
    }

    // 把排序结果复制回原始数组
    memcpy(array.data(), sorted.data(), sorted.size() * sizeof(int));
}