class Solution {
public:
struct TrieNode
{
    TrieNode* left;
    TrieNode* right;
    TrieNode()
    {
        left=nullptr;
        right=nullptr;
    }
};
TrieNode* root = new TrieNode();
void insert(int a)
{
    TrieNode* crawler=root;
    for(int i=31;i>=0;--i)
    {
        int ithbit=(a>>i)&1;
        if(ithbit==1)
        {
            if(crawler->right==nullptr)
            crawler->right=new TrieNode();
            crawler=crawler->right;
        }
        else
        {
            if(crawler->left==nullptr)
            crawler->left=new TrieNode();
            crawler=crawler->left;
        }
    }
    
}
int findmax(int a)
{
    TrieNode* crawler=root;
    int ans=0;
    
    for(int i=31;i>=0;--i)
    {
         int ithbit=(a>>i)&1;
         if(ithbit==0)
         {
            if(crawler->right!=nullptr)
            {
            ans |= (1 << i);
            crawler=crawler->right;
            }
            else
            crawler=crawler->left;
         }
         else
         {
            if(crawler->left!=nullptr)
            {
            ans |= (1 << i);
            crawler=crawler->left;
            }
            else
            crawler=crawler->right;
         }
    }
    return ans;
}
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
vector<int> ans(queries.size(), -1);
                 vector<vector<int>> offline;
              sort(nums.begin(), nums.end());   
 for (int i = 0; i < queries.size(); i++) {
            offline.push_back({queries[i][1], queries[i][0], i});
        }   
        sort(offline.begin(), offline.end());  
        int j=0;
         for(auto a:offline)
         {
            int m=a[0];
            int x=a[1];
            int idx=a[2];
            
            while(j<n && nums[j]<=m)
            {
                insert(nums[j]);
                j++;
            }
            if(j==0)
            ans[idx]=-1;
            else
            ans[idx]=findmax(x);
           
         }
         return ans;
    }
};
