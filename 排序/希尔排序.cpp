#include <vector>
using std::vector;


void sort(vector<int>& array) {
    int n = array.size();
    int h = 1;
    while (h < n / 2) {
        h = h * 2;
    }

    while (h >= 1) {
        int sortIndex = h;
        while (sortIndex < n) {
            for (int i = sortIndex; i >= h; i -= h) {
                if (array[i] < array[i - h]) {
                    int temp = array[i];
                    array[i] = array[i - h];
                    array[i - h] = temp;
                } else {
                    break;
                }
            }

            sortIndex += 1;
        }
        
        h /= 2;
    }
}