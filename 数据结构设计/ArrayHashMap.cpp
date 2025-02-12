#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>


template <typename K, typename V>
class MyArrayHashMap {
    private:
        class Node {
            K key;
            V value;
            Node(K key, V val): key(key), value(value) {}
        };

        // 存储key和key在arr中对应的索引
        std::unordered_map<K, int> map;
        std::vector<Node> arr;
        std::default_random_engine e;
    public:
        MyArrayHashMap() {
            e.seed(std::random_device()());
        }

        V get(K key) {
            if (!map.count(key)) {
                return NULL;
            }
            int index = map[key];
            return arr[index].val;
        }

        void put(K key, V value) {
            if (containsKey(key)) {
                int i = map[key];
                arr[i].val = val;
                return;
            }

            arr.push_back(Node(key, value));
            map[key] = arr.size() - 1;
        }

        void remove(K key) {
            if (!map.count(key)) {
                return;
            }

            int index = map[key];
            Node node = arr[index];
            Node e = arr.back();
            std::swap(arr[index], e);
            map[e.key] = index;
            arr.pop_back();
            map.erase(node.key);
        }

        K randomKey() {
            int n = arr.size();
            std::uniform_int_distribution<int> u(0, n - 1);
            int randomIndex = u(e);
            return arr[randomIndex].key;
        }

        bool containsKey(K key) {
            return map.count(key);
        }

        int size() {
            return map.size();
        }
};