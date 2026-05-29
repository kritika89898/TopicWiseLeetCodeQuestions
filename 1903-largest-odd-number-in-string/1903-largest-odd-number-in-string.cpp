class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int e = n-1;
        while(e>=0){
            int a = num[e]- '0';
            if(a%2 == 0){
                n--;
                e--;

            }else{
                break;
            }
        }
        return num.substr(0,n);
    }
};