#include <iostream>
#include <vector>
#include <list>


template<typename K, typename V>
class MyChainingHashMap {
    private:
        class KVNode {
            public:
                K key;
                V value;
                KVNode(K key, V value): key(key), value(std::move(value)) {}
        };

        std::vector<std::list<KVNode>> table;
        int size;
        static constexpr int INIT_CAP = 4;

        int hash(K key) {
            return (std::hash<K>{}(key) & 0x7fffffff) % table.size();
        }

        void resize(int newCap) {
            newCap = std::max(newCap, 1);
            MyChainingHashMap<K, V> newMap(newCap);
            for (auto& list: table) {
                for (auto& node: list) {
                    newMap.put(node.key, node.value);
                }
            }

            this->table = newMap.table;
        }
    public:
        MyChainingHashMap(): MyChainingHashMap(INIT_CAP) {}
        explicit MyChainingHashMap(int initCapacity) {
            size = 0;
            initCapacity = std::max(initCapacity, 1);
            table.resize(initCapacity);
        }
        
};
