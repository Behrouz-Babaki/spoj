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

struct Node{
  unsigned int vIndex;
  unsigned int weight;
};

vector<unsigned int> weights;
vector<vector<unsigned int> > edges;
double global_best;

void search (const vector<Node>&, const vector<Node>&, double, double);

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
    
    vector<Node> nodes(num_vertices);
    weights.resize(num_vertices, -1);
    double sum = 0;
    for (int vCounter = 0; vCounter < num_vertices; vCounter++){
      cin >> weights[vCounter];
      Node current_node;
      current_node.vIndex = vCounter;
      current_node.weight = weights[vCounter];
      sum += current_node.weight;
      nodes.push_back(current_node);
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
    vector<Node> init;
    search (init, nodes, 0, sum);
    cout << global_best << endl;
  }

  return 0;
}

void search (const vector<Node>& in_set, const vector<Node>& candidates, double inWeightSum, double candWeightSum){

  if (candidates.empty()){
    if (inWeightSum > global_best)
      global_best = inWeightSum;
    return;
  }
  
  vector<Node> cand (candidates);

  if (inWeightSum + candWeightSum > global_best){
    vector<Node> in (in_set);
    while (!cand.empty()){
      Node nextNode = cand.back();
      cand.pop_back();
      in.push_back(nextNode);
      candWeightSum -= nextNode.weight;
      double partial = inWeightSum + nextNode.weight;
      //This is crazy! Why are we copying this everywhere?
      vector<Node> cand2 (cand);
      //TODO remove those nodes from cand2 which are adjacent to nextNode
      search(in, cand2, partial, candWeightSum);
      in.pop_back();
    }
  }
    return;
}

