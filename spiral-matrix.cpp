
        vector<int> ans;
      
        int n=a.size(),m=a[0].size();
          int left=0,right=m-1,top=0,down=n-1;
        while(left<=right && top <=down)
        {
            if(top<=down)
            {
        for(int i=left;i<=right;++i)
        {
            ans.push_back(a[top][i]);
        }
            
        ++top;
            }
            if(left<=right)
            {
        for(int i=top;i<=down;++i)
        {
            ans.push_back(a[i][right]);
        }
        --right;
            }
            if(top<=down)
            {
        for(int i=right;i>=left;--i)
        {
              ans.push_back(a[down][i]);
        }
        --down;
        }
        if(left<=right)
        {
         for(int i=down;i>=top;--i)
        {
            ans.push_back(a[i][left]);
        }
        ++left;
        }
        }
    
        return ans;
    }
