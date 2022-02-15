// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 14/02/2022

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> temp;
        getCombinations(combinations,n,1,k,temp);
        return combinations;
    }
    void getCombinations(vector<vector<int>> &combinations,int n,int i,int k,vector<int> temp){
        if(temp.size()==k)
        {
            combinations.push_back(temp);
            return;
        }
        for(int j = i; j < n+1 ; j++){
            temp.push_back(j);
            getCombinations(combinations,n,j+1,k,temp);
            temp.pop_back();
        }
    }
};



// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]