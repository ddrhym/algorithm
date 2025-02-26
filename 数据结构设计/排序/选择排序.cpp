#include <vector>
#include <iostream>

using std::vector;

void sort(vector<int>& array) {
    int sortIndex = 0;  // 左边为所有已经有序的部分
    int length = array.size();
    while (sortIndex < length) {
        int minIndex = sortIndex;
        for (int i = sortIndex + 1; i < length; i++) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }

        int temp = array[minIndex];
        array[minIndex] = array[sortIndex];
        array[sortIndex] = temp;

        sortIndex += 1;
    }
}