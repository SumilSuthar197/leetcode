class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minute;
        int diff=INT_MAX;
        for(auto i:timePoints){
            int h=stoi(i.substr(0,2));
            int m=stoi(i.substr(3,2));
            minute.push_back(60*h + m);
        }
        sort(minute.begin(),minute.end());
        for(int i=1;i<minute.size();i++){
            diff=min(diff,abs(minute[i-1]-minute[i]));
        }
        diff=min(diff,minute[0]+1440-minute[minute.size()-1]);
        return diff;
    }
};