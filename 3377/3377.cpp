#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::pair;
using std::make_pair;

void printInteractions (const vector<vector<unsigned int> >&, const vector<pair<int, int> >&);

int main(void) {
  int numCases;
  cin >> numCases;
  for (int caseCounter = 0; caseCounter < numCases; caseCounter++) {
    int numBugs, numInteractions;
    cin >> numBugs >> numInteractions;
    vector<vector<unsigned int> > interactions (numBugs, vector<unsigned int>());
    for (int interactionCounter = 0; interactionCounter < numInteractions; interactionCounter++)
      {
	int first, second;
	cin >> first >> second;
	interactions[first-1].push_back(second);
	interactions[second-1].push_back(first);
      }

    vector<pair<int, int> > vecSizes (numBugs);
    for (int counter = 0; counter < numBugs; counter++)
      vecSizes[counter] = make_pair (counter, interactions[counter].size());
    
    sort (vecSizes.begin(), vecSizes.end(), [] (const pair<int,int>& left, const pair<int, int>& right){ return left.second > right.second;});
    printInteractions (interactions, vecSizes);
    cout << endl;
    
  }
  
  return 0;
}

void printInteractions (const vector<vector<unsigned int> >& interactions, const vector<pair<int,int> >& sizes) {
  for (auto itr = sizes.begin(), end = sizes.end(); itr != end; itr++) {
    int idx = itr->first;
    cout << idx + 1 << ": ";
    for (auto itr = interactions[idx].begin(); itr != interactions[idx].end(); itr++)
      cout << *itr << " ";
    cout << endl;
      }
}
