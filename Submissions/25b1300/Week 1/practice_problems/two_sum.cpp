#include <bits/stdc++.h>
using namespace std;

vector<long long> twoSum(vector<long long>& nums, long long target) {
    unordered_map<long long, long long> result;
    for(size_t i=0; i<nums.size(); i++) {
        if(result.find(target - nums[i]) != result.end()) {
            return {result[target - nums[i]], static_cast<long long>(i)};
        }
        result[nums[i]] = i;
    }
    return {};
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long target;
    vector<long long> nums;
    long long n;
    cin >> n;
    for(long long i=0; i<n; i++) {
        long long num;
        cin >> num;
        nums.push_back(num);
    }
    cin >> target;
    vector<long long> result = twoSum(nums, target);
    for(size_t i=0; i<result.size(); i++) {    
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}
