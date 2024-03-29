class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tempSum = 0, rsum = 0, sum = 0, h = cardPoints.size() - 1;

        tempSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        sum = tempSum;
        for (int i = k - 1; i >= 0; i--) {
            tempSum -= cardPoints[i];
            tempSum += cardPoints[h--];
            sum = max(sum, tempSum);
        }
        return sum;
    }
};