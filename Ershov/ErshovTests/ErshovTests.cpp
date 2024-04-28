#define CATCH_CONFIG_MAIN
#include "../../../../Catch2/catch.hpp"
#include "../Ershov/Ershov.h"

TEST_CASE("Test graph coloring and dual graph construction") 
{
    // Создаем граф
    Graph graph(7);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(4, 6);
    graph.AddEdge(5, 6);

    // Раскрашиваем граф и создаем двойственный граф
    vector<int> colors = ErshovColoring(graph);
    Graph dualGraph = CreateDualGraph(graph, colors);

    SECTION("Graph coloring")
    {
        // Проверяем, что вершины раскрашены правильно
        REQUIRE(colors[0] == 0);
        REQUIRE(colors[1] == 1);
        REQUIRE(colors[2] == 2);
        REQUIRE(colors[3] == 3);
        REQUIRE(colors[4] == 0);
        REQUIRE(colors[5] == 1);
        REQUIRE(colors[6] == 2);
    }

    SECTION("Dual graph construction") 
    {
        // Проверяем, что двойственный граф построен верно
        REQUIRE(dualGraph.V == 7); // Двойственный граф должен иметь 7 вершин
    }

    SECTION("Four color theorem check") 
    {
        // Проверяем гипотезу четырех красок
        bool result = CheckFourColorTheorem(dualGraph, colors);
        REQUIRE(result == true); // Гипотеза четырех красок должна быть выполнена
    }
}

TEST_CASE("Test graph coloring and dual graph construction part2")
{
    // Создаем граф
    Graph graph(6);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 0);
    graph.AddEdge(0, 3);

    // Раскрашиваем граф и создаем двойственный граф
    vector<int> colors = ErshovColoring(graph);
    Graph dualGraph = CreateDualGraph(graph, colors);

    SECTION("Graph coloring")
    {
        // Проверяем, что вершины раскрашены правильно
        REQUIRE(colors[0] == 0);
        REQUIRE(colors[1] == 1);
        REQUIRE(colors[2] == 0);
        REQUIRE(colors[3] == 1);
        REQUIRE(colors[4] == 0);
        REQUIRE(colors[5] == 1);
    }

    SECTION("Dual graph construction")
    {
        // Проверяем, что двойственный граф построен верно
        REQUIRE(dualGraph.V == 6); // Двойственный граф должен иметь 6 вершин
    }

    SECTION("Four color theorem check")
    {
        // Проверяем гипотезу четырех красок
        bool result = CheckFourColorTheorem(dualGraph, colors);
        REQUIRE(result == true); // Гипотеза четырех красок должна быть выполнена
    }
}