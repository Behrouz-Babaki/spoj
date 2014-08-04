
// problem 18532. Tree _order -- Problem code: TREEORD
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ios_base;

bool checktree (vector<size_t> preorder, size_t pre_start, size_t pre_end, 
		vector<size_t> postorder, size_t post_start, size_t post_end,
		vector<size_t> inorder, size_t in_start, size_t in_end);

void printvec (const vector<size_t>& vec);

int main (void) {
  ios_base::sync_with_stdio (false);

  size_t numNodes;
  cin >> numNodes;
  vector<size_t> preorder (numNodes);
  vector<size_t> postorder (numNodes);
  vector<size_t> inorder (numNodes);

  for (int nodeCounter = 0; nodeCounter < numNodes; nodeCounter++) 
    cin >> preorder [nodeCounter];

  for (int nodeCounter = 0; nodeCounter < numNodes; nodeCounter++) 
    cin >> postorder [nodeCounter];

  for (int nodeCounter = 0; nodeCounter < numNodes; nodeCounter++) 
    cin >> inorder [nodeCounter];

  if (checktree(preorder, 0, numNodes-1,
		postorder, 0, numNodes-1,
		inorder, 0, numNodes-1))
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  return 0;
} 

bool checktree (vector<size_t> preorder, size_t pre_start, size_t pre_end, 
	       vector<size_t> postorder, size_t post_start, size_t post_end,
	       vector<size_t> inorder, size_t in_start, size_t in_end) {

  int pre_dif = pre_end - pre_start;
  int post_dif = post_end - post_start;
  int in_dif = in_end - in_start;
  
  if (pre_dif != post_dif || post_dif != in_dif ) {
    cout << "1 " << pre_start << "-" << pre_end<< " " << post_start << "-" << post_end << " " << in_start << "-" << in_end << endl;
    return false;
  }

  if (pre_dif == 0)
    return true;
  
  size_t parent = preorder[pre_start];
  size_t p_left = preorder [pre_start + 1];
  size_t p_right = postorder[post_end-1];

  bool found = false;
  size_t left_pre_end = 0;
  int counter;
  for (counter = pre_start + 1; !found && counter <=  pre_end; counter++)
    if (preorder[counter] == p_right) {
      left_pre_end = counter - 1;
      found = true;
    }

  if (!found) {
    cout << "2" << endl;
    return false;
  }
  
  found = false;
  size_t left_in_end = 0;
  for (counter = in_start; !found && counter <= in_end; counter++)
    if (inorder[counter] == parent) {
      left_in_end = counter - 1;
      found = true;
    }

  if (!found) {
    cout << "3" << endl;
    return false;
  }
  
  found = false;
  size_t left_post_end = 0;
  for (counter = post_start; !found && counter <= post_end; counter++)
    if (postorder[counter] == p_left) {
      left_post_end = counter;
      found = true;
    }

  if (!found) {
    cout << "4" << endl;
    return false; 
  }


  // parents should look the same
  if (preorder[pre_start] != inorder[left_in_end + 1] || preorder[pre_start] != postorder [post_end]) {
    cout << "5" << endl;
    return false;
  }
  
  if (!checktree (preorder, pre_start + 1, left_pre_end,
			 postorder, post_start, left_post_end, 
		  inorder, in_start, left_in_end))
    {
      cout << "6" << endl;
      return false;
    }

  if (pre_end >= left_pre_end + 1 && !checktree (preorder, left_pre_end + 1, pre_end,
	     postorder, left_post_end + 1, post_end - 1,
	     inorder, left_in_end + 2, in_end))
    {
      cout << "7" << endl;
      return false;
    }
  
  //both tests passed!
  return true;

}

void printvec (const vector<size_t>& vec) {
  for (int counter = 0, size = vec.size(); counter < size; counter++)
    cout << vec[counter] << " -- ";
}
