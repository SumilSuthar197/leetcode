class Solution {
public:

    void buildAns(stack<string>& s,string& ans){
        if(s.empty()) return;

        string minpath=s.top();
        s.pop();
        buildAns(s,ans);
        ans+=minpath;
    }

    string simplifyPath(string path) {

        stack<string> st;
        int i=0;

        while(i<path.length()){
            int s=i;
            int e=i+1;

            while(e<path.length() && path[e]!='/'){
                e++;
            }

            string p=path.substr(s,e-s);
            i=e;

            if(p=="/" || p=="/.") continue;

            if(p!="/..") st.push(p);
            else if(!st.empty()) st.pop();

        }
        string ans=st.empty()?"/":"";

        buildAns(st,ans);
        return ans;        
    }
};