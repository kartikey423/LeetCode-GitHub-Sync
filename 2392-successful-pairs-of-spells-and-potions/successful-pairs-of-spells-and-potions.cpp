class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size(), m = spells.size();
        vector<pair<int,int>> spellWithIndex;
        for (int i = 0; i < m; i++) spellWithIndex.push_back({spells[i], i});
        sort(spellWithIndex.begin(), spellWithIndex.end());
        sort(potions.begin(), potions.end());
        vector<int> ret(m);
        int j = n - 1;
        for (int i = 0; i < m; i++) {
            int spell = spellWithIndex[i].first;
            while (j >= 0 && (long long)spell * potions[j] >= success) j--;
            ret[spellWithIndex[i].second] = n - (j + 1);
        }
        return ret;
    }
};