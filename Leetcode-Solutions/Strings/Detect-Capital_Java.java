class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.equals(word.toUpperCase()))
            return true;
        for(int i=1;i<word.length();i++){
            if(word.charAt(i)>= 'A' && word.charAt(i)<='Z')
                return false;
        }
        return true;
    }
}