class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char i:s){
            if(!st.empty() && abs(st.top()-i)==32){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};