class Solution {
public:
struct TrieNode
{
    TrieNode* children[2];
    int count;
    TrieNode()
    {
        children[0] = children[1] = nullptr;
        count=0;
    }
};
TrieNode* root=new TrieNode();
void remove(int x)
{
    TrieNode* curr=root;
    for(int i=30;i>=0;--i)
    {
        int ithbit=(x>>i)&1;
        curr=curr->children[ithbit];
        curr->count--;
    }
}
void insert(int x)
{
    TrieNode* curr=root;
    for(int i=30;i>=0;--i)
    {
        int ithbit=(x>>i)&1;
        if(curr->children[ithbit]==nullptr)
        {
            curr->children[ithbit]=new TrieNode();
           
            
        }
         curr=curr->children[ithbit];
       curr->count++;
    }
}
int maxxor(int x)
{
    long long ans=0;
    TrieNode* curr=root;
    for(int i=30;i>=0;--i)
    {
        long long ithbit=(x>>i)&1;
        int opp=1-ithbit;
        if(curr->children[opp] && curr->children[opp]->count>0)
        {
            ans|=(1<<i);
            curr=curr->children[opp];
        }
        else
        {
           curr=curr->children[ithbit];
        }
    }
    return ans;
    
}
    int maximumStrongPairXor(vector<int>& a) {
        // x-y<=min(x,y)
        //let x<=y
        //x-y<=x; y<=2*x
        sort(a.begin(),a.end());
        int left=0,mx=0;
        for(int right=0;right<a.size();++right)
        {
            insert(a[right]);
            while(a[right]>2*a[left])//invalid
            {
                remove(a[left]);
                ++left;
            }
            mx=max(mx,maxxor(a[right]));
           
        }
        return mx;
    }
};
