class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(p.begin(),p.end());
        int maxTime=0;
        int n=p.size();
        for(int i=0;i<tasks.size();i++){
            if(i%4==0) n--;
            // cout<<p[n]<<" "<<tasks[i]<<"\n";
            maxTime=max(maxTime,p[n]+tasks[i]);   
        }
        return maxTime;
    }
};