#include <iostream>
#include <vector>
using namespace std;


void addNumber(int *number){
  *number = *number + 1;
  return;
}

// O(1) for time and O(1) for space

int main(){
  int number = 9999;
  addNumber(&number);
  cout << number << endl;
  return number;
}

void addNumberFour(vector<int> arrayOfNumbers){
  arrayOfNumbers.push_back(4);
  return;
}



int sumAllValues(vector<int> arrayOfNumbers){
  int actualSum = 0;

  //When we start to analyze our function bellow, it's iterations depends on the size of the array, so it is O(n) for time
  // as our functions does need extra space for memory regarding the array size for execution, it is O(1) for space
  // solution: O(N) for time and O(N) for space (constant) => returns 6 for the initial array
  for(int i = 0; i < arrayOfNumbers.size(); i++) {
    actualSum += arrayOfNumbers[i];
  };
  return actualSum;
}

int sumAllValues(vector<int> numberArr) {
  int actualSum = 0; //const = 1, 1 rep for exec;
  for(int i = 0; i < numberArr.size()/2 ; i++){ // const = N, 1 rep for each pair of elements on the array (N/2); O(N/2) => O(N)
    actualSum += numberArr[i]; //const = 1, 1 rep for each element on the array (N);
  }
  cout << actualSum << endl;
  return actualSum;
}

vector<int> getTheArray() {
  vector<int> arrayOfNumbers = {1, 2, 3, 4}; //const = 1, 1 rep for each element on the array (N);
  cout << sumAllValues(arrayOfNumbers);
  return arrayOfNumbers;
}

int main(){
  getTheArray();
  return 0;
}
//solution => O(N) for time and O(N) for space (variates alongside the array size);

// G)

int sumAllValues(vector<int> numberArr) {
  int actualSum = 0;
  for(int i = 0; i < numberArr.size()/2; i++){ 
    for(int j = 0; j < numberArr.size()/2; j++){
      if(true){
        actualSum = actualSum;
      };
    };
    actualSum += numberArr[i];
  };
  return actualSum;
}

vector<int> getTheArray() {
  vector<int> numbersArray = { 1, 2, 4, 5, 6, 7 };
  cout << sumAllValues(numbersArray);
  return numbersArray;
}

int main(){
  getTheArray();
  return 0 ;
}

