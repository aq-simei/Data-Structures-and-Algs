#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr){ // time: O(N²), space: O(1) using pointers
  for (int i = 0; i < arr.size(); i ++)
    for (int j = i + 1; j < arr.size(); j++){
      if (arr[i] > arr[j]){ 
        swap(arr[i], arr[j]);
    }
  }
}

void mergeTwoSortedArrays(vector<int>& firstArray, vector<int>& secondArray){ // O(N) => where N is the sum of the arrays sizes, time is O(1)
  vector<int>* result = {};
  for(int i = 0; i < firstArray.size();){
    for (int j = 0; j < secondArray.size();){
      if (firstArray[i] >= secondArray[j]){
        result -> push_back(secondArray[j]);
        j++;
      }
      else {
        result -> push_back(firstArray[i]);
        i++;
      }
    }
  }
}

void mergeSort(int * vector, int start, int end, int size){ // recursive merge sort O(N.log(N)) for time, space depends on the call stack
  int mid = (start + end) / 2;
  if(start < end){
    mergeSort( vector, start, mid, size );
    mergeSort( vector, mid + 1, end, size );
    merge( vector, start, mid, end);
  };
}

void merge(int *vet, int start, int mid, int end){ // merge sub arrays
  

  int firstArrayTracker, secondArrayTracker, originalArrayTracker;
  firstArrayTracker = start;
  secondArrayTracker = mid + 1;
  originalArrayTracker = 0;
  int * aux_vector = new int[mid];
  while(firstArrayTracker <= mid && secondArrayTracker <= end){

    if(vet[firstArrayTracker] < vet[secondArrayTracker]){
      aux_vector[originalArrayTracker] = vet[firstArrayTracker];
      firstArrayTracker++;
    } else{
      aux_vector[originalArrayTracker] = vet[secondArrayTracker];
      secondArrayTracker++;
    }
    originalArrayTracker++;
  }
}
