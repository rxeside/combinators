#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../../../../Catch2/catch.hpp"
#include "../FindDots/FindDots.h"


SCENARIO("backpackProblem")
{
    WHEN("input array isn't empty")
    {
        std::ostringstream out;
        THEN("output isn't empty")
        {
            std::vector<std::vector<bool>> graph =
            {
                {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            };
            auto data = FindArticulationPoints(graph);
            copy(data.begin(), data.end(), std::ostream_iterator<int>(out, " "));
            REQUIRE(out.str() == "1 2 3 4 7 9 ");
        }
        THEN("output isn't empty")
        {
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
            auto data = FindArticulationPoints(graph);
            copy(data.begin(), data.end(), std::ostream_iterator<int>(out, " "));
            REQUIRE(out.str() == "2 5 ");
        }
        THEN("output isn't empty")
        {
            std::vector<std::vector<bool>> graph =
            {
                {0, 1, 0, 0, 0, 0, 0, 0},
                {1, 0, 1, 1, 0, 0, 0, 0},
                {0, 1, 0, 1, 0, 0, 1, 0},
                {0, 1, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 1, 1},
                {0, 0, 0, 0, 1, 0, 0, 0},
                {0, 0, 1, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 1, 0},
            };
            auto data = FindArticulationPoints(graph);
            copy(data.begin(), data.end(), std::ostream_iterator<int>(out, " "));
            REQUIRE(out.str() == "2 3 5 7 ");
        }
        THEN("output isn't empty")
        {
            std::vector<std::vector<bool>> graph =
            {
                {0, 1, 0, 0, 0, 1, 0, 0},
                {1, 0, 1, 1, 0, 0, 0, 0},
                {0, 1, 0, 1, 0, 0, 1, 0},
                {0, 1, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 1, 1},
                {1, 0, 0, 0, 1, 0, 0, 0},
                {0, 0, 1, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 1, 0},
            };
            auto data = FindArticulationPoints(graph);
            copy(data.begin(), data.end(), std::ostream_iterator<int>(out, " "));
            REQUIRE(out.str() == "");
        }
    }
};