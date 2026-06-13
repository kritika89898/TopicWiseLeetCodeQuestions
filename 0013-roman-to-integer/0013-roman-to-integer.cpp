class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                if(i + 1 < n && s[i+1]=='V'){
                    cnt=cnt+4;
                    i++;
                }
                else if(i + 1 < n && s[i+1]=='X'){
                    cnt=cnt+9;
                    i++;
                }
                else cnt++;
            }
            else if(s[i]=='V'){
                cnt=cnt+5;
            }
            else if(s[i]=='X'){
                if(i + 1 < n && s[i+1]=='L'){
                    cnt=cnt+40;
                    i++;
                }
                else if(i + 1 < n && s[i+1]=='C'){
                    cnt=cnt+90;
                    i++;
                }
                else cnt=cnt+10;
            }
            else if(s[i]=='L'){
                cnt=cnt+50;
            }
            else if(s[i]=='C'){
                if(i + 1 < n && s[i+1]=='D'){
                    cnt=cnt+400;
                    i++;
                }
                else if(i + 1 < n && s[i+1]=='M'){
                    cnt=cnt+900;
                    i++;
                }
                else cnt=cnt+100;
            }
            else if(s[i]=='D'){
                cnt=cnt+500;
            }
            else{
                cnt=cnt+1000;
            }
        }
        return cnt;
    }
};