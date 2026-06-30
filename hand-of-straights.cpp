//using pq
    bool isNStraightHand(vector<int>& a, int gpsize) {
       if(a.size()%gpsize!=0)
       return false;
       int c=0;
       unordered_map<int,int>m;
       int n=a.size(),l=0;
       int div=n/gpsize;
       priority_queue<int,vector<int>,greater<int>>pq;
       for(auto i:a)
      {
        ++m[i];
        if(m[i]==1)
        pq.push(i);
      }
      while(!pq.empty())
      {
        int start=pq.top();
       for(int i=0;i<gpsize;++i)
       {
        int card=i+start;
        if(m[card]==0)
        return false;
        m[card]--;
        if(m[card]==0)
        {
            if(pq.top()!=card)
            return false;
        
        pq.pop();
       }
       }
      }
       return true;
      }
//-----------------------------------------------------------
//using map

    bool isNStraightHand(vector<int>& a, int gpsize) {
       if(a.size()%gpsize!=0)
       return false;
       int c=0;
      map<int,int>m;
       int n=a.size(),l=0;
      
       for(auto i:a)
      {
        m[i]++;
      }
      while(!m.empty())
      {
          int start=m.begin()->first;
       for(int i=0;i<gpsize;++i)
       {
      
        int card=start+i;
        if(m.count(card)==0)
        return false;
        m[card]--;
        if(m[card]==0)
            m.erase(card);
       }
      }
       return true;
      }
