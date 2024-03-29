class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int maxFreq = 0, maxEle = 0;
        unordered_map<int, int> mp;
        for (int& i : barcodes) {
            mp[i]++;
            if (maxFreq < mp[i]) {
                maxFreq = mp[i];
                maxEle = i;
            }
            i = 0;
        }
        int i = 0;
        while (i < barcodes.size() && maxFreq > 0) {
            barcodes[i] = maxEle;
            mp[maxEle]--;
            maxFreq--;
            i += 2;
        }

        for (auto m : mp) {
            if (m.second <= 0)
                continue;
            while (m.second > 0) {
                i = i >= barcodes.size() ? 1 : i;
                barcodes[i] = m.first;
                m.second--;
                i += 2;
            }
        }

        return barcodes;
    }
};