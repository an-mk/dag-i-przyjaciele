#include "topological.hpp"
#include <iostream>

int main()
{
	adjancencyMatrix ax(6);
	ax.addConnection(3,1);
	ax.addConnection(3,0);
	ax.addConnection(3,4);
	
	ax.addConnection(1,2);
	ax.addConnection(1,0);
	
	ax.addConnection(0,2);
	
	ax.addConnection(4,2);
	ax.addConnection(4,1);
	
	ax.addConnection(5,0);
	ax.addConnection(5,4);
	//ax.addConnection(3,1);
	
	auto ret = ts(ax);
	
	while(!ret.empty()){
		std::cout<<ret.top()<<" ";
		ret.pop();
	}
	
}