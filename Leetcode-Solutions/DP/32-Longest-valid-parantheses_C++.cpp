class Solution {
public:
    int longestValidParentheses(string str) 
    {
        int n = str.length(); 
  if(n==0)
  return 0;
    stack<int> stk; 
    stk.push(-1); 
  
    int result = 0; 
  
    for (int i=0; i<n; i++) 
    { 
       
        if (str[i] == '(') 
          stk.push(i); 
        else 
        { 
            stk.pop(); 
            if (!stk.empty()) 
                result = max(result, i - stk.top()); 
            else stk.push(i); 
        } 
    } 
  
    return result; 
    }
};