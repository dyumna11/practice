
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
         vector<int>ans;
         int n=s.size();
         vector<pair<pair<int,int>,int>>meeting;
        for(int i=0;i<n;++i)
        {
            meeting.push_back({{f[i],s[i]},i+1});
        }
        sort(meeting.begin(),meeting.end());
        int lastfin=-1;
        for(auto m:meeting)
        {
            int finish=m.first.first;
            int start=m.first.second;
            int ind=m.second;
            if(start>lastfin)
            {
                ans.push_back(ind);
                lastfin=finish;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
