class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto b:s){
            
            if(b=='(' || b == '[' || b == '{'){
                st.push(b);
            }
            else if(!st.empty()){
                if((b == ')' && st.top() == '(') || (b == ']' && st.top() == '[') || b == '}' && st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return st.empty();
    }
};