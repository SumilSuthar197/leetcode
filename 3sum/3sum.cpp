class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; 

        for(int i = 0; i < nums.size()-1; i++){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k] > 0)
                    k--;
                else if(nums[i]+nums[j]+nums[k] < 0)
                    j++;
                else{
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) 
                        j++;
                    while (j < k && nums[k] == nums[k-1]) 
                        k--;
                    j++; k--;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) 
                i++;
        }
        return res;
    }
};