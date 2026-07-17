#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    vector<long long> ans;
    long long n;
    cin>>n;
    for(long long i = 0; i < n; i++){
        long long x, y;
        cin>>x>>y;
        long long maxans = 0;
        long long an = 0;
        while(x <= y){
            vector<int> nums;
            nums.resize(0);
            long long a = x;
            while(a > 0){
                nums.push_back(a%10);
                a /= 10;
            }
            long long maximum = 0;
            long long minimum = LLONG_MAX;
            for(int k = 0; k < nums.size(); k++){
                if(nums[k] > maximum){
                    maximum = nums[k];
                }
                if(nums[k] < minimum){
                    minimum = nums[k];
                }
            }
            long long m = maximum - minimum;
            if(m >= maxans){
                maxans = m;
                an = x;
            }
            if(maxans == 9) break;
            x++;
        }
        ans.push_back(an);
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}