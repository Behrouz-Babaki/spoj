// problem 10380 -- prayatna PR -- Problem code: CAM5
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ios_base;
using std::vector;

void search (const vector<vector<int> >&, vector<int>&, vector<bool>&, int);
bool allInformed(const vector<bool>&);
void showRelations (const vector<vector<int> >& relations);

int bestNum;

int main (void) {
  ios_base::sync_with_stdio (false);

  int numberOfCases;
  cin >> numberOfCases;
  for (int caseCounter = 0; caseCounter < numberOfCases; caseCounter++){
    int numPeers;
    cin >> numPeers;
    bestNum = numPeers;

    vector<vector<int> > relations (numPeers, vector<int> ());
    vector<bool> informed (numPeers, false);
    vector<int> members;

    int numRelations;
    cin >> numRelations;

    for (int relationCounter = 0; relationCounter < numRelations; relationCounter++) 
      {
	int first, second;
	cin >> first >> second;
	relations[first].push_back(second);
	relations[second].push_back(first);
      }
    
    search (relations, members, informed, 0);
    members.push_back(0);
    informed[0] = true;
    search (relations, members, informed, 0);
    
    cout << bestNum << "\n";
  }
    
  return 0;
}


void search (const vector<vector<int> >& relations, vector<int>& members, vector<bool>& informed, int index) {
  if (members.size() >= bestNum)
    return;

  //propagate the news among friends
  if (informed[index])
    {
      for (vector<int>::const_iterator itr = relations[index].begin(), end = relations[index].end(); itr != end; itr++)
	informed [*itr] = true;
    }
  
  //get the next uninformed fellow
  index ++;
  while (index < relations.size() && informed[index])
    index++;
  
  if (index == relations.size()) {
    if (allInformed(informed) && bestNum > members.size())
      bestNum = members.size();
    return;
  }
  
  //branch over two possibilities
  //1- inform the guy:
  members.push_back(index);
  informed[index] = true;
  search (relations, members, informed, index);
  
  //2- leave the guy uninformed
  members.pop_back();
  informed[index] = false;

  index++;
  while (index < relations.size() && informed[index])
    index++;
  
  if (index == relations.size())
    return ;

  search (relations, members, informed, index);
}

bool allInformed(const vector<bool>& informed) {
  for (int counter = 0, size = informed.size(); counter < size; counter++)
    if (!informed[counter])
      return false;
  return true;
}


void showRelations (const vector<vector<int> >& relations) {
  cout << "relations:" << endl;
  for (int outer = 0; outer < relations.size(); outer++)
    {
      cout << outer << ": ";
      for (int inner = 0; inner < relations[outer].size(); inner++)
	cout << relations[outer][inner] << " ";
      cout << endl;
    }
}
