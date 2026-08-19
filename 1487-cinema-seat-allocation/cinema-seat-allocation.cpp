class Solution {
public:
    using T = bitset<11>;
    T mask_L = 60;//00000111100
    T mask_R = 960;//01111000000
    T mask_M = 240;//00011110000
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (auto r : reservedSeats) {
            mp[r[0]].push_back(r[1]);
        }

        int cnt = 2 * (n - mp.size());
        for (auto& [r, c] : mp) {
            T mask = 0;
            for (int& x : c)mask.set(x);

            int L = (mask & mask_L).none(), R = (mask & mask_R).none(), M = (mask & mask_M).none();
            cnt += max(M, L + R);
        }
        return cnt;
    }
};