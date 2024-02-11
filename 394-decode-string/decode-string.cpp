class Solution {
public:
    string decodeString(string s) {
        int i=s.length()-1;
        stack<string> st;
        while(i>=0){
            if(!st.empty() && s[i]=='['){
                string temp="";
                while(st.top()!="]"){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                string no="",rs="";
                i--;
                while(i>=0 && isdigit(s[i])){
                    no=s[i]+no;
                    i--;
                }
                // cout<<temp<<" "<<no<<" "<<stoi(no)<<" "<<s[i]<<"\n";
                for (int k=0;k<stoi(no);k++) rs+=temp;
                st.push(rs);
            }
            else{
                string str(1, s[i]); // Convert char to string
                st.push(str);
                i--;
            }
        }
        string mn="";
        while(!st.empty()){
            mn+=st.top();
            st.pop();
        }
        return mn;
    }
};