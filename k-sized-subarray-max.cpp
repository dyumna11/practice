 vector<int> maxOfSubarrays(vector<int>& a, int k) {
        // code here
        int l=0;
        vector<int>ans;
        int n=a.size();
        deque<int>dq;
        for(int i=0;i<n;++i)
        {
            while(!dq.empty() && dq.front()<=i-k)//[i-k+1...i] window size, eliminate all those before that
            dq.pop_front();
            while(!dq.empty() && a[dq.back()]<a[i]) //remove smaller elements
            dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)//this is for the first window, keep adding elements till there are k present
              //[i-k+1...i], so length= i-(i-k+1)=k-1
            ans.push_back(a[dq.front()]);//greatest element at front
            
        }
        return ans;
    }
//tc= o(n) deque each operation takes o(1)
//sc= o(k) size of deque
