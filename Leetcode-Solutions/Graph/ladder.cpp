class Solution {
public:
      unordered_set<string>set,set1;
      queue<pair<string,int>>que;
   void exists(string word,string endWord,int level){
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            for(int j=0;j<26;j++){
                word[i]='a'+j;
                if(word[i]==ch)
                    continue;
                if(set.find(word)!=set.end() &&        set1.find(word)==set1.end()){
                    // cout<<" "<<word;
                    que.push({word,level});
                    set1.insert(word);
                    if(word==endWord)
                        return;
                }
            }
            word[i]=ch;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size()==0)
            return 0;      
        for(string s:wordList)
            set.insert(s);
        if(set.find(endWord)==set.end())
            return 0;
        que.push({beginWord,1});
        while(que.size()>0){
            pair<string,int>top=que.front();
            que.pop();
            // cout<<top.first<<"-"<<top.second<<endl;
            if(top.first==endWord)
                return top.second;
            exists(top.first,endWord,top.second+1);           
            }
        return 0;
    }
};