class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int index=0;
    for(int i=1;i<nums.size();i++){
        if(nums[index]!=nums[i]){
            index++;
        }
        else{
            nums.erase(nums.begin()+i);
            i--;
        }
    }
    return index+1;
    }
};