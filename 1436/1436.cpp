
// problem 1436. It is a tree -- problem code: PT07Y
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void mark (vector<bool> &marked, int index, const vector<vector<unsigned int> >& graph);

int main(void) {
  int numNodes, numEdges;
  cin >> numNodes >> numEdges;

  vector<vector<unsigned int> > graph (numNodes, vector<unsigned int>());
  vector<bool> marked (numNodes, false);
  for (int edgeCounter = 0; edgeCounter < numEdges; edgeCounter++)
    {
      int first, second;
      cin >> first >> second;
      graph [first-1].push_back(second-1);
      graph [second-1].push_back(first-1);
    }

  if (numEdges != numNodes - 1)
    cout << "NO" << endl;
  else {
  
    mark(marked, 0, graph);
    bool isTree = true;
    for (int nodeCounter = 1; isTree && nodeCounter < numNodes; nodeCounter++)
      if (!marked[nodeCounter])
	isTree = false;
  
    if (isTree)
      cout << "YES";
    else
      cout << "NO";
  
    cout << endl;
  }

  return 0;
}

void mark (vector<bool> &marked, int index, const vector<vector<unsigned int> >& graph) {
  marked[index] = true;
  for (int counter = 0, last = graph[index].size(); counter < last; counter++)
    if (!marked[graph[index][counter]]) 
      mark(marked, graph[index][counter], graph);
}
