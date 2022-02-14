// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 07/02/2022

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> m;
        int max = -99999;
        int i = 0,j=0; 
        while(i<s.size() && j<s.size()){
            if(m[s[j]]==false){
                m[s[j]] = true;
                j++;
                if(j-i > max) max = j-i; 
            }
            else{
                m[s[i]] = false;
                i++;
            }
        }
        return max<0 ? 0:max;
            
    }
};


// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.