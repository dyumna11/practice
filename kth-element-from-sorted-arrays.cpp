
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
       priority_queue<int>pq;
       int l1=0,n=a.size(),m=b.size(),l2=0;
       int ans=0;
       while(l1<n && l2<m )
       {
           if(a[l1]<b[l2])
               ans=a[l1++];
           else
           ans=b[l2++];
          
           if(--k==0)
           return ans;
       }
    while(l1<n)
    { ans=a[l1++];
    
     if(--k==0)
           return ans;
        
    }
      while(l2<m)
      
    { ans=b[l2++];
   
     if(--k==0)
           return ans;
        
    }
       
return -1;
}
};
//tc=o(n+m)
------------------------------------------------

class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {

        int n = a.size();
        int m = b.size();

        if (n > m) //perform bs on smaller array
            return kthElement(b, a, k);

        
// cut1+cut2=k
//cut2=k-cut1
//cut1- elements taken from a, cut2= elements taken from b
//cut1<=n && cut2<=m
// k-cut1<=m, cut1>=k-m
//k-cut1>=0 , cut1<=k

//similar to median
        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1)// partition of size k
                return max(l1, l2);

            else if (l1 > r2)//we took more elements from a
                high = cut1 - 1;//move to cut1 to left

            else
                low = cut1 + 1;
        }

        return -1;
    }
};

//tc= o(log(min(n,m))
