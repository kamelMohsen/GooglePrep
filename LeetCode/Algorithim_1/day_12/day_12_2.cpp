// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 14/02/2022

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[nums.size()-1] = nums[nums.size()-1];
        dp[nums.size()-2] = nums[nums.size()-2];
        dp[nums.size()-3] = nums[nums.size()-3] + nums[nums.size()-1];
        for(int i = nums.size()-4 ; i >= 0 ; i--){
            dp[i] = max(dp[i+2],dp[i+3]) + nums[i];           
        }
        
        return max(dp[0],dp[1]);
    }
};




// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.