
    int largestRectangleArea(vector<int>& a) 
    {
        int mx=0,n=a.size(),w=0;
        stack<int>st;
      for(int i=0;i<=n;++i)
      {
        while(!st.empty() && (i==n || a[st.top()]>a[i]))
        {
            int ele=a[st.top()];
            st.pop();
            if(!st.empty())
            w=i-st.top()-1;
            else
            w=i;
            mx=max(mx,ele*w);
        }
        st.push(i);
      }
      return mx;
    }
