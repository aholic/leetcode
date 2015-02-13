//https://oj.leetcode.com/problems/max-points-on-a-line/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
*/

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 2) return points.size();

        unordered_map<double, int> cnt;
        int same = 1, vertical = 1, max = 1, ret = 1;
        double k = 0;
        for (int i = 0; i < points.size(); i++) {
            cnt.clear();
            same = 0;
            max = 1;
            vertical = 1;
            for (int j = i+1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same += 1;
                    continue;
                }
                if (points[j].x == points[i].x) {
                    vertical += 1;
                    if (vertical > max) max = vertical;
                    continue;
                }
                k = (double (points[i].y-points[j].y)) / (double (points[i].x-points[j].x));
                cnt[k] += 1;
                if (cnt[k]+1 > max) max = cnt[k]+1;
            }
            if (max + same > ret) ret = max + same;
        }

        return ret;
    }
};
