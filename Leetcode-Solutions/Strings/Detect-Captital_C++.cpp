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
        int n = word.length();
        if(n== 1) return true;
        if(isupper(word[0]) && isupper(word[1])){
            for(int i = 2; i<n ; ++i)
                if(islower(word[i])) return false;
        }else{
            for(int i = 1; i< n; ++i)
                if(isupper(word[i])) return false;
        }
        return true;
    }
