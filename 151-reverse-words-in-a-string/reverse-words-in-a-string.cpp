class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp="",ans="";
        for(int i=0;i<s.length()+1;i++){
            if(s[i]==' ' || i==s.length()){
                if(temp!=""){
                    st.push(temp);
                }
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        while(st.size()!=1){
            cout<<"a"<<st.top()<<"b"<<"\n";
            ans+=st.top()+" ";
            st.pop();
        }
        ans+=st.top();
        return ans;
    }
};