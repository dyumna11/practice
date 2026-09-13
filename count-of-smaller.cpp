class Solution {
public:
 vector<int>tree;
int query(int l,int r,int ql,int qr,int node)
{
    if(l>qr || r<ql)
    return 0;
    if(l>=ql && r<=qr)
    return tree[node];
    int m=(l+r)/2;
    return query(l,m,ql,qr,2*node+1)+query(m+1,r,ql,qr,2*node+2);
}
void update(int l,int r,int node,int i)
{
    if(l==r)
    {
        tree[node]++;//marks freq of element
        return;
    }
     int m=(l+r)/2;
    if(i<=m)
    update(l,m,2*node+1,i);
    else
    update(m+1,r,2*node+2,i);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
    vector<int> countSmaller(vector<int>& a) {
         int n=a.size();
        vector<int> ans(n);
         
      
       vector<int> v = a;
sort(v.begin(), v.end());
v.erase(unique(v.begin(),v.end()),v.end());//remove duplicates
       int sz=v.size();
        tree.resize(4*sz,0);
        for(int i=n-1;i>=0;--i)
        {
            //finding the index that it will be present in after sorting
            //compressing
            int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            //checking how many numbers lie before pos-1
            //eg if for 5,2,6,1--> 1,2,5,6
            //a[i]=5, pos=2
            //check elements in 0 and 1
           ans[i]=query(0,sz-1,0,pos-1,0);
           update(0,sz-1,0,pos);
        }
        return ans;
    }
};
