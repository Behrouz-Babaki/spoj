// problem 10380 -- prayatna PR -- Problem code: CAM5
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ios_base;
using std::vector;

void mark (int, const vector<vector<int> >&, vector<bool> &);

int main (void) {
  ios_base::sync_with_stdio (false);

  int numberOfCases;
  cin >> numberOfCases;
  for (int caseCounter = 0; caseCounter < numberOfCases; caseCounter++){
    int numPeers;
    cin >> numPeers;

    vector<vector<int> > relations (numPeers, vector<int> ());
    vector<bool> marked (numPeers, false);

    int numRelations;
    cin >> numRelations;

    for (int relationCounter = 0; relationCounter < numRelations; relationCounter++) 
      {
	int first, second;
	cin >> first >> second;
	relations[first].push_back(second);
	relations[second].push_back(first);
      }

    int numInformed = 0;
    for (int peerCounter = 0; peerCounter < numPeers; peerCounter++)
      if (!marked[peerCounter]) {
	mark (peerCounter, relations, marked);
	numInformed++;
      }
    
    cout << numInformed << "\n";
  }
    
  return 0;
}


void mark (int index, const vector<vector<int> >& relations, vector<bool> & marked) {
  marked[index] = true;
  for (int friendCounter = 0, last = relations[index].size(); friendCounter < last; friendCounter++)
    if (!marked[relations[index][friendCounter]])
      mark(relations[index][friendCounter], relations, marked);
}

