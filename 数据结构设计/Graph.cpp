// 有向加权图的邻接表实现
#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;

// 加权有向图的通用实现 (邻接表)
class WeightedGraph {
    public:
        class Edge {
            public:
                int to;
                int weight;
                Edge(int to, int weight) {
                    this->to = to;
                    this->weight = weight;
                }
        };

        WeightedGraph(int n) {
            graph = vector<vector<Edge>>(n);
        }

        // 添加一条带权重的有向边，复杂度O(1)
        void addEdge(int from, int to, int weight) {
            graph[from].emplace_back(to, weight);
        }

        // 删除一条有向边，复杂度O(V)
        void removeEdge(int from, int to) {
            for (auto it = graph[from].begin(); it != graph[from].end(); it++) {
                if (it->to == to) {
                    graph[from].erase(it);
                    break;
                }
            }
        }

        // 判断两个节点是否相邻，复杂度O(V)
        bool hasEdge(int from, int to) {
            for (const auto& e: graph[from]) {
                if (e.to == to) {
                    return true;
                }
            }
            return false;
        }

        // 返回一条边的权重，复杂度O(V)
        int weight(int from, int to) {
            for (const auto& e: graph[from]) {
                if (e.to == to) {
                    return e.weight;
                }
            }
            throw std::invalid_argument("no such edge");
        }

        // 返回某个节点的所有邻居节点, 复杂度O(1)
        const vector<Edge>& neighbors(int v) {
            return graph[v];
        }
    private:
        // 临接表，graph[v]存储节点v的所有邻居节点和对应权重
        vector<vector<Edge>> graph;
};


// 有向加权图的邻接矩阵实现
class WeightedDiagraph {
    public:
        class Edge {
            public:
                int to;
                int weight;
                Edge(int to, int weight): to(to), weight(weight) {}
        };
        WeightedDiagraph(int n) {
            matrix = vector<vector<int>>(n, vector<int>(n, 0));
        }

        void addEdge(int from, int to, int weight) {
            matrix[from][to] = weight;
        }

        void removeEdge(int from, int to) {
            matrix[from][to] = 0;
        }

        // 判断两个节点是否相邻
        bool hasEdge(int from, int to) {
            return matrix[from][to] != 0;
        }

        int weight(int from, int to) {
            return matrix[from][to];
        }

        vector<Edge> neighbors(int v) {
            std::vector<Edge> res;
            for (int i = 0; i < matrix[v].size(); i++) {
                if (matrix[v][i] > 0) {
                    res.push_back(Edge(i, matrix[v][i]));
                }
            }
            return res;
        }
    private:
        vector<vector<int>> matrix;
};