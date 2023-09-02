class Solution {
public:
    string sortVowels(string s) {
        string temp;
        set<char>st={'a','A','e','E','i','I','o','O','u','U'};
        for(auto i:s){
            if(st.count(i)) temp+=i;
        }
        sort(temp.begin(),temp.end());
        int j=0,i=0;
        while(j<temp.length()){
            if(st.count(s[i])){
                s[i]=temp[j];
                j++;
            }
            i++;
        }
        return s;
    }
};