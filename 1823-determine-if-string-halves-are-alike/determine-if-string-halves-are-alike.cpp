class Solution {
public:
    bool halvesAreAlike(string s) {
        int a=0,b=0,n=s.length();
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<n/2;i++){
            if(vowels.count(s[i])>0) a++;
            if(vowels.count(s[n-i-1])>0) b++;
        }
        if(a==b)return true;
        return false;
    }
};