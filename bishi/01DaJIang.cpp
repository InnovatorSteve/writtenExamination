#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:

	/* Write Code Here */
	int getMinute(string &time) {
		return (int(time[0] - '0') * 10 + int(time[1] - '0')) * 60 + int(time[3] - '0') * 10 + int(time[4] - '0');
	}
	int findMinDifference(vector < string >& timePoints) {
		int n = timePoints.size();
		if (n > 1440) return 0;
		sort(timePoints.begin(), timePoints.end());
		int ans = INT_MAX;
		int t0Minute = getMinute(timePoints[0]);
		int preMinute = t0Minute;
		for (int i = 1; i < n; ++i) {
			int minute = getMinute(timePoints[i]);
			ans = min(ans, minute - preMinute);
            preMinute = minute;
		}
		ans = min(ans, t0Minute + 1440 - preMinute);
		return ans;

	}
};
int main() {
	int res;

	int timePoints_size = 0;
	cin >> timePoints_size;
    getchar();
	vector<string> timePoints;
	string timePoints_item;
	for (int timePoints_i = 0; timePoints_i < timePoints_size; timePoints_i++) {
		getline(cin, timePoints_item);
        timePoints.push_back(timePoints_item);
	}
	Solution *s = new Solution();
	res = s->findMinDifference(timePoints);
	cout << res << endl;

	return 0;

}
