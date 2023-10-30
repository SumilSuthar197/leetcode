class Solution {
public:
    static bool bitSort(int a,int b){
        int a_bit=__builtin_popcount(a);
        int b_bit=__builtin_popcount(b);
        if(a_bit!=b_bit) return a_bit<b_bit;
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),bitSort);
        return arr;
    }
};