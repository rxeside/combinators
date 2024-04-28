#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph 
{
    int V; // Количество вершин
    vector<vector<int>> adj; // Вектор смежности

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Функция для добавления ребра в граф
    void AddEdge(int u, int v);
};
vector<int> ErshovColoring(Graph& graph);
Graph CreateDualGraph(Graph& graph, vector<int>& colors);
bool CheckFourColorTheorem(Graph& graph, vector<int>& colors);