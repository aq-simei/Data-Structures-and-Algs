#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// exercise statement : https://leetcode.com/problems/last-stone-weight/

int lastStone(vector<int> stones)
{
  priority_queue<int> stonesHeap(stones.begin(), stones.end()); // TIME: O(n), space: O(N)
  int first_stone, second_stone, to_add_stone;          // should initialize these variables (in case we do a sum)

  if (stonesHeap.size() == 1)
  {
    return stonesHeap.top();
  }

  while (stonesHeap.size() > 1) // O(n.log(n))
  {
    first_stone = stonesHeap.top();  // O(1)
    stonesHeap.pop();                // O(log n)
    second_stone = stonesHeap.top(); // second only => heads up at the session
    stonesHeap.pop();                // O(1)

    if (first_stone != second_stone)
    {
      to_add_stone = first_stone - second_stone;
      stonesHeap.push(to_add_stone); // O(log n)
    };
  };

  return 0;
  // => results in O(N.log(n))
};

struct point { // clarify question => whats is the nature of my coordinates (x, y)? -> integers, decimals ,...
  float x;
  float y;
};
