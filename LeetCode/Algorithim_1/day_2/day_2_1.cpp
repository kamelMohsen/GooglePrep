// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 05/02/2022

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squaresArray(nums.size());
        int i=0,j=nums.size()-1,c=nums.size()-1;
        int sq1 = 0, sq2 = 0;
        while(c>=0){
            sq1 = nums[i]*nums[i];
            sq2 = nums[j]*nums[j];
            if(sq1>=sq2){
                squaresArray[c--] = sq1; 
                i++;
            }else{
                squaresArray[c--] = sq2; 
                j--;
            }
        }
        return squaresArray;
    }

};



// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]