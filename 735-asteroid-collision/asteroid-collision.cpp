class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for(int i=0;i<a.size();i++){
            if(s.empty()) s.push(a[i]);
            else if(s.top()>0 && a[i]<0){//+- case
                while(!s.empty() && s.top()>0 && abs(a[i])>abs(s.top())) s.pop();
                if(!s.empty() && a[i]+s.top()==0) s.pop();
                else if(s.empty()||s.top()<0) s.push(a[i]);
            }
            else{s.push(a[i]);}//++ ||  -- case
        }
        
        vector<int> v(s.size(),0);
        int i=s.size()-1;
        while(!s.empty()){
            v[i--]=s.top();
            s.pop();
        }
        return v;
    }
};