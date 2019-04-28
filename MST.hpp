#include <map>
#include <functional>
#include <cstdio>
#include "topological.hpp"


struct prev
{
    int from, to, weight;
};

struct cmp
{
    bool operator()(const prev& lhs, const prev& rhs) const
    {
        return lhs.weight < rhs.weight;
    }
};

// Prim algorithm
neighbourList mst(const neighbourList& g)
{
    int toTake = g.getSize();
    neighbourList ret(toTake);
    std::vector<bool> visited(toTake);
    std::set<prev, cmp> priorityQueue;
    for (const auto& i : g.getConnections(0))
    {
        priorityQueue.insert({0, (int)i, rand()%1000});
        //std::cout<<0<<" "<<i<<"\n";
    }
    while (toTake && !priorityQueue.empty())
    {
        toTake--;
        auto top = *priorityQueue.begin();
        priorityQueue.erase(priorityQueue.begin());
        
        while (visited[top.to] && !priorityQueue.empty())
        {
            top = *priorityQueue.begin();
            priorityQueue.erase(priorityQueue.begin());
        }
        //if (priorityQueue.empty()) break;
        for (const auto& i : g.getConnections(top.to))
        {
            priorityQueue.insert({top.to, (int)i, rand()%1000}); 
            //std::cout<<top.to<<" "<<i<<"\n";
        }
       // std::cout<<top.from<<" "<<top.to<<"\n";
        ret.addConnection(top.from, top.to);
        visited[top.to] = true;
    }
    //for (auto x : visited) std::cout<<x<<" ";
    //std::cout<<"\n";
    return ret;
}

adjacencyMatrix mst(const adjacencyMatrix& g)
{
    int toTake = g.getSize();
    adjacencyMatrix ret(toTake);
    std::vector<bool> visited(toTake);
    std::set<prev, cmp> priorityQueue;
    for (int i = 0; i < g.getSize(); i++)
    {
        if (!g.isConnected(0, i))
            continue;
        priorityQueue.insert({0, (int)i, rand()%1000});
        //std::cout<<0<<" "<<i<<"\n";
    }
    while (toTake && !priorityQueue.empty())
    {
        toTake--;
        auto top = *priorityQueue.begin();
        priorityQueue.erase(priorityQueue.begin());
        
        while (visited[top.to] && !priorityQueue.empty())
        {
            top = *priorityQueue.begin();
            priorityQueue.erase(priorityQueue.begin());
        }
        //if (priorityQueue.empty()) break;
        for (int i = 0; i < g.getSize(); i++)
        {
            if (!g.isConnected(top.to, i))
                continue;
            priorityQueue.insert({top.to, (int)i, rand()%1000}); 
            //std::cout<<top.to<<" "<<i<<"\n";
        }
       // std::cout<<top.from<<" "<<top.to<<"\n";
        ret.addConnection(top.from, top.to);
        visited[top.to] = true;
    }
    //for (auto x : visited) std::cout<<x<<" ";
    //std::cout<<"\n";
    return ret;
}