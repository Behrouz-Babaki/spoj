// problem 3377. A Bug's Life -- problem code: BUGLIFE
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
bool suspicious (const vector<vector<unsigned int> >&, const vector<int>&, int, vector<char>);

bool pairComp (const pair<int,int>& left, const pair<int, int>& right){ return left.second > right.second;}

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
	interactions[first-1].push_back(second-1);
	interactions[second-1].push_back(first-1);
      }

    vector<pair<int, int> > vecSizes (numBugs);
    for (int counter = 0; counter < numBugs; counter++)
      vecSizes[counter] = make_pair (counter, interactions[counter].size());
    
    sort (vecSizes.begin(), vecSizes.end(), pairComp);
    vector<int> order (numBugs);
    for (int counter = 0; counter < numBugs; counter++)
      order[counter] = vecSizes[counter].first;

    vector<char> sex(numBugs, 2);
    cout << "Scenario #" << caseCounter+1 << ":" << endl;
    sex[order[0]] = 0;
    if (!suspicious(interactions, order, 0, sex))
      cout << "No suspicious ";
    else
      {
	sex[order[0]] = 1;
	if (!suspicious(interactions, order, 0, sex))
	  cout << "No suspicious ";
	else 
	  cout << "Suspicious ";
      }
    cout << "bugs found!" << endl;
  }
  
  return 0;
}

void printInteractions (const vector<vector<unsigned int> >& interactions, const vector<pair<int,int> >& sizes) {
  for (vector<pair<int,int> >::const_iterator itr = sizes.begin(), end = sizes.end(); itr != end; itr++) {
    int idx = itr->first;
    cout << idx + 1 << ": ";
    for (vector<unsigned int>::const_iterator itr = interactions[idx].begin(); itr != interactions[idx].end(); itr++)
      cout << *itr+1 << " ";
    cout << endl;
  }
}

bool suspicious (const vector<vector<unsigned int> >& interactions, const vector<int>& order, int orderId , vector<char> sex) {
  int numBugs = interactions.size();
  int index = order[orderId];

  // check for inconsistencies
  vector<int> indices;
  for (vector<unsigned int>::const_iterator itr = interactions[index].begin() , end = interactions[index].end(); itr != end; itr++)
    if (sex[*itr] == sex[index]) {
      for (int i = 0, s = indices.size(); i < s; i++)
      	sex[indices[i]] = 2;
      return true;
    }
    else if (sex[*itr] == 2) {
      sex[*itr] = 1 - sex[index];
      indices.push_back(*itr);
    }

  orderId ++;
  if (orderId == numBugs)
    return false;
  
  index = order[orderId];
  if (sex[index] != 2) 
    return suspicious(interactions, order, orderId, sex);
    
 else {
   sex[index] = 0;
   if (!suspicious(interactions, order, orderId, sex)) {
     return false;
   }
   sex[index] = 1;
   if (!suspicious(interactions, order, orderId, sex)) {
     return false;
   }
 }
  
  for (int i = 0, s = indices.size(); i < s; i++)
    sex [indices[i]] = 2;
  return true; 
}
