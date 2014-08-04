
// problem 1437. Longest path in a tree -- problem code: PT07Z
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void updateDistances (int index, vector<int>& distances, const vector<vector<unsigned int> >& graph);
void printDistances (const vector<int>& distances);

int main(void) {
  int numNodes;
  cin >> numNodes;

  vector<vector<unsigned int> > graph (numNodes, vector<unsigned int>());


  for (int edgeCounter = 0; edgeCounter < numNodes - 1; edgeCounter++)
    {
      int first, second;
      cin >> first >> second;
      graph [first-1].push_back(second-1);
      graph [second-1].push_back(first-1);
    }

  int maxDist = 0;
  for (int nodeCounter = 0; nodeCounter < numNodes; nodeCounter++) {
      vector<int> distances (numNodes, numNodes);
      distances [nodeCounter] = 0;
      updateDistances (nodeCounter, distances, graph);
      //printDistances (distances);
      int max = 0;
      for (int counter = 0, size = distances.size(); counter < size; counter++) 
	if (distances[counter] > max) 
	  max = distances [counter];

      if (maxDist < max)
	maxDist = max;
  }
  cout << maxDist << endl;
  return 0;
}

void updateDistances (int index, vector<int>& distances, const vector<vector<unsigned int> >& graph) {
  for (int counter = 0, end = graph[index].size(); counter < end; counter++) {
    int id = graph[index][counter];
    if (distances [id] > distances [index] + 1) {
      distances [id] = distances[index] + 1;
      updateDistances (id, distances, graph);
    }
  }
  
}

void printDistances (const vector<int>& distances){
  for (int counter = 0, size = distances.size(); counter < size; counter++)
    cout << distances[counter] << " ";
  cout << endl;
}
