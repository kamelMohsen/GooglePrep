// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 20/02/2022

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for (auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front(); q.pop(); numCourses--;
            for (auto next: adj[curr])
                if (--degree[next] == 0) q.push(next);
        }
        return numCourses == 0;
    }
};