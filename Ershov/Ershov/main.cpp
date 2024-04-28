#include "Ershov.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int V, E;
    cout << "Введите количество вершин и рёбер: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Введите рёбра в формате (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    vector<int> colors = ErshovColoring(graph);

    cout << "Раскраска вершин:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Вершина " << i << ": Цвет " << colors[i] << endl;
    }

    Graph dualGraph = CreateDualGraph(graph, colors);

    cout << "Рёбра двойственного графа:" << endl;
    for (int u = 0; u < V; u++)
    {
        for (int v : dualGraph.adj[u])
        {
            cout << u << " " << v << endl;
        }
    }

    bool fourColorTheorem = CheckFourColorTheorem(dualGraph, colors);

    if (fourColorTheorem)
    {
        cout << "Гипотеза четырех красок выполняется." << endl;
    }
    else 
    {
        cout << "Гипотеза четырех красок не выполняется." << endl;
    }

    return 0;
}
