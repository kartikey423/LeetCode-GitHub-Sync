class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> counter;
        int ans = 0;
        int count = 0;
        int n = nums.size();

        for (int num : nums) {
            counter[num]++;
        }

        for (auto& entry : counter) {
            int key = entry.first;
            int value = entry.second;

            if (value * 2 > n) {
                ans = key;
                count = value;
                break;
            }
        }

        int preCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == ans) {
                preCount++;
                count--;
            }

            if (preCount > (i + 1) / 2 && count > (n - i - 1) / 2) {
                return i;
            }
        }

        return -1;
    }
};