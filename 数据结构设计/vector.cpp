#include <iostream>
#include <stdexcept>
#include <vector>

template <typename E>
class MyArrayList {
    private:
        // 真正存储数据的底层数组
        E *data;

        // 记录当前元素个数
        int size;

        // 最大元素容量
        int cap;

        // 默认初始容量 
        static const int INIT_CAP = 1;
    public:
        MyArrayList() {
            this->data = new E[INIT_CAP];
            this->size = 0;
            this->cap = INIT_CAP;
        }

        MyArrayList(int initCapacity) {
            this->data = new E[initCapacity];
            this->size = 0;
            this->cap = initCapacity;
        }

        // add element
        void addLast(E e) {
            if (size == cap) {
                resize(2 * cap);
            }
            data[size] = e;
            size += 1;
        }

        void add(int index, E e) {
            // 检查索引越界
            checkPositionIndex(index);
            if (size == cap) {
                resize(2 * cap);
            }
            for (int i = this->size - 1; i >= index; i--) {
                data[i + 1] = data[i];
            }

            data[index] = e;
            size += 1;
        }

        void addFirst(E e) {
            add(0, e);
        }

        // 删除最后一个位置处的元素
        E removeLast() {
            if (size == 0) {
                throw std::out_of_range("No such element exception");
            }

            if (size == cap / 4) {
                this->resize(cap / 2);
            }

            E deletedVal = this->data[this->size - 1];
            data[this->size - 1] = NULL;
            size -= 1;
            return deletedVal;
        }

        E remove(int index) {
            checkElementIndex(index);

            if (size == cap /4) {
                resize(cap / 2);
            }

            E deletedVal = this->data[index];
            for (int i = index + 1; i < this->size; i++) {
                this->data[i - 1] = this->data[i];
            }

            this->data[this->size - 1] = NULL;
            this->size -= 1;
            return deletedVal;
        }

        E removeFirst() {
            return remove(0);
        }

        bool isElementIndex(int index) {
            return index >= 0 && index < this->size;
        }

        bool isPositionIndex(int index) {
            return index >= 0 && index <= this->size;
        }

        // 检查index位置是否可以存在元素
        void checkElementIndex(int index) {
            if (!isElementIndex(index)) {
                throw std::out_of_range("Index out of bounds");
            }
        }

        void checkPositionIndex(int index) {
            if (!isPositionIndex(index)) {
                throw std::out_of_range("Index out of bounds");
            }
        }

        int getSize() {
            return this->size;
        }

        bool isEmpty() {
            return this->size == 0;
        }

        // 将data的容量更改为newCap
        void resize(int newCap) {
            E *temp = new E[newCap];
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }

            delete[] data;
            data = temp;
            cap = newCap;
        }

        E get(int index) {
            checkElementIndex(index);
            return this->data[index];
        }

        E set(int index, E element) {
            checkElementIndex(index);
            E oldVal = data[index];
            data[index] = element;
            return oldVal;
        }

        void display() {
            std::cout << "size = " << this->size << " cap = " << this->cap << std::endl;
            for (int i = 0; i < this->size; i++) {
                std::cout << this->data[i] << " ";
            }
            std::cout << std::endl;
        }

        ~MyArrayList() {
            delete[] this->data;
        }
};


int main() {
    // 初始容量设置为 3
    MyArrayList<int> arr(3);

    // 添加 5 个元素
    for (int i = 1; i <= 5; i++) {
        arr.addLast(i);
    }

    arr.remove(3);
    arr.add(1, 9);
    arr.addFirst(100);
    int val = arr.removeLast();

    // 100 1 9 2 3
    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.get(i) << std::endl;
    }

    return 0;
}