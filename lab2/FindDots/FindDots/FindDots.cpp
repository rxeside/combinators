#include "FindDots.h"

void EmplaceOutTimeMapAndUpTimeUp(TimeMap& upTimeMap, TimeMap& outTimeMap, int& currentTime, int& vertex, int& possibleUp) {
    outTimeMap.emplace(vertex, currentTime);
    upTimeMap.emplace(vertex, possibleUp);
    currentTime++;
}

void RootCheck(int& root, int& vertex, int& childrenCounter, std::vector<int>& articulatedPoints) {
    if (root == vertex && childrenCounter > 1)
    {
        articulatedPoints.push_back(vertex + 1);
    }
}

void DFS(int vertex, std::vector<std::vector<bool>>& graph, TimeMap& inTimeMap, TimeMap& outTimeMap, TimeMap& upTimeMap, 
    std::vector<int>& visitedSons, int& currentTime, std::vector<int>& articulatedPoints, int root)
{
    visitedSons.push_back(vertex);
    currentTime++;
    inTimeMap.emplace(vertex, currentTime);
    int possibleUp = currentTime;
    int childrenCounter = 0;
    for (int j = 0; j < graph.size(); j++)
    {
        if (graph[vertex][j])
        {
            if (std::count(visitedSons.begin(), visitedSons.end(), j) == 0)
            {
                childrenCounter++;
                DFS(j, graph, inTimeMap, outTimeMap, upTimeMap, visitedSons, currentTime, articulatedPoints, root);

                if (upTimeMap[j] >= inTimeMap[vertex] && std::count(articulatedPoints.begin(), articulatedPoints.end(), vertex + 1) == 0 && root != vertex)
                {   
                    articulatedPoints.push_back(vertex + 1);
                }

                if (upTimeMap[j] < possibleUp) 
                {
                    possibleUp = upTimeMap[j];
                }
            }
            else
            {
                if (inTimeMap[j] < possibleUp) 
                {
                    possibleUp = inTimeMap[j];
                }
            }
        }
    }
    RootCheck(root, vertex, childrenCounter, articulatedPoints);
    

    EmplaceOutTimeMapAndUpTimeUp(upTimeMap, outTimeMap, currentTime, vertex, possibleUp);
}

std::vector<int> FindArticulationPoints(std::vector<std::vector<bool>>& graph)
{
    TimeMap inTimeMap;
    TimeMap outTimeMap;
    TimeMap upTimeMap;
    std::vector<int> articulatedPoints;
    std::vector<int> visitedSons;
    int currentTime = 0;
    DFS(0, graph, inTimeMap, outTimeMap, upTimeMap, visitedSons, currentTime, articulatedPoints, 0);
    std::sort(articulatedPoints.begin(), articulatedPoints.end());
    return articulatedPoints;
};