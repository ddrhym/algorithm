#include <vector>
using std::vector;


// 对选择排序进行第一次优化，获得稳定性
void sort(std::vector<int>& array) {
    int n = array.size();
    int sortIndex = 0;
    while (sortIndex < n) {
        int minIndex = sortIndex;
        for (int i = sortIndex + 1; i < n; i++) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }

        int minVal = array[minIndex];
        // 将aray[minIndex]插入到nums[sortIndex]的位置 (插入就涉及到后续数据的搬运)
        for (int i = minIndex; i > sortIndex; i--) {
            array[i] = array[i - 1];
        }

        sortIndex += 1;
    }
}

// 冒泡
void sort1(std::vector<int>& array) {
    int n = array.size();
    int sortIndex = 0;
    while (sortIndex < n) {
        // 寻找array[sortIndex,,,]中的最小值
        for (int i = n - 1; i > sortIndex; i--) {
            if (array[i] < array[i - 1]) {
                int tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
            }
        }

        sortIndex += 1;
    }
}

void sort2(std::vector<int>& array) {
    int n = array.size();
    int sortIndex = 0;
    while (sortIndex < n) {
        bool swap = false;
        for (int i = n - 1; i > sortIndex; i--) {
            if (array[i] < array[i - 1]) {
                int tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
                swap = true;
            }
        }

        // 如果一次交换操作都没有执行，说明数组已经有序，可以提前终止算法
        if (!swap) {
            break;
        }

        sortIndex += 1;
    }
}