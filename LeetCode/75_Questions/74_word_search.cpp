// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 18/02/2022

class TrieNode{
public:
    TrieNode *child[26];
    string s;
    
    TrieNode(){
        this->s = "";
        for(int i=0; i<26; i++) this->child[i] = NULL;
    }
};

class Solution {
    TrieNode *newNode;
    vector<string> ans;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    
    void insert(string word){
        TrieNode *t = newNode;
        for(auto w : word){
            if(!t->child[w-'a']) t->child[w-'a'] = new TrieNode();
            t = t->child[w-'a'];
        }
        t->s = word;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *t){
        
        char c = board[i][j];
        t = t->child[board[i][j] - 'a'];
        board[i][j] = '.';
        
        if(t->s != ""){
            ans.push_back(t->s);
            t->s = "";
        }
        
        for(int p=0; p<4; p++){
            int x=i+dx[p], y=j+dy[p];
            
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y] != '.' && t->child[board[x][y]-'a'])
                dfs(board, x, y, t);
        }
        board[i][j] = c;
		return;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        newNode = new TrieNode();
        
        for(auto word : words) insert(word);
        TrieNode *t = newNode;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(t->child[board[i][j]- 'a']) dfs(board, i, j, t); 
            }
        }
        return ans;
    }
};