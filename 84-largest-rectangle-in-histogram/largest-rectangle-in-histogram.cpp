class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> right(n,n-1),left(n,0);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<=arr[s.top()]) s.pop();
            if(!s.empty()) left[i]=s.top()+1;
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[i]<=arr[s.top()]) s.pop();
            if(!s.empty()) right[i]=s.top()-1;
            s.push(i);  
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,arr[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};