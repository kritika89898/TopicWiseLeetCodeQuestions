class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            string str = "";
            while(s[i] != ' ' && i<s.size()){
                str = str + s[i];
                i++;
            }
            reverse(str.begin(),str.end());
            if(str.length()>0){
                ans = ans+" " + str;
            }
        }
        return ans.substr(1);
    }
};