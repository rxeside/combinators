#include "Ershov.h"

using namespace std;

// Функция для добавления ребра в граф
void Graph::AddEdge(int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Функция для раскраски графа с использованием алгоритма Ершова
vector<int> ErshovColoring(Graph& graph)
{
    vector<int> colors(graph.V, -1); // Массив цветов для вершин, -1 обозначает не раскрашенную вершину
    vector<bool> available(graph.V, true); // Массив для отслеживания доступных цветов

    // Начинаем с раскраски первой вершины
    colors[0] = 0;

    // Раскрашиваем остальные вершины
    for (int u = 1; u < graph.V; u++)
    {
        // Перебираем смежные вершины
        for (int v : graph.adj[u])
        {
            if (colors[v] != -1) 
            {
                available[colors[v]] = false; // Метим занятый цвет
            }
        }

        // Находим первый доступный цвет
        int cr;
        for (cr = 0; cr < graph.V; cr++)
        {
            if (available[cr])
            {
                break;
            }
        }

        colors[u] = cr; // Раскрашиваем вершину в найденный цвет

        // Восстанавливаем доступные цвета для следующей итерации
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

// Функция для создания двойственного графа
Graph CreateDualGraph(Graph& graph, vector<int>& colors) 
{
    int V = graph.V;
    Graph dualGraph(V); // Создаем граф с тем же количеством вершин

    // Перебираем вершины оригинального графа
    for (int u = 0; u < V; u++)
    {
        // Перебираем смежные вершины для текущей вершины
        for (int v : graph.adj[u])
        {
            // Добавляем ребро в двойственный граф
            dualGraph.AddEdge(colors[v], colors[u]);
        }
    }

    return dualGraph;
}

// Функция для проверки гипотезы четырех красок
bool CheckFourColorTheorem(Graph& graph, vector<int>& colors) 
{
    int V = graph.V;

    // Проверяем каждое ребро двойственного графа
    for (int u = 0; u < V; u++) 
    {
        for (int v : graph.adj[u]) 
        {
            // Если вершины одного цвета, то гипотеза не выполняется
            if (colors[u] == colors[v]) 
            {
                return false;
            }
        }
    }

    return true;
}

