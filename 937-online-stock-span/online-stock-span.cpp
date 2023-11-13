class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    int i=-1;
    StockSpanner() {
    }
    
    int next(int price) {
        i++;
        v.push_back(price);
        while(!s.empty() &&  v[s.top()]<=v[i]) s.pop();
        int res=s.empty()?i+1:i-s.top();
        s.push(i);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */