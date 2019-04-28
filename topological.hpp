#ifndef TOPOLOGICAL_HPP_
#define TOPOLOGICAL_HPP_

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

class adjacencyMatrix
{
	bool **matrix;
	unsigned n;
	
	public:
	adjacencyMatrix(unsigned n);
	~adjacencyMatrix();
	
	void addConnection(unsigned a, unsigned b);
	void remConnection(unsigned a, unsigned b);
	bool isConnected(unsigned a, unsigned b)const;
	unsigned getSize()const{return n;}

};
adjacencyMatrix::adjacencyMatrix(unsigned n)
{
	this->n = n;
	
	matrix = new bool*[n];
	for(decltype(n) i=0; i<n; i++)
	{
		matrix[i] = new bool[n];
		for(decltype(n) f=0; f<n; f++)matrix[i][f] = false;
	}
}
adjacencyMatrix::~adjacencyMatrix()
{
	for(decltype(n) i=0; i<n; i++)delete [] matrix[i];
	delete [] matrix;
}
void adjacencyMatrix::addConnection(unsigned a, unsigned b)
{
	matrix[a][b] = true;
}
void adjacencyMatrix::remConnection(unsigned a, unsigned b)
{
	matrix[a][b] = false;
}
bool adjacencyMatrix::isConnected (unsigned a, unsigned b)const
{
	return matrix[a][b];
}
/////////////////////////////////////
static void tsA(unsigned a, const adjacencyMatrix& ax, unsigned *visited, std::stack<unsigned> &vec)
{
	visited[a] = 1;
	
	for(int i=0; i<ax.getSize(); i++){
		if(!visited[i]){
			if(ax.isConnected(a,i))tsA(i,ax,visited, vec);
		}
	}
	vec.push(a);
}
std::stack<unsigned> ts(const adjacencyMatrix& ax)
{
	std::stack<unsigned> vec;
	
	unsigned *visited = new unsigned[ax.getSize()];
	for(int i=0; i<ax.getSize(); i++)visited[i]=0;
	
	for(int i=0; i<ax.getSize(); i++)
	{
		if(!visited[i])tsA(i, ax, visited, vec);
		//visited[i] = true;
	}
	
	delete [] visited;
	
	return vec;
}
///////////////////////////////
class neighbourList
{
	std::vector<unsigned> *lists;
	unsigned n;
	
	public:
	neighbourList(unsigned n);
	~neighbourList();
	
	void addConnection(unsigned a, unsigned b);
	void remConnection(unsigned a, unsigned b);
	bool isConnected(unsigned a, unsigned b)const;
	const std::vector<unsigned>& getConnections(unsigned a)const;
	unsigned getSize()const{return n;}

};
neighbourList::neighbourList(unsigned n)
{
	this->n = n;
	
	lists = new std::vector<unsigned>[n];
}
neighbourList::~neighbourList()
{
	delete [] lists;
}
void neighbourList::addConnection(unsigned a, unsigned b)
{
	lists[a].push_back(b);
}
void neighbourList::remConnection(unsigned a, unsigned b)
{
	lists[a].erase(std::remove(lists[a].begin(), lists[a].end(), b), lists[a].end());
}
bool neighbourList::isConnected (unsigned a, unsigned b)const
{
	auto ret = std::find(lists[a].begin(), lists[a].end(), b);
	return ret == lists[a].end() ? false : true;
}
const std::vector<unsigned>& neighbourList::getConnections(unsigned a)const
{
	return lists[a];
}
static void tsA(unsigned a, const neighbourList& ax, unsigned *visited, std::stack<unsigned> &vec)
{
	visited[a] = 1;
	
	//auto conns = ax.getConnections(a);
	// Range based for działa dobrze z funkcją zwracającą referencję ;D
	
	for(const auto& i : ax.getConnections(a)){
			if(!visited[i])tsA(i,ax,visited, vec);
	}
	vec.push(a);
}
std::stack<unsigned> ts(const neighbourList& ax)
{
	std::stack<unsigned> vec;
	
	unsigned *visited = new unsigned[ax.getSize()];
	for(int i=0; i<ax.getSize(); i++)visited[i]=0;
	
	for(int i=0; i<ax.getSize(); i++)
	{
		if(!visited[i])tsA(i, ax, visited, vec);
	}
	
	delete [] visited;
	
	return vec;
}

#endif /* !TOPOLOGICAL_HPP_ */
