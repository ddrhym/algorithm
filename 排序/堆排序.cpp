#include <vector>
using std::vector;


int parent(int node) {
    return (node - 1) >> 1;
}

int left(int node) {
    return node << 1 + 1;
}

int right(int node) {
    return node << 1 + 2;
}

void swap(vector<int>& heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

/// @brief 小顶堆的上浮操作
/// @param heap 
/// @param node 
void minHeapSwim(vector<int>& heap, int node) {
    while (node > 0 && heap[node] < heap[parent(node)]) {
        swap(heap, node, parent(node));
        node = parent(node);
    }
}

/// @brief 小顶堆的下沉操作
/// @param heap 
/// @param node 
void minHeapSink(vector<int>& heap, int node) {
    while (node < heap.size()) {
        int minIndex = node;
        if (left(node) < heap.size() && heap[minIndex] > heap[left(node)]) {
            minIndex = left(node);
        }
        if (right(node) < heap.size() && heap[minIndex] > heap[right(node)]) {
            minIndex = right(node);
        }

        if (minIndex == node) {
            break;
        }

        swap(heap, node, minIndex);
        node = minIndex;
    }
}
