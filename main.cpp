#include "topological.hpp"
#include "randomDAG.hpp"
#include <iostream>

int main()
{
	auto x = generateRandomDAG(10, 0.5);
	adjacencyMatrix ax = x.first;
	//ax.addConnection(3,1);
	//ax.addConnection(3,0);
	//ax.addConnection(3,4);
	//
	//ax.addConnection(1,2);
	//ax.addConnection(1,0);
	//
	//ax.addConnection(0,2);
	//
	//ax.addConnection(4,2);
	//ax.addConnection(4,1);
	//
	//ax.addConnection(5,0);
	//ax.addConnection(5,4);
	//ax.addConnection(3,1);
	
	auto ret = ts(ax);
	
	while(!ret.empty()){
		std::cout<<ret.top()<<" ";
		ret.pop();
	}

/////
	neighbourList nl = x.second;
	//nl.addConnection(3,1);
	//nl.addConnection(3,0);
	//nl.addConnection(3,4);
	//
	//nl.addConnection(1,2);
	//nl.addConnection(1,0);
	//
	//nl.addConnection(0,2);
	//
	//nl.addConnection(4,2);
	//nl.addConnection(4,1);
	//
	//nl.addConnection(5,0);
	//nl.addConnection(5,4);
	//nl.addConnection(3,1);
	
	ret = ts(nl);
	std::cout<<"\n";
	while(!ret.empty()){
		std::cout<<ret.top()<<" ";
		ret.pop();
	}
	
}