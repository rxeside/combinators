#include "Ershov.h"

using namespace std;

// ������� ��� ���������� ����� � ����
void Graph::AddEdge(int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// ������� ��� ��������� ����� � �������������� ��������� ������
vector<int> ErshovColoring(Graph& graph)
{
    vector<int> colors(graph.V, -1); // ������ ������ ��� ������, -1 ���������� �� ������������ �������
    vector<bool> available(graph.V, true); // ������ ��� ������������ ��������� ������

    // �������� � ��������� ������ �������
    colors[0] = 0;

    // ������������ ��������� �������
    for (int u = 1; u < graph.V; u++)
    {
        // ���������� ������� �������
        for (int v : graph.adj[u])
        {
            if (colors[v] != -1) 
            {
                available[colors[v]] = false; // ����� ������� ����
            }
        }

        // ������� ������ ��������� ����
        int cr;
        for (cr = 0; cr < graph.V; cr++)
        {
            if (available[cr])
            {
                break;
            }
        }

        colors[u] = cr; // ������������ ������� � ��������� ����

        // ��������������� ��������� ����� ��� ��������� ��������
        for (int v : graph.adj[u]) 
        {
            if (colors[v] != -1)
            {
                available[colors[v]] = true;
            }
        }
    }

    return colors;
}

// ������� ��� �������� ������������� �����
Graph CreateDualGraph(Graph& graph, vector<int>& colors) 
{
    int V = graph.V;
    Graph dualGraph(V); // ������� ���� � ��� �� ����������� ������

    // ���������� ������� ������������� �����
    for (int u = 0; u < V; u++)
    {
        // ���������� ������� ������� ��� ������� �������
        for (int v : graph.adj[u])
        {
            // ��������� ����� � ������������ ����
            dualGraph.AddEdge(colors[v], colors[u]);
        }
    }

    return dualGraph;
}

// ������� ��� �������� �������� ������� ������
bool CheckFourColorTheorem(Graph& graph, vector<int>& colors) 
{
    int V = graph.V;

    // ��������� ������ ����� ������������� �����
    for (int u = 0; u < V; u++) 
    {
        for (int v : graph.adj[u]) 
        {
            // ���� ������� ������ �����, �� �������� �� �����������
            if (colors[u] == colors[v]) 
            {
                return false;
            }
        }
    }

    return true;
}

