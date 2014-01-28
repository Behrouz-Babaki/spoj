#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::ws;
using std::cerr;
using std::vector;
using std::priority_queue;

void find_mis(const vector<vector<unsigned int> >&, const vector<unsigned int>&);

int main(void){
  int num_cases;
  cin >> num_cases >> ws;
  if (!cin.good()){
    cerr << "Invalid number of cases." << endl;
    exit(EXIT_FAILURE);
  }
  
  for (int caseCounter = 0; caseCounter < num_cases; caseCounter ++){
    int num_vertices, num_edges;
    cin >> num_vertices >> ws >> num_edges >> ws;
    if (!cin.good()){
      cerr << "Error in reading the number of vertices/edges." << endl;
      exit(EXIT_FAILURE);
    }
    
    vector<unsigned int> weights(num_vertices, -1);
    for (int vCounter = 0; vCounter < num_vertices; vCounter++)
      cin >> weights[vCounter];

    vector<vector<unsigned int> > edges(num_vertices);
    for (int edgeCounter = 0; edgeCounter < num_edges; edgeCounter++){
      unsigned int firstVertex, secondVertex;
      cin >> firstVertex >> secondVertex >> ws;
      firstVertex --;
      secondVertex --;
      edges[firstVertex].push_back(secondVertex);
      edges[secondVertex].push_back(firstVertex);
    }
    find_mis(edges, weights);
  }

  return 0;
}

void find_mis(const vector<vector<unsigned int> >& edges, const vector<unsigned int>& w){
  priority_queue<unsigned int> weights (w.begin(), w.end());
}
