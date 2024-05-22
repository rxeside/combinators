#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // если ваш граф ориентированный, удалите эту строку
    }

    vector<int> mostPopularNodes() {
        unordered_map<int, int> degreeCounts;

        // Подсчет степеней вершин
        for (auto& pair : adjList) {
            int node = pair.first;
            int degree = pair.second.size();
            degreeCounts[node] = degree;
        }

        // Нахождение максимальной степени
        int maxDegree = 0;
        for (auto& pair : degreeCounts) {
            maxDegree = max(maxDegree, pair.second);
        }

        // Сбор вершин с максимальной степенью центральности
        vector<int> mostPopularNodes;
        for (auto& pair : degreeCounts) {
            if (pair.second == maxDegree) {
                mostPopularNodes.push_back(pair.first);
            }
        }

        return mostPopularNodes;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Graph g;
    int numEdges;
    cout << "Введите количество рёбер в графе: ";
    cin >> numEdges;

    cout << "Введите рёбра в формате 'вершина1 вершина2':\n";
    for (int i = 0; i < numEdges; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    vector<int> mostPopular = g.mostPopularNodes();
    if (!mostPopular.empty()) {
        cout << "Самые популярные вершины: ";
        for (int node : mostPopular) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "Граф пустой" << endl;
    }

    return 0;
}
