class Solution {
public:
    string reverseWords(string s) {
        // string ans="",temp="";
        // int i=0;
        // while(i!=s.length()){
        //     if(s[i]==' '){
        //         ans+=temp+" ";
        //         temp="";
        //     }
        //     else{
        //         temp=s[i]+temp;
        //     }
        //     i++;
        // }
        // ans+=temp;
        // return ans;
        stringstream ss(s);
        string temp,ans;
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans+= (temp+" ");
        }
        return ans.substr(0,ans.size()-1);
    }
};