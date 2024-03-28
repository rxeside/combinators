#include "FindDots.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<std::vector<bool>> graph =
    {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 1},
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0},
    };
    std::vector<int> res = FindArticulationPoints(graph);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
}