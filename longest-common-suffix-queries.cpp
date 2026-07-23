class Solution {
public:
struct TrieNode{
    TrieNode* children[26];
    bool endofword;
    int index;//keep index to know which ans to be stored
    TrieNode()
    {
        for(int i=0;i<26;++i)
        children[i]=nullptr;
        endofword=false;
        index=0;
    }
    ~TrieNode() {//destructor is req otherwise it gives mle
        for (int i = 0; i < 26; ++i)
            delete children[i];
    }
};
void insert(string &word,TrieNode*root,int index,vector<string>& wordsContainer)//since we are finding suffix
{
    TrieNode*crawler=root;
    int n=word.size();
    for(int i=n-1;i>=0;--i)//insert from last word in the trie
    {
        char c=word[i];
        if(crawler->children[c-'a']==nullptr)
        {
        crawler->children[c-'a']=new TrieNode();
        crawler->children[c-'a']->index = index;
    }
        crawler=crawler->children[c-'a'];
       if (n < wordsContainer[crawler->index].size() ||//have a check acc to condition, if we encounter a smaller word, change index
   (n == wordsContainer[crawler->index].size() &&
    index < crawler->index))
{
    crawler->index = index;
}
    }
    crawler->endofword=true;
}
int check(string &query,TrieNode*root)//for checking suffix
{
    int n=query.size();
    TrieNode*crawler=root;
    for(int i=n-1;i>=0;--i)
    {
        char c=query[i];
        if(crawler->children[c-'a']==nullptr)//if it doesnt exist just return the latest index
        return crawler->index;
        crawler=crawler->children[c-'a'];
    }
    return crawler->index;//otherwise return index
}
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode*root=new TrieNode();
        int n=wordsContainer.size();
        for(int i=0;i<n;++i)
        {
            int index=root->index;//root already stores index, store it in index
            if(wordsContainer[index].size()>wordsContainer[i].size())//if already stored is greater, that means we need to replace it
            root->index=i;//change it to i
             insert(wordsContainer[i],root,i,wordsContainer);
        }
       
        vector<int>ans;
        for(string query:wordsQuery)
        {
            ans.push_back(check(query,root));
        }
        delete root;//after done execution, delete
        return ans;
    }
};
//tc- o(sum of lengths of total char + sum of lengths of total queries)
//sc- o(sum of unique char), for destructor Time: O(all nodes), Extra space: O(h)
