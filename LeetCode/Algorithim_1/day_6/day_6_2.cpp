// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 08/02/2022

class Solution {
public:
bool checkInclusion(string s1, string s2) {
        int m = s1.length(),n = s2.length();
        if(m>n)return false;
        vector<int>maps1(26),maps2(26);
        for(int i=0;i<m;i++)
        {
            maps1[s1[i] - 'a'] ++;
            maps2[s2[i] - 'a'] ++;
        }
        if(maps1 == maps2) return true; 
        for(int i = 0;i+m<n;i++)
        {
             maps2[s2[i] - 'a'] --;
             maps2[s2[i+m] - 'a'] ++;
             if(maps1 == maps2) return true;
        }
        return false;
    }
};