class Solution {
public:
    // Appeoach of O(n^2):
    //
    int expandAroundIndex(string s,int i,int j){
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int c=0;
        for(int i=0;i<s.length();i++){
            c+=expandAroundIndex(s,i,i);
            c+=expandAroundIndex(s,i,i+1);
        }
        return c;
    }

    // Approach of O(n^3):
    //
    // bool isPalindrome(string s){
    //     if(s.length()==1) return true;
    //     for(int i=0;i<s.length()/2;i++){
    //         if(s[i]!=s[s.length()-i-1]) return false;
    //     }
    //     return true;
    // }
    // int countSubstrings(string s) {
    //     vector<string> str;
    //     for(int i=0;i<s.size();i++){
    //         for(int len=1;len<=s.size()-i;len++){
    //             str.push_back(s.substr(i,len));
    //         }
    //     }
    //     int count=0;
    //     for(auto i:str){
    //         cout<<i<<" ";
    //         if(isPalindrome(i)) count++;
    //     }
    //     return count;
    //}
};