#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph 
{
    int V; // ���������� ������
    vector<vector<int>> adj; // ������ ���������

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // ������� ��� ���������� ����� � ����
    void AddEdge(int u, int v);
};
vector<int> ErshovColoring(Graph& graph);
Graph CreateDualGraph(Graph& graph, vector<int>& colors);
bool CheckFourColorTheorem(Graph& graph, vector<int>& colors);