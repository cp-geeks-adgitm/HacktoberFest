/* Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/

class Solution {
    public String removeDuplicateLetters(String s) {
        //         FIND THE INDEX OF LAST OCCURRENCE OF EACH CHARACTER
        int[] last = new int[26];
        for(int i=0; i<s.length(); i++){
            last[s.charAt(i)-'a'] = i;
        }
//         USE A STACK TO KEEP RESULT CHARACTERS
//         MAINTAIN A BOOLEAN SET TO SEE IF CHARACTER HAS BEEN ENCOUNTERED BEFORE
        boolean[] seen = new boolean[26];
        Stack<Integer> resultChar = new Stack<>();
        
//         LOOP THROUGH EACH CHCARACTER
//         IF CURRENT CHARACTER IS LEXICOGRAPHICALLY SMALLER THAN LAST CHARACTER IN STACK AND THE LAST CHARACTER IN STACK OCCURS LATER IN THE STREAM THEN POP THE CHARACTER FROM THE STACK
        for(int i=0; i<s.length(); i++){
            int curr = s.charAt(i)-'a';
            if(seen[curr]) continue;
            seen[curr] = true;
            
            while(!resultChar.isEmpty() && 
                 curr<resultChar.peek() &&
                 last[resultChar.peek()]>i){
                seen[resultChar.pop()] = false;
            }
            //PUSH CURRENT CHARACTER IN STACK
            resultChar.push(curr);
        }
        
        //BUILD STRING USING STACK
        StringBuilder sb = new StringBuilder();
        for(int i : resultChar){
            sb.append((char)('a'+i));
        }
        return sb.toString();
    }
}