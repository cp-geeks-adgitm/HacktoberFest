/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

• s consists only of printable ASCII characters.
*/

//SOLUTION

  bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.length();i++)
        {
            s[i]=tolower(s[i]);
            if(s[i]>='0' && s[i]<='9'||s[i]>='a' && s[i]<='z')
            str+=s[i];
        }
    int i=0,j=str.length()-1;
    while(i<=j){
        if(str[i++]!=str[j--])
            return false;
    }
    return true;
    }
