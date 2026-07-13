class Solution {
public:
struct TrieNode
{
   TrieNode* left;
    TrieNode* right;
};
TrieNode* root;
void insert(TrieNode* root,int &x)
{
    TrieNode* crawl=root;
    for(int i=31;i>=0;--i)
    {
        int ithbit=(x>>i)&1;
        if(ithbit==1)
        {
            if(crawl->left==nullptr)
            crawl->left=new TrieNode();
            crawl=crawl->left;
        }
        else
        {
            if(crawl->right==nullptr)
            crawl->right=new TrieNode();
            crawl=crawl->right;
        }
    }
}
int find(TrieNode* root,int &x)
{
    int ans=0;
    TrieNode* crawler=root;
    
    for(int i=31;i>=0;--i)
    {
        int ithbit=(x>>i)&1;
        if(ithbit==0)
        {
            if(crawler->left!=nullptr)
            {
                ans |= (1 << i);
                crawler=crawler->left;
            }
            else
            crawler=crawler->right;
        }
        else
        {
            if(crawler->right!=nullptr)
            {
                ans |= (1 << i);
                crawler=crawler->right;
            }
            else
            crawler=crawler->left;
        }
    }
    return ans;
}
    int findMaximumXOR(vector<int>& a) {
       int mx=0,res=0;
       root=new TrieNode();
       int n=a.size();
       for(int x:a)
       insert(root,x);
       for(int i=0;i<n;++i)
       {
        res=find(root,a[i]);
        mx=max(mx,res);
       }
       return mx;
    }
};
