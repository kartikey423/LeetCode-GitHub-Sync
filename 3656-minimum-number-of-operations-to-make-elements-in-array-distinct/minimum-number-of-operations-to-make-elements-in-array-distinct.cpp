class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n=nums.size();
        bitset<101> hasX=0;
        for(int i=n-1; i>=0; i--){
            int x=nums[i];
            if (hasX[x]) return i/3+1;
            hasX[x]=1;
        }
        return 0;
    }
};