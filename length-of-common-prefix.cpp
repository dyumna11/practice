class Solution {
public:
struct TrieNode
{
    TrieNode* children[10];
    bool endofnum;
    TrieNode()
    {
        for(int i=0;i<10;++i)
        children[i]=nullptr;
        endofnum=false;
    }
};
void insert(TrieNode* root,int x)
{
    TrieNode* crawler=root;
     string s=to_string(x);
       for(char c:s)
       {
        if(crawler->children[c-'0']==nullptr)
        crawler->children[c-'0']=new TrieNode();
        crawler=crawler->children[c-'0'];
       }
    crawler->endofnum=true;
}
int check(TrieNode* root,int n)
{
    int count=0;
     TrieNode* crawler=root;
    string s=to_string(n);//convert to string for easier execution
       for(char c:s)
       {
        if(crawler->children[c-'0']==nullptr)
        break;
        crawler=crawler->children[c-'0'];
         ++count;//just use count variable to inc
       }
    crawler->endofnum=true;
    return count;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root=new TrieNode();
        for(int x:arr1)
        insert(root,x);//insert arr1
        int mx=0;
        for(int x:arr2)
        mx=max(mx,check(root,x));//find max in arr2
        return mx;
    }
};
//tc=o(n+m)*digits, max in this case=10
//sc=o(n*d), d=10
