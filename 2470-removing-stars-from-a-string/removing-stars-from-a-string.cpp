class Solution {
public:
    string removeStars(string s) {
        int noOfStar=0,i=s.size()-1;
        string res="";
        while(i>=0){
            if(s[i]=='*') noOfStar++;
            else if(noOfStar>0 && s[i]!='*'){
                s[i]='#';
                noOfStar--;
            }
            i--;
        }
        for(char i:s){
            if(i!='*' && i!='#') res+=i;
        }
        return res;

        // stack<char> st;
        // string res="";
        // for(char i:s){
        //     if(i=='*') st.pop();
        //     else st.push(i);
        // }
        // while(!st.empty()){
        //     res=st.top()+res;
        //     st.pop();
        // }
        // return res;
    }
};