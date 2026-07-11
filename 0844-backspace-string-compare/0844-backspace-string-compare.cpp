class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(auto ch : s){
            if(!st1.empty() && ch == '#') st1.pop();
            else if(ch != '#') st1.push(ch);
            else continue;
        }
        for(auto ch : t){
            if(!st2.empty() && ch == '#') st2.pop();
            else if(ch != '#') st2.push(ch);
            else continue;
        }
        return st1 == st2;
    }
};