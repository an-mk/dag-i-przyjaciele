#include "topological.hpp"
#include "randomDAG.hpp"
#include "MST.hpp"
#include "MeasurementTool.hpp"
#include <iostream>
#include <omp.h>

using TestDataType = std::pair<adjacencyMatrix, neighbourList>;

int main() 
{
    omp_set_num_threads(8);
	mst(generateRandomDAG(15,1).second);
    MesurementLab<TestDataType, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600> lab;
    lab.setTestGenerator([](const size_t &sizeOfTest){ return generateRandomDAG(sizeOfTest, 0.6f); });
    lab([](const std::pair<adjacencyMatrix, neighbourList>& G){ ts(G.first); }, "ts adjacencyMatrix");
    lab([](const std::pair<adjacencyMatrix, neighbourList>& G){ ts(G.second); }, "ts neighbourList");

	//MesurementLab<TestDataType, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600> lab;
    //lab.setTestGenerator([](const size_t &sizeOfTest){ return generateRandomDAG(sizeOfTest, 0.6f); });
    lab([](const std::pair<adjacencyMatrix, neighbourList>& G){ mst(G.first); }, "mst adjacencyMatrix");
    lab([](const std::pair<adjacencyMatrix, neighbourList>& G){ mst(G.second); }, "mst neighbourList");
    return 0;
}