#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>


template <typename T>
class MyPriorityQueue {
    private:
        std::vector<T> heap;
        int size;
        std::function<bool(const T&, const T&)> comparator;

        int parent(int node) {
            return (node - 1) / 2;
        }

        int left(int node) {
            return node * 2 + 1;
        }

        int right(int node) {
            return node * 2 + 2;
        }

        void swap(int i, int j) {
            std::swap(heap[i], heap[j]);
        }

        void resize(int capacity){
            if (capacity > size) {
                heap.resize(capacity);
            }
        }

        // 上浮操作, 时间复杂度是树高 O(logN)
        void swim(int node) {
            while (node > 0 && comparator(heap[parent(node)], heap[node])) {
                swap(parent(node), node);
                node = parent(node);
            }
        }

        void sink(int node) {
            while (left(node) < size || right(node) < size) {
                int min = node;
                if (left(node) < size && comparator(heap[min], heap[left(node)])) {
                    min = left(node);
                }
                if (right(node) < size && comparator(heap[min], heap[right(node)])) {
                    min = right(node);
                }
                if (min == node) {
                    break;
                }
                swap(node, min);
                node = min;
            }
        }
    
        public:
            MyPriorityQueue(int capacity, std::function<bool(const T&, const T&)> comparator): heap(capacity), size(0), comparator(std::move(comparator)) {}

            int getSize() const {
                return size;
            }

            bool isEmpty() const {
                return size == 0;
            }

            const T& peek() const {
                if (isEmpty()) {
                    throw std::underflow_error("Priority queue underflow");
                }
                return heap[0];
            }

            void push(const T& x) {
                if (size == heap.size()) {
                    resize(2 * heap.size());
                }

                // 把新元素添加到最后
                heap[size] = x;

                // 上浮到正确的位置
                swim(size);
                size += 1;
            }

            int pop() {
                int res = heap[0];
                heap[0] = heap[size - 1];
                size -= 1;
                sink(0);
                return res;
            }
};