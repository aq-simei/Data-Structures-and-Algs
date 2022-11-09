class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    // could we use a heap in order to remove the biggest values?
    priority_queue<vector<int>> pointsDataHeap; // heap of vectors
    // build points heap
    for (int i = 0; i < points.size(); i++) // N times
    {
      int x = points[i][0], int y = points[i][1]; // get coordinates of point [i]

      pointsDataHeap.push({x * x + y * y, x, y}); // O(log n)

      if (pointsDataHeap.size() > k)
      { // we are getting more points than necessary
        // so we can delete the biggest one of them
        pointsDataHeap.pop();     // O(log n);
      }
    }
  }
  vector<vector<int>> result;

  for (int i = 0; i < k; i++)
  {
    vector<int> biggestPoint = pointsDataHeap.top(); // biggest point on the heap
    pointsDataHeap.pop();
    result.push_back({biggestPoint[1], biggestPoint[2]}); // our return has the size of k
  }
  return result;
  // complexities: O(n log n) for time and O(K) for space
};
