// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 07/02/2022

class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {

        int gcd_ = gcd(nums.size(),k);
        for (int n = 0; n<gcd_; n++){
            int i = n;
            int temp = nums[n];
            int temp2 = temp;
            while(((i+k)%nums.size())!=n){
                temp2 = nums[(i+k)%nums.size()]; 
                nums[(i+k)%nums.size()] = temp;
                temp = temp2;
                i = (i+k)%nums.size();
            }
            nums[n] = temp;                
        }
    }
    int gcd(int a, int b){
        if (b==0) return a;        
        return gcd(b,a%b);
    }
};



// Given an array, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]