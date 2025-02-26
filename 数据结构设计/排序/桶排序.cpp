#include <vector>
#include <iostream>
#include <climits>
using std::vector;


void bucketSort(vector<int>& nums, int bucketCount) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int& val: nums) {
        if (min > val) {
            min = val;
        }
        if (max < val) {
            max = val;
        }
    }

    // 理论上每个桶需要装的元素个数
    int bucketSize = (max - min) / bucketCount + 1;

    vector<int> buckets[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = vector<int>();
    }

    // 将元素分配到桶中
    for (int num: nums) {
        int index = (num - min) / bucketSize;
        buckets[index].push_back(num);
    }

    // 对每个桶中的元素进行排序
    for (int i = 0; i < bucketCount; i++) {
        insertSort(buckets[i]);
    }

    // 合并有序桶
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int num: buckets[i]) {
            nums[index] = num;
            index += 1;
        }
    }
}

void insertSort(vector<int>& array) {
    int sortIndex = 0;
    int length = array.size();
    while (sortIndex < length) {
        for (int i = sortIndex; i > 0; i--) {
            if (array[i] < array[i - 1]) {
                // 交换两个元素
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            } else {
                break;
            }
        }
        sortIndex += 1;
    }
}