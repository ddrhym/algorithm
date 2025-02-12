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

        void put(K key, V val) {
            auto& list = table[hash(key)];

            // 如果key之前已经存在，则修改对应的val
            for (auto& node: list) {
                if (node.key == key) {
                    node.value = val;
                    return;
                }
            }
            list.emplace_back(key, val);
            size += 1;
            if (size >= table.size() * 0.75) {
                resize(table.size() * 2);
            }
        }

        void remove(K key) {
            auto& list = table[hash(key)];
            for (auto it = list.begin(); it != list.end(); it++) {
                if (it->key == key) {
                    list.erase(it);
                    size -= 1;

                    if (size <= table.size() / 8) {
                        resize(table.size() / 4);
                    }
                    return;
                }
            }
        }

        V get(K key) {
            const auto& list = table[hash(key)];
            for (const auto& node: list) {
                if (node.key == key) {
                    return node.value;
                }
            }
            return nullptr;
        }

        // 返回所有key
        std::list<K> keys() {
            std::list<K> keys;
            for (const auto& list: table) {
                for (const auto& node: list) {
                    keys.push_back(node.key);
                }
            }
            return keys;
        }

        int size() const {
            return size;
        }
};
