class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> v(A.size());
        unordered_map<int,int> mp;
        int c=0;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            if(mp[A[i]]==2) c++;
            mp[B[i]]++;
            if(mp[B[i]]==2) c++;
            v[i]=c;
        }
        return v;
    }
};