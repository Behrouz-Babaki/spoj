#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::ws;
using std::cerr;
using std::vector;
using std::set;
using std::max_element;

vector<unsigned long int> weights;
vector<vector<unsigned int> > edges;
unsigned long int global_best;

void search (const set<unsigned int>&, unsigned long int, unsigned long int);

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
    
    set<unsigned int> nodeIndices;
    weights.resize(num_vertices, -1);
    unsigned long int sum = 0;
    for (int vCounter = 0; vCounter < num_vertices; vCounter++){
      cin >> weights[vCounter];
      sum += weights[vCounter];
      nodeIndices.insert(vCounter);
    }

    edges.resize(num_vertices);
    for (int edgeCounter = 0; edgeCounter < num_edges; edgeCounter++){
      unsigned int firstVertex, secondVertex;
      cin >> firstVertex >> secondVertex >> ws;
      firstVertex --;
      secondVertex --;
      edges[firstVertex].push_back(secondVertex);
      edges[secondVertex].push_back(firstVertex);
    }
    
    global_best = 0;
    search (nodeIndices, 0, sum);
    cout << global_best << endl;
  }

  return 0;
}

void search (const set<unsigned int>& candidates, unsigned long int inWeightSum, unsigned long int candWeightSum){

  if (candidates.empty()){
    if (inWeightSum > global_best)
      global_best = inWeightSum;
    return;
  }
  
  set<unsigned int> cand (candidates);

  if (inWeightSum + candWeightSum > global_best){
    while (!cand.empty()){
      set<unsigned int>::iterator maxItr = cand.begin();
      unsigned long int max = weights[*(cand.begin())];
      for (set<unsigned int>::iterator itr = cand.begin(), endItr = cand.end(); itr != endItr; itr++)
        if (weights[*itr] > max){
          maxItr = itr;
          max = weights[*itr];
        }
      unsigned int nextNodeIndex = *maxItr;
      cand.erase(maxItr);
      candWeightSum -= weights[nextNodeIndex];
      unsigned long int partial = inWeightSum + weights[nextNodeIndex];
      
      // You gotta be kidding me!
      set<unsigned int> cand2 (cand);
      for (vector<unsigned int>::iterator itr = edges[nextNodeIndex].begin() , endItr = edges[nextNodeIndex].end();
           itr != endItr; itr++)
        cand2.erase(*itr);

      search(cand2, partial, candWeightSum);
    }
  }
    return;
}

