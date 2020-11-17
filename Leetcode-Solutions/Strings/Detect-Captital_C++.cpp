/* Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

1. All letters in this word are capitals, like "USA".
2. All letters in this word are not capitals, like "leetcode".
3. Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way. 

Example 1:

Input: "USA"
Output: True

Example 2:

Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters. */

//SOLUTION
 bool detectCapitalUse(string word) {
        int count=0;
        for(int i=0;i<word.length();i++){
            if(word[i]-'A'<=27 && word[i]-'A'>=0){
                count++;
            }
        }
        if(count==word.length()||count==0||count==1 && word[0]-'A'<=27 && word[0]-'A'>=0)
            return true;
        return false;
    }
