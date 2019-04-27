#include <iostream>
#include <stack>

class adjancencyMatrix
{
	bool **matrix;
	unsigned n;
	
	public:
	adjancencyMatrix(unsigned n);
	~adjancencyMatrix();
	
	void addConnection(unsigned a, unsigned b);
	void remConnection(unsigned a, unsigned b);
	bool isConnected(unsigned a, unsigned b)const;
	unsigned getSize()const{return n;}

};
adjancencyMatrix::adjancencyMatrix(unsigned n)
{
	this->n = n;
	
	matrix = new bool*[n];
	for(decltype(n) i=0; i<n; i++)
	{
		matrix[i] = new bool[n];
		for(decltype(n) f=0; f<n; f++)matrix[i][f] = false;
	}
}
adjancencyMatrix::~adjancencyMatrix()
{
	for(decltype(n) i=0; i<n; i++)delete [] matrix[i];
	delete [] matrix;
}
void adjancencyMatrix::addConnection(unsigned a, unsigned b)
{
	matrix[a][b] = true;
}
void adjancencyMatrix::remConnection(unsigned a, unsigned b)
{
	matrix[a][b] = false;
}
bool adjancencyMatrix::isConnected (unsigned a, unsigned b)const
{
	return matrix[a][b];
}
/////////////////////////////////////
static void tsA(unsigned a, const adjancencyMatrix& ax, unsigned *visited, std::stack<unsigned> &vec)
{
	visited[a] = 1;
	
	for(int i=0; i<ax.getSize(); i++){
		if(!visited[i]){
			if(ax.isConnected(a,i))tsA(i,ax,visited, vec);
		}
	}
	vec.push(a);
}
std::stack<unsigned> ts(const adjancencyMatrix& ax)
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
