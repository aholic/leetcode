//https://oj.leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp (const Interval& i1, const Interval& i2) {
return i1.start < i2.start;
}

class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return vector<Interval>();

        sort(intervals.begin(), intervals.end(), cmp);

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
