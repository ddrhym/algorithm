#include <iostream>
#include <stdexcept>
#include <ostream>
#include <memory>


template <typename T>
class CycleArray {
    private:
        std::unique_ptr<T[]> arr;
        int start;
        int end;
        int count;
        int size;

        // 自动扩容
        void resize(int newSize) {
            std::unique_ptr<T[]> newArr = std::make_unique<T[]>(newSize);

            for (int i = 0; i < count; i++) {
                newArr[i] = this->arr[(start + i) % size];
            }

            // 转移指针所有权
            arr = std::move(newArr);
            start = 0;
            end = count;
            size = newSize;
        }

    public:
        CycleArray(): CycleArray(1) {}
        
        explicit CycleArray(int size): start(0), end(0), count(0), size(size) {
            arr = std::make_unique<T[]>(size);
        }

        // 在环形数组头部添加元素, 时间复杂度为O(1)
        void addFirst(const T& val) {
            if (isFull()) {
                resize(size * 2);
            }

            start = (start - 1 + size) % size; 
            arr[start] = val;
            count += 1;
        }

        void addLast(const T& val) {
            if (isFll()) {
                resize(size * 2);
            }
            arr[end] = val;
            end = (end + 1) % size;
            count += 1;
        }

        void removeFirst() {
            if (isEmpty()) {
                throw std::runtime_error("Array is empty");
            }

            arr[start] = T();
            start = (start + 1) % size;
            count -= 1;

            if (count > 0 && count == size / 4) {
                resize(size / 2);
            }
        }

        void removeLast() {
            if (isEmpty()) {
                throw std::runtime_error("Array is empty");
            }
            end = (end - 1 + size) % size;
            arr[end] = T();
            count -= 1;
            if (count > 0 && count == size / 4) {
                resize(size / 2);
            }
        }

        T getFirst() {
            if (isEmpty()) {
                throw std::runtime_error("Array is empty");
            }
            return this->arr[start];
        }

        T getLast() {
            if (isEmpty()) {
                throw std::runtime_error("Array is empty");
            }
            return this->arr[end];
        }

        bool isFull() {return size == count;}

        int getSize() {
            return size;
        }

        const bool isEmpty() {
            return count == 0;
        }

};