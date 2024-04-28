#include "Ershov.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int V, E;
    cout << "������� ���������� ������ � ����: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "������� ���� � ������� (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    vector<int> colors = ErshovColoring(graph);

    cout << "��������� ������:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "������� " << i << ": ���� " << colors[i] << endl;
    }

    Graph dualGraph = CreateDualGraph(graph, colors);

    cout << "и��� ������������� �����:" << endl;
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
        cout << "�������� ������� ������ �����������." << endl;
    }
    else 
    {
        cout << "�������� ������� ������ �� �����������." << endl;
    }

    return 0;
}
