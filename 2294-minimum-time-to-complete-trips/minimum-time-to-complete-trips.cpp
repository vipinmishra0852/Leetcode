class Solution {
public:
 bool check(long long mid, long long totalTrips, vector<int>& time) {
    int n = time.size();
    long long m = 0;
    for (int i = 0; i < n; ++i) {
        if (time[i] == 0) {
            if (mid < 0) {
                // Handle negative overflow by setting m to LLONG_MIN
                m = LLONG_MIN;
                break;
            }
            // If time[i] is 0, no need to divide, just add totalTrips
            m += totalTrips;
        } else {
            // Add mid divided by time[i], but ensure it doesn't overflow
            if (mid / time[i] > LLONG_MAX - m) {
                // Handle overflow by setting m to LLONG_MAX
                m = LLONG_MAX;
                break;
            }
            m += mid / time[i];
        }
    }
    return m >= totalTrips;
}



    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long lo = 1;
        long long hi = LLONG_MAX;
        long long ans = 0;
        if (n == 1) return (long long)totalTrips * time[0]; // Cast totalTrips to long long here
        long long trips = (long long)totalTrips; 

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid, trips, time)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
