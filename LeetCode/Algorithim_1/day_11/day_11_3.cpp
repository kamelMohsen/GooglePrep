// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 14/02/2022

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s,0,ans);
        return ans;
    }
    
    void solve(string &s,int indx,vector<string> &ans){
        if(indx>=s.size()){
            ans.push_back(s);
            return;
        }
        
        char temp = s[indx];
        s[indx] = islower(temp) ? toupper(temp) : tolower(temp);
        solve(s,indx+1,ans);
        if(isalpha(temp)){
            s[indx] = temp;
            solve(s,indx+1,ans); 
        }
    }
};


// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]