// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 20/02/2022

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) 
            freq[num]++;
        
        vector<vector<int>> buckets(nums.size());
        for (auto [a, b] : freq)
            buckets[b-1].push_back(a);
        
        vector<int> res;
        for (int i = nums.size()-1; k>0; i--) {
            for (auto a : buckets[i]) {
                res.push_back(a);
                k--;
            }
        }
        
        return res;
    }
};