#include <map> 
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxlen = 0;
        for(int i=0; i<=s.length(); i++)
        {
            bool repeated = 0;
            for(int j = 0; j+i<=s.length(); j++)
            {
                string substring = s.substr(i,j);
                repeated = is_non_repeated_string(substring);
                if (repeated)
                    break;
                update(substring, maxlen);
            }
        }
        return maxlen;
    }
    bool is_non_repeated_string(string s)
    {
        map<char, int> m;
        for(int i = 0; i <= s.length(); i++)
        {
            pair<char, int> p(s[i], 1);
            auto search = m.find(s[i]);
            if (search != m.end()){
                return 1;
            }
            m.insert(p);
        }
        return 0;
    }
    void update(string s, int& maxlen)
    {
        if(s.length() > maxlen)
        {
            maxlen = s.length();
        }
    }
};
