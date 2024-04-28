#define CATCH_CONFIG_MAIN
#include "../../../../Catch2/catch.hpp"
#include "../Ershov/Ershov.h"

TEST_CASE("Test graph coloring and dual graph construction") 
{
    // ������� ����
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

    // ������������ ���� � ������� ������������ ����
    vector<int> colors = ErshovColoring(graph);
    Graph dualGraph = CreateDualGraph(graph, colors);

    SECTION("Graph coloring")
    {
        // ���������, ��� ������� ���������� ���������
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
        // ���������, ��� ������������ ���� �������� �����
        REQUIRE(dualGraph.V == 7); // ������������ ���� ������ ����� 7 ������
    }

    SECTION("Four color theorem check") 
    {
        // ��������� �������� ������� ������
        bool result = CheckFourColorTheorem(dualGraph, colors);
        REQUIRE(result == true); // �������� ������� ������ ������ ���� ���������
    }
}

TEST_CASE("Test graph coloring and dual graph construction part2")
{
    // ������� ����
    Graph graph(6);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 0);
    graph.AddEdge(0, 3);

    // ������������ ���� � ������� ������������ ����
    vector<int> colors = ErshovColoring(graph);
    Graph dualGraph = CreateDualGraph(graph, colors);

    SECTION("Graph coloring")
    {
        // ���������, ��� ������� ���������� ���������
        REQUIRE(colors[0] == 0);
        REQUIRE(colors[1] == 1);
        REQUIRE(colors[2] == 0);
        REQUIRE(colors[3] == 1);
        REQUIRE(colors[4] == 0);
        REQUIRE(colors[5] == 1);
    }

    SECTION("Dual graph construction")
    {
        // ���������, ��� ������������ ���� �������� �����
        REQUIRE(dualGraph.V == 6); // ������������ ���� ������ ����� 6 ������
    }

    SECTION("Four color theorem check")
    {
        // ��������� �������� ������� ������
        bool result = CheckFourColorTheorem(dualGraph, colors);
        REQUIRE(result == true); // �������� ������� ������ ������ ���� ���������
    }
}