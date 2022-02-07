// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 05/02/2022

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return dSearch(nums,target,0,nums.size()-1);
    }
    int dSearch(vector<int>& nums, int target, int lo, int hi){

        if(lo>=hi) return nums[lo] == target ? lo:-1;

                
        int mid = lo + (hi-lo)/2;
        
        if(nums[mid] == target) return mid;
        
        
        if(nums[mid]>target)
            return dSearch(nums, target, lo,mid);
        else
            return dSearch(nums,target,mid+1,hi);
    }
};



// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 
