#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long> > tasks;
    long long sumDeadlines = 0;

    for (int i = 0; i < n; i++) {
        long long a, d;
        cin >> a >> d;
        tasks.push_back(make_pair(a, d));
        sumDeadlines += d;
    }

    sort(tasks.begin(), tasks.end());

    long long currentTime = 0;
    long long sumFinishTimes = 0;

    for (int i = 0; i < n; i++) {
        currentTime += tasks[i].first;
        sumFinishTimes += currentTime;
    }

    cout << sumDeadlines - sumFinishTimes << endl;

    return 0;
}