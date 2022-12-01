// link to problem: https://leetcode.com/problems/array-partition/

class Solution {
  public:
    int arrayPairSum(vector<int>& nums) {
      int sum = 0;
      sort(nums.begin, nums.end);
      for(int i = 0; i < nums.size() ; i+=2){
        sum += nums[i];
      }
      return sum;
    }
}

// link to LeetCode problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buy = INT_MAX , profit = 0, currentMax = 0;
      for(int i = 0 ; i < prices.size() - 1 ; i++) {
        if(prices[i] < buy) { buy = prices[i]; }
        profit = prices[i] - buy;
        if(profit > currentMax) { currentMax = profit; }
      } return currentMax;
    }
};
