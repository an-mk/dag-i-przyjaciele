#include "topological.hpp"
#include "randomDAG.hpp"
#include "MeasurementTool.hpp"
#include <iostream>

using TestDataType = std::pair<adjacencyMatrix, neighbourList>;

int main() 
{
    MesurementLab<TestDataType, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600> lab;
    lab.setTestGenerator([](const size_t &sizeOfTest){ return generateRandomDAG(sizeOfTest, 0.6f); });
    lab([](const std::pair<adjacencyMatrix, neighbourList>& G){ ts(G.first); }, "adjacencyMatrix");
    lab([](const std::pair<adjacencyMatrix, neighbourList>& G){ ts(G.first); }, "neighbourList");
    return 0;
}