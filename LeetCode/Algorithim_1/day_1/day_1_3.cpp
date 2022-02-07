// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 05/02/2022

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int lo = 0, mid = nums.size()/2, hi = nums.size()-1;
        
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            
            if (nums[mid] == target) return mid;
            
            // Go Left
            if(nums[mid] > target){
                hi = mid - 1;
            }
            // Go Right 
            else if(nums[mid] < target){
                lo = mid + 1;
            }
        }
        return lo;
    }
    
};


// 2ND Solution took slighlty longer 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return dSearch(nums, target, 0, nums.size());
    }
    
    int dSearch(vector<int>& nums, int target, int lo, int hi){

        if(lo==hi) return lo;


        int mid = lo + (hi-lo)/2;

        if(nums[mid] == target) return mid;


        if(nums[mid]>target)
            return dSearch(nums, target, lo,mid);
        else
            return dSearch(nums,target,mid+1,hi);
    }
};

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4