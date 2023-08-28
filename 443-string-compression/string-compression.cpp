class Solution {
public:
    int compress(vector<char>& chars) {
        char prev=chars[0];
        int i=1,c=1,index=0;
        while(i<chars.size()){
            if(chars[i]==prev){
                c++;
            }
            else{
                chars[index++]=prev;
                string s=to_string(c);
                int j=0;
                while(j<s.length() && c>1){
                    chars[index++]=s[j++];
                }
                prev=chars[i];
                c=1;
            }
            i++;
        }
        chars[index++]=prev;
        string s=to_string(c);
        int j=0;
        while(j<s.length() && c>1){
            chars[index++]=s[j++];
        }
        return index;
    }
};