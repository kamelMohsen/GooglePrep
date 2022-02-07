// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 07/02/2022

class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j=0;
        string ans ="";
        while(i<s.size()){
            j = getFWS(s,i);
            i = j+1;
            while(j>0 && s[j-1]!=' ')
                ans += s[--j];
            if(i<s.size())
                ans+=" ";
        }
        return ans;
    }
    int getFWS(string s, int start){//get First White-Space
        for(int i = start ; i<s.size(); i++)
        {
           if(s[i]==' ') return i;
        }
        return s.size();
    }
};

// 2ND Solution a lot faster

class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == ' ') {
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
            }
        }
        reverse(s.begin()+i, s.end());
        return s;
    }

};

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"