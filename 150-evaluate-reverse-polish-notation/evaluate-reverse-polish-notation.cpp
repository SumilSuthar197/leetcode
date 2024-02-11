class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a,int b) {return a+b;}},
            {"-", [](int a,int b) {return a-b;}},
            {"*", [](int a,int b) {return a*b;}},
            {"/", [](int a,int b) {return a/b;}}
        };
        for(string i:tokens){
            if(operations.find(i) != operations.end()){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                // cout<<b<<" "<<i<<" "<<a<<" "<<operations[i](b,a)<<"\n";
                s.push(operations[i](b,a));
            }else{
                s.push(stoi(i));
            }
        }
        if(s.empty()) return 0;
        return s.top();
    }
};