// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 07/02/2022

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0,j=0;
        while(i<numbers.size()){
            j = findBS(numbers,i,numbers.size()-1,target-numbers[i]);
            if (j!=-1)
                break;
            i++;
        }
        if(i==j)
            return vector<int> {i+1,j+2};
        return vector<int> {i+1,j+1};
    }
    
    int findBS(vector<int>& numbers, int lo, int hi, int target){
        if (lo>=hi) return numbers[lo]==target ? lo:-1;
        int mid = lo +(hi-lo)/2;
        if(numbers[mid]==target) return mid;
        if(numbers[mid]>target)
            return findBS(numbers,lo,mid-1,target);
        else
            return findBS(numbers,mid+1,hi,target);
    }
};

// 2ND Solution took almost the same

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0 ;
        int j = numbers.size()-1;
        vector<int> ans;
        while(i<j){
            if(numbers[i] + numbers[j] == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
                    
            }else{
                i++;
            }
                
        }
        return ans;
    }
    

};


// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

 

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
// Example 2:

// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
// Example 3:

// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].