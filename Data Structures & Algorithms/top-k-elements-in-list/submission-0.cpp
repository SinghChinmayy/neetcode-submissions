class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for( const auto& [number, count] : freq){
            buckets[count].push_back(number);
        }

        vector<int> result;
        for(int count = nums.size(); count >= 1; count--){
            for(int numbers: buckets[count]){
                result.push_back(numbers);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
