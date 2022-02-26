/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> visited;
        return node ? dfs(node, visited):nullptr;
    }
    
    Node* dfs(Node* root,map<int, Node*> &visited){
        visited[root->val] = new Node(root->val);
        for(auto neighbor : root->neighbors){
            if(!visited[neighbor->val]){
                visited[root->val]->neighbors.push_back(dfs(neighbor, visited)); 
            }else{
                visited[root->val]->neighbors.push_back(visited[neighbor->val]);   
            }
        }

        return visited[root->val];
    }
};