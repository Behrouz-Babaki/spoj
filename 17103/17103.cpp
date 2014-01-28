#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::set_intersection;
using std::vector;

int main(void){
  vector<int> first, second, third;
  int count;

  cin >> count;
  first.reserve(count);
  for (int counter = 0; counter < count; counter++){
    int val;
    cin >> val;
    first.push_back(val);
  }

  cin >> count;
  second.reserve(count);
  for (int counter = 0; counter < count; counter++){
    int val;
    cin >> val;
    second.push_back(val);
  }
    
  third.resize(min(first.size() , second.size()));
  vector<int>::iterator itr;
  itr = set_intersection(first.begin(), first.end(), 
    second.begin(), second.end(), third.begin());
  third.resize(itr - third.begin());

  for (int counter = 0, size = third.size(); counter < size; counter++)
    cout << third[counter] << " ";
  cout << endl;

  return 0;
}
