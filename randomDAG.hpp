#ifndef RANDOMDAG_HPP_
#define RANDOMDAG_HPP_

#include <vector>
#include <set>
#include <random>
#include "topological.hpp"

std::pair<adjacencyMatrix, neighbourList> generateRandomDAG(int size, float factor)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> rng(0, size - 2);
    std::set<std::pair<int, int>> arcs;
    int a = size - 1, b;

    arcs.insert({0, 1});
    arcs.insert({0, 3 });
    arcs.insert({1, 2});

    while (arcs.size() < size*(size - 1)/2*factor)
    {
        a = rng(mt);
        std::uniform_int_distribution<int> rng2(a + 1, size - 1);
        b = rng2(mt);
        arcs.insert({a, b});
    }
    // Trzeba jeszcze przemapować numery

    std::pair<adjacencyMatrix, neighbourList> ret{size, size};
    for (const auto& arc : arcs)
    {
        ret.first.addConnection(arc.first, arc.second);
        ret.second.addConnection(arc.first, arc.second);
    }

    return ret;
}

#endif /* !RANDOMDAG_HPP_ */
