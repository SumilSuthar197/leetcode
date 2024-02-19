class Solution {
public:
    int maxArea(vector<int> v,int n){
        vector<int> left(n,0),right(n,n-1);
        stack<int> s;
        //NSR
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && v[s.top()]>=v[i]) s.pop();
            if(!s.empty()) right[i]=s.top()-1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        //NSL
        for(int i=0;i<n;i++){
            while(!s.empty() && v[s.top()]>=v[i]) s.pop();
            if(!s.empty()) left[i]=s.top()+1;
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i]*(right[i]-left[i]+1));
        }
        // for(int i:v) cout<<i<<" ";cout<<"\nr: ";
        // for(int i:right) cout<<i<<" ";cout<<"\nl: ";
        // for(int i:left) cout<<i<<" ";cout<<"\na: "<<ans<<"\n";
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=0,r=matrix.size(),c=matrix[0].size();
        vector<int> temp(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1') temp[j]+=1;
                else temp[j]=0;
                // cout<<temp[j]<<" ";
            }
            // cout<<"\n";
            maxi=max(maxi,maxArea(temp,c));
        }
        return maxi;
    }
};