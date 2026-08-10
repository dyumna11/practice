class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>mp;
        for(int i=0;i<req_skills.size();++i)
        {
            mp[req_skills[i]]=i;//assigned numbers to each skills string
        }
        vector<int> peoplemsk(people.size(), 0);
        int m=people.size();
        for(int i=0;i<people.size();++i)
        {
            for(auto skill:people[i])
            {
                peoplemsk[i] |= (1 << mp[skill]);//used to create a mask
                //by using or gate, which will add results for each person
                //so we know for each person his/her skills
            } 
        }
        int n=req_skills.size();
        vector<vector<int>> dp(1 << n);
        // dp[mask] = smallest team producing mask
        for(int i=0;i<m;++i)
        {
            auto old=dp;
            for(int msk=0;msk<(1<<n);++msk)
        {
             if (old[msk].empty() && msk != 0)
                    continue;
                     // Add person i
            int newmsk=msk|peoplemsk[i];
            //if no skill added
            if (newmsk == msk)
                    continue;
            if (dp[newmsk].empty() ||
                    dp[newmsk].size() > old[msk].size() + 1) {
//we have to find smallest size that we can get
                    dp[newmsk] = old[msk];
                    dp[newmsk].push_back(i);
        }
        }
        }
        
return dp[(1<<n)-1];
    }
};
//Time: O(S + m·2ⁿ), Space: O(n·2ⁿ), where n is the number of required skills, m is the number of people, and S is the total number of listed skills.
