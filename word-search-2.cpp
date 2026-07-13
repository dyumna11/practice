class Solution {
public:
vector<string> ans;
int n,m;
vector<pair<int,int>> dir = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
struct trieNode
{
    bool endofword;
    trieNode* children[26];
    string word;
};
trieNode* get()
{
    trieNode* newnode= new trieNode();
    newnode->endofword=false;
    newnode->word="";
    for(int i=0;i<26;++i)
    newnode->children[i]=nullptr;
    return newnode;
}
void insert(trieNode* root,string &word)
{
    trieNode* crawler=root;
    for(int i=0;i<word.size();++i)
    {
        char ch=word[i];
        if(crawler->children[ch-'a']==NULL)
        crawler->children[ch-'a']=get();
        crawler=crawler->children[ch-'a'];

    }
    crawler->endofword=true;
    crawler->word=word;
}
void findword(vector<vector<char>>& board, int i,int j,trieNode* root)
{
    if(i<0 || i>=n || j<0 || j>=m)
    return;
    if(board[i][j]=='$' || root->children[board[i][j]-'a']==nullptr)
    return;
    root=root->children[board[i][j]-'a'];
    if(root->endofword)
    {
        ans.push_back(root->word);
        root->endofword=false;
    }
    char temp=board[i][j];
    board[i][j]='$';
    for(auto d:dir)
    {
        int nr=i+d.first;
        int nc=j+d.second;
        findword(board,nr,nc,root);
    }
    board[i][j]=temp;
}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size(),m=board[0].size();
        trieNode* root=get();
        for(string &word:words)
        {
            insert(root,word);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL)
                findword(board,i,j,root);
            }
        }
        return ans;
    }
};
