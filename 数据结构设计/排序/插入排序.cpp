#include <vector>
using std::vector;


void sort(vector<int>& array) {
    int n = array.size();
    // 维护[0, sortIndex)为有序数组
    int sortIndex = 0;
    while (sortIndex < n) {
        for (int i = sortIndex; i > 0; i--) {
            if (array[i] < array[i - 1]) {
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