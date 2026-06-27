class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto& ch : s){
            
            if(!st.empty()){
                string ns = "";
                ns = ns + st.top();
                
                ns = ns + ch;
                
                if(ns == "AB" || ns == "CD"){
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.size();
    }
};