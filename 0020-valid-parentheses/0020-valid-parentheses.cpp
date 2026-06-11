class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1) return false;
        stack<int> st;

        for(auto x: s){
           if(x == '(' || x == '[' || x == '{') st.push(x);
           else{
            if(st.empty()) return false;
            if((x == ')' && st.top() == '(') || (x == '}' && st.top() == '{') || (x == ']' && st.top() == '[')) st.pop();
            else return false;
           }
        }
        return st.empty();
        

    }
};