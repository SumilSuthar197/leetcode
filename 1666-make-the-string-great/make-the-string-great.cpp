class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string result="";
        for(char i:s){
            if(!st.empty() && abs(st.top()-i)==32){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};