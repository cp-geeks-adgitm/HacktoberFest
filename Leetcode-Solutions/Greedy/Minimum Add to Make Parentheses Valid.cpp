class Solution {
public:
    int minAddToMakeValid(string S) {
        if(S=="" || S==" ") return 0;
        int count=0;
        stack<char> s;
        for(int i=0;i<S.size();i++)
        {
            char tmp=S[i];
            if(tmp=='(')
            {
                s.push('(');
            }
            else if(tmp==')')
            {
                if(s.empty()) s.push(')');
                else
                {
                    if(s.top()=='(') s.pop();
                    else s.push(')');
                } 
            }
        }
        while(!s.empty())
        {
            s.pop();
            count++;
        }
        return count;
    }
};
