class Solution {
public:
    double average(vector<int>& salary) {
        int maxEle=*max_element(salary.begin(),salary.end());
        int minEle=*min_element(salary.begin(),salary.end());
        double average=(accumulate(salary.begin(),salary.end(),0.0)-maxEle-minEle)/(salary.size()-2);
        return average;
        
    }
};