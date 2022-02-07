// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 07/02/2022

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return;
        int FNZ;
        for(int i = 0 ; i < nums.size();i++){
            FNZ = getFNZ(nums,i);
            if (FNZ == -1 || FNZ < i) return;
            if(nums[i] == 0){
                swap(nums[i],nums[FNZ]);
            }
  
        }
    }
    int getFNZ(vector<int> &nums, int start){//get First Non-Zero
        for(int i = start ; i<nums.size(); i++)
        {
           if(nums[i]!=0) return i;
        }
        return -1;
    }
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};



// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
