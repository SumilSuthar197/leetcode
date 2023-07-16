class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> st;
        int i=0,j=1;
        while(j<nums.size()){
            int dif=nums[j]-nums[i];
            if(dif==k){
                st.insert({nums[i],nums[j]});
                ++i;++j;
            }else if(dif>k){
                ++i;
            }
            else{
                ++j;
            }
            if(i==j){
                ++j;
            }
        }
        return st.size();
    }
};