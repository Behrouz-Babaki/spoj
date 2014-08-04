
// problem 1437. Longest path in a tree -- problem code: PT07Z
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void updateDistances (int index, vector<unsigned int>& distances, vector<bool>& visited, const vector<vector<unsigned int> >& graph);
void printDistances (const vector<int>& distances);

int maxIndex; 
int maxDist;

int main(void) {
  int numNodes;
  cin >> numNodes;

  vector<vector<unsigned int> > graph (numNodes, vector<unsigned int>());
  vector<unsigned int> distances (numNodes, 0);

  for (int edgeCounter = 0; edgeCounter < numNodes - 1; edgeCounter++)
    {
      int first, second;
      cin >> first >> second;
      graph [first-1].push_back(second-1);
      graph [second-1].push_back(first-1);
    }

  maxIndex = 0;
  maxDist = 0;
  vector<bool> visited (numNodes, false);
  updateDistances (maxIndex, distances, visited, graph);

  distances.clear();
  visited.clear();
  distances.resize(numNodes, 0);
  visited.resize(numNodes, false);
  updateDistances (maxIndex, distances, visited, graph);
  
  cout << maxDist << endl;

  return 0;
}

void updateDistances (int index, vector<unsigned int>& distances, vector<bool>& visited, const vector<vector<unsigned int> >& graph) {
  visited[index] = true;
  for (int counter = 0, end = graph[index].size(); counter < end; counter++) {
    int id = graph[index][counter];
    if (!visited[id]) {
      distances [id] = distances[index] + 1;
      if (distances[id] > maxDist) {
	maxIndex = id;
	maxDist = distances[id];
      }
      updateDistances (id, distances, visited, graph);
    }
  }
  
}

void printDistances (const vector<int>& distances){
  for (int counter = 0, size = distances.size(); counter < size; counter++)
    cout << distances[counter] << " ";
  cout << endl;
}
