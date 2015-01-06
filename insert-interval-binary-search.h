//https://oj.leetcode.com/problems/insert-interval/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int getInsertPos(const vector<Interval> &intervals, Interval newInterval) {
        if (intervals.size() == 0) return 0;
        if (intervals[intervals.size()-1].start < newInterval.start) return intervals.size();

        int l = 0, r = intervals.size() - 1;
        int mid = l + (r - l) / 2;
        while (l <= r) {
            if (intervals[mid].start >= newInterval.start) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
        }

        return l;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int insertPos = getInsertPos(intervals, newInterval);
        intervals.insert(intervals.begin()+insertPos, newInterval);

        vector<Interval> ret;
        int low = intervals[0].start;
        int high = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (high >= intervals[i].start) {
                if (high < intervals[i].end) {
                    high = intervals[i].end;
                }
                continue;
            }

            ret.push_back(Interval(low, high));
            low = intervals[i].start;
            high = intervals[i].end;
        }

        ret.push_back(Interval(low, high));

        return ret;
    }
};
