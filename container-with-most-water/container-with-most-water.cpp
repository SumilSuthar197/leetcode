class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,ans=0;
        while(left<right){
            int temp=min(height[left],height[right])*(right-left);
            ans=max(ans,temp);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return ans;
    }
};