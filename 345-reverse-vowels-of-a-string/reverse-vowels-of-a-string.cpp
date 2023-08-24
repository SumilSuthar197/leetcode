class Solution {
public:
    bool isVowels(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||ch=='A' ||     ch=='E' ||          ch=='I' ||ch=='O' ||ch=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(!isVowels(s[i])){
                i++;
            }
            else if(!isVowels(s[j])){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
        
    }
};