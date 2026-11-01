class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int val = nums.size();
        for (int i = 0; i < nums.size(); i++){
            val ^= i ^ nums[i];
        }
        return val;
    }
};
