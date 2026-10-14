class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9 * num < sum) return "";
        string ans{};
        int nines = sum / 9;
        ans.append(nines, '9');
        sum -= nines * 9;
        if(sum) ans += (sum + '0');
        ans.append(num - ans.size(), '0');
        return ans;
    }
};