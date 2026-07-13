
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
//tc- since it can go till max height(height of max number), in that case, any number can be represented by log(n) bits
//max number can be represented in 32 bits
//TC= O(32*n) for inserting and finding for every index * n
//------------------------------------------------------------

    int findMaximumXOR(vector<int>& a) {
       int mx=0,ans=0;
      for(int i=31;i>=0;--i)
      {
        unordered_set<int>pref;
        for(int x:a)
        {
            pref.insert(x>>i);//storing prefixes of binary representation till that index
        }
        bool found=false;
        int candidate=(ans<<1)|1;//assuming we get one
        for(int p:pref)
        {
            if(pref.count(p^candidate))//a^b=c; a=b^c finding if it is possible to make candidate=1
            {
                found=true;
                break;
            }
        }
        if(found)//if possible
        ans=candidate;
        else
        ans=(ans<<1)|0;//otherwise add 0
      }
      return ans;
    }
//tc= O(32*n)= O(n)
