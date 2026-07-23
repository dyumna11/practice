class Solution {
public:
struct TrieNode{
    TrieNode* children[26];
    bool endofword;
    TrieNode()
    {
        for(int i=0;i<26;++i)
        children[i]=nullptr;
        endofword=false;
    }
};
void insert(string word,TrieNode* root)//insert all prefixes
{
    TrieNode* crawler=root;
    for(char c:word)
    {
        if(crawler->children[c-'a']==nullptr)
        {
            crawler->children[c-'a']=new TrieNode();
        }
       
        crawler=crawler->children[c-'a'];        
    }
    crawler->endofword=true;
}
string check(string word,TrieNode* root)//check if prefix exists for words
{
    TrieNode* crawler=root;
    int n=word.size();
    for(int i=0;i<n;++i)
    {
        char c=word[i];
        if(crawler->children[c-'a']==nullptr)
        return word;
        crawler=crawler->children[c-'a'];
        if(crawler->endofword)//if we have reached end of our prefix
        return word.substr(0,i+1);//return substring till there
    }
    return word;
}
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root=new TrieNode();
        for(string c:dict)
        insert(c,root);
        string ans="";
        stringstream ss(sentence);//use string tokenizer to partition acc to spaces
        string word;
        while(getline(ss,word,' '))
        ans+=check(word,root)+' ';
        ans.pop_back();//to avoid the last space
        return ans;
    }
};
