class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st1;
        set<int> st2;
        vector<int> v;
        int count;
        for(int i=0;i<A.size();i++){
            st1.insert(A[i]);
            st2.insert(B[i]);
            count=0;
            for(auto i:st1){
                if(st2.find(i)!=st2.end()){
                    count++;
                }
            }
            v.push_back(count);
        }
        return v;
    }
};