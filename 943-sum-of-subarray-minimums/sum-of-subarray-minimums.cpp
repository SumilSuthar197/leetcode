class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& v) {
        int n=v.size();
        vector<int> left(n,-1),right(n,n);
        stack<int> s;
        //next smallest
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && v[s.top()]>v[i]) s.pop();
            if(!s.empty()) right[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        //prev smallest
        for(int i=0;i<n;i++){
            while(!s.empty() && v[s.top()]>=v[i]) s.pop();
            if(!s.empty()) left[i]=s.top();
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=static_cast<long long>((i-left[i])*1LL*(right[i]-i)*v[i])%mod;
            ans%=mod;
        }
        return (int)ans;
    }
};