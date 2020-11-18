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
        if(s.length() <= 1) return true;
        int start = 0, end= s.length()-1;
        while(start<end){
            //isalnum() is used to check if a char is alpha numeric.
            //Increment till we encounter an alpha numeric character
            while(start< end && !isalnum(s[start])) start++; //left side
            while(start< end && !isalnum(s[end])) end--; //right side

            if(start<end && tolower(s[start]) != tolower(s[end])) return false;
            start++;    
            end--;
            
        }
        return true;
    }
