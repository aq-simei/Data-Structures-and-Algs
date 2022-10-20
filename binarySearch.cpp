#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& array, int goal){
  int start = 0;
  int end = array.size() - 1;

  while(start <= end){
    int mid = (start + end) / 2;

    if(mid = goal){
      return mid; 
    }
    if(array[mid] < goal){
      start = mid + 1;
    }
    else {
      end = mid - 1; 
    }

    return -1; // when does not found the goal;
  }
}
