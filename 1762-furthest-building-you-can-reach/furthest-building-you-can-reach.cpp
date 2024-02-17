class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        priority_queue<int> pq;
        while(i<heights.size()-1){
            int d=heights[i+1]-heights[i];
            if(d>0) pq.push(-d);
            if (pq.size()>ladders) {
                bricks+=pq.top();
                pq.pop();
            }
            if (bricks<0) break;
            i++;
        }
        return i;
    }
};