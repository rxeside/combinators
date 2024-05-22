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
        adjList[w].push_back(v); // ���� ��� ���� ���������������, ������� ��� ������
    }

    vector<int> mostPopularNodes() {
        unordered_map<int, int> degreeCounts;

        // ������� �������� ������
        for (auto& pair : adjList) {
            int node = pair.first;
            int degree = pair.second.size();
            degreeCounts[node] = degree;
        }

        // ���������� ������������ �������
        int maxDegree = 0;
        for (auto& pair : degreeCounts) {
            maxDegree = max(maxDegree, pair.second);
        }

        // ���� ������ � ������������ �������� �������������
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
    cout << "������� ���������� ���� � �����: ";
    cin >> numEdges;

    cout << "������� ���� � ������� '�������1 �������2':\n";
    for (int i = 0; i < numEdges; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    vector<int> mostPopular = g.mostPopularNodes();
    if (!mostPopular.empty()) {
        cout << "����� ���������� �������: ";
        for (int node : mostPopular) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "���� ������" << endl;
    }

    return 0;
}
