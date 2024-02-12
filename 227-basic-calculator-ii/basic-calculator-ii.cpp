class Solution {
public:
    int calculate(string s) {
        int i=0,n=s.length();
        int res=0,curr=0,prev=0;
        char curr_op='+';
        while(i<n){
            if(isdigit(s[i])){
                while(i<n && isdigit(s[i])){
                    curr=10*curr+(s[i]-'0');
                    i++;
                }
                i--;
                if(curr_op=='+'){
                    res+=curr;
                    prev=curr;
                }else if(curr_op=='-'){
                    res-=curr;
                    prev=-curr;
                }else if(curr_op=='*'){
                    res-=prev;
                    res+=curr*prev;
                    prev=curr*prev;
                }else if(curr_op=='/'){
                    res-=prev;
                    res+=prev/curr;
                    prev=prev/curr;
                }
                curr=0;
            }
            else if(s[i]!=' '){
                curr_op=s[i];
            }
            // cout<<res<<" "<<curr<<" "<<prev<<" "<<curr_op<<"\n";
            i++;
        }
        return res;
    }
};