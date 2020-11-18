class Solution {
public:
    map<pair<int,int>,bool>m;
    bool helper(string text,string pattern, int textindex, int patternindex) {
  if(textindex==text.length()&&patternindex==pattern.length())
     m[{textindex,patternindex}]=true;
  else if(textindex==text.length()) {
    if(patternindex+1<pattern.length()&&pattern[patternindex+1]=='*'&&m.find({textindex,patternindex})==m.end())
       m[{textindex,patternindex}]= helper(text,pattern,textindex,patternindex+2);
    else 
       m[{textindex,patternindex}] =false;
  }
  
  else if(patternindex+1<pattern.length()&&pattern[patternindex+1]=='*') {
    if((text[textindex]==pattern[patternindex]||pattern[patternindex]=='.')&&m.find({textindex,patternindex})==m.end())
       m[{textindex,patternindex}] = helper(text,pattern,textindex+1,patternindex) ||             helper(text,pattern,textindex,patternindex+2);
    else
      m[{textindex,patternindex}] = helper(text,pattern,textindex,patternindex+2);
  }
      
  else if((text[textindex]==pattern[patternindex]||pattern[patternindex]=='.')&&m.find({textindex,patternindex})==m.end())
    m[{textindex,patternindex}] = helper(text,pattern,textindex+1,patternindex+1);
  
  else
    m[{textindex,patternindex}] = false;

        return m[{text.length(),pattern.length()}];
  }
    bool isMatch(string s, string p) {
        
        return  helper(s,p,0,0);
    }
};