class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        vector<int> answer;
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum<target) left++;
            else if(sum>target) right--;
            else {
                answer.push_back(left+1);
                answer.push_back(right+1);
                break;
            }
        }
        return answer;
    }
};