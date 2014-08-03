#include <stdio.h>

char* strg = "ALLIZZWELL";
int nRows;
int nCols;
int IzzAllWell (char** matrix, char** used, int nRows, int nCols);
int search (char** matrix, char** used, int x, int y, int position);

int main(void) {
  int nCases;
  scanf("%d\n", &nCases);
  int counter;
  for (counter = 0; counter < nCases; counter++) {
    scanf("%d %d\n", &nRows, &nCols);
    char strs [nRows][nCols+1];
    char* matrix [nRows];
    char used_ [nRows][nCols];
    char* used [nRows];
    int rowCounter, colCounter;
    for (rowCounter = 0; rowCounter < nRows; rowCounter++) {
      scanf("%s\n", strs[rowCounter]);
      matrix[rowCounter] = &strs[rowCounter][0];

      for (colCounter = 0; colCounter < nCols; colCounter++)
	used_[rowCounter][colCounter] = 0;
      used[rowCounter] = &used_[rowCounter][0];
    }

    if (IzzAllWell(matrix, used, nRows, nCols))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

int IzzAllWell (char** matrix, char ** used, int nRows, int nCols) {
  int rowCounter, colCounter;
  for (rowCounter = 0; rowCounter < nRows; rowCounter++)
    for (colCounter = 0; colCounter < nCols; colCounter++)
      if (matrix[rowCounter][colCounter] == 'A' && search (matrix, used, colCounter, rowCounter, 0))
	return 1;

  return 0;
}

int search (char** matrix, char** used, int x, int y, int position) {
  if (position == 9)
    return 1;

  used[y][x] = 1;
  
  if (x-1 >= 0){
    if (y-1 >= 0 && matrix[y-1][x-1] == strg[position+1] && !used[y-1][x-1])
      if (search(matrix, used, x-1, y-1, position+1))
	return 1;
    if (matrix[y][x-1] == strg[position+1] && !used[y][x-1])
      if (search(matrix ,used, x-1, y , position+1))
	return 1;
    if ((y+1 < nRows) && matrix[y+1][x-1] == strg[position+1] && !used[y+1][x-1])
      if (search(matrix, used, x-1, y+1, position+1))
	return 1;
  }

  if ((y-1 >= 0) &&  matrix[y-1][x] == strg[position+1] && !used[y-1][x])
    if (search(matrix, used, x, y-1, position+1))
      return 1;

  if ((y+1 < nRows) && matrix[y+1][x] == strg[position+1] && !used[y+1][x])
    if (search(matrix, used, x, y+1, position+1))
      return 1;

  if (x+1 < nCols) {
    if ((y-1 >= 0) && matrix[y-1][x+1] == strg[position+1] && !used[y-1][x+1])
      if (search(matrix, used, x+1, y-1, position+1)) 
	return 1;
    if (matrix[y][x+1] == strg[position+1] && !used[y][x+1])
      if (search(matrix ,used,  x+1, y  , position+1))
	return 1;
    if ((y+1 < nRows)  && matrix[y+1][x+1] == strg[position+1] && !used[y+1][x+1])
      if (search(matrix, used, x+1, y+1, position+1)) 
	return 1;
  }

  used[y][x] = 0;

  return 0;
}
