class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int element=0;
        for(int i:nums){
            element^=i;
        }
        return element;
    }
};