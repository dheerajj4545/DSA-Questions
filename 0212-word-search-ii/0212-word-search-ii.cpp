class Solution {
public:
    struct Node{
        Node*child[26];
        string word;

        Node(){
            word="";
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    int m;
    int n;
    vector<string>ans;

    void dfs(vector<vector<char>>& board,int r,int c,Node*node){
        if(r<0||r>=m||c<0||c>=n) return;

        char ch=board[r][c];
        if(ch=='#'||node->child[ch-'a']==NULL) return;

        node=node->child[ch-'a'];
        if(node->word!=""){
            ans.push_back(node->word);
            node->word="";
        }
        board[r][c]='#';
        dfs(board,r+1,c,node);
        dfs(board,r-1,c,node);
        dfs(board,r,c+1,node);
        dfs(board,r,c-1,node);

        board[r][c]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();

        Node*root=new Node();
        for(string word:words){
            Node*curr=root;
            for(char ch:word){
                int idx=ch-'a';
                if(curr->child[idx]==NULL){
                    curr->child[idx]=new Node();
                }
                curr=curr->child[idx];
            }
            curr->word=word;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root);
            }
        }
        return ans;
    }
};