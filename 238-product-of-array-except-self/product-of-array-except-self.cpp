class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n);
        vector<int> s(n);
        vector<int> v;
        p[0]=1;
        s[n-1]=1;

        for(int i=0;i<n-1;i++) p[i+1]=p[i]*nums[i];
        for(int i=n-1;i>=1;i--) s[i-1]=s[i]*nums[i];

        // for(int i=0;i<n;i++){
        //     cout<<p[i]<<" "<<s[i]<<"\n";
        // }
        for(int i=0;i<n;i++){
            v.push_back(p[i]*s[i]);
        }
        return v;
    }
};