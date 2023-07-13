class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if (j>(i+1) && nums[j]==nums[j-1]) continue;
                int low=j+1,high=nums.size()-1;
                while(low<high){
                    long sum=(long)nums[i]+(long)nums[j]+(long)nums[low]+(long)nums[high];
                    if(sum<target){
                        low++;
                    }
                    else if(sum>target){
                        high--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        while (low < high && nums[low] == nums[low-1]) low++;
                    }
                }
            }
        }  
        return ans; 
    }
};