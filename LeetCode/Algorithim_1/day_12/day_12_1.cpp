// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 14/02/2022

class Solution {
public:
    int climbStairs(int n) {
        int count;
        vector<int> dp(n+1,-1);
        for(int i = 1 ; i<=n;i++){
            dp[i] = climbR(i,dp);
        }

        return dp[n];
    }
    int climbR(int n,vector<int> dp){
        if(dp[n]!=-1)
            return dp[n];
        if(n <= 0) return 1;
        int count = 0 ;
        
        if(n-1 >= 0)
        count += climbR(n-1,dp);
        if(n-2 >= 0)
            count += climbR(n-2,dp);
        return count;
    }
};



// 70. Climbing Stairs
// Easy

// 10381

// 318

// Add to List

// Share
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step