class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        // concept:
        // 3sum = one initial number + 2 sum
        // for a to avoid repetition we will sort it and then go through each number value as a until >0
        int a = 0;
        while( a < nums.size() - 2 && nums[a] <= 0){
            int l = a + 1;
            int r = nums.size()-1;
            while(r > l){
                int sum = nums[a] + nums[l] + nums[r];
                if(sum == 0){
                    result.push_back({nums[a], nums[l], nums[r]});
                    l++;
                    while( l < r && nums[l] == nums[l - 1] )l++;
                    r--;
                    while(r > l && nums[r] == nums[r + 1])r--;
                }
                else if(sum > 0)r--;
                else if(sum < 0)l++;
            }
            // increment a such that next a value should be distinct
            a++;
            while( a < l && nums[a] == nums[a - 1])a++;
        }
        return result;
    }
};
