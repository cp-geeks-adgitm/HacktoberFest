class Solution {
public:
    string defangIPaddr(string address) {

        string s="";
        for(int i=0;i<address.length();i++){
            if(address[i]=='.')
            {
                s=s+"[.]";
            }
            else
                s=s+address[i];
        }
        return s;
    }
};
