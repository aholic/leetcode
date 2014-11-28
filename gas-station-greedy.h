//https://oj.leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        int totalGas = 0, totalCost = 0, mi = 0, pos = 0;
        for (int i = 0; i < len; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            if (totalGas - totalCost < mi) {
                mi = totalGas - totalCost;
                pos = i;
            }
        }
        if (totalGas < totalCost) return -1;
        return (pos + 1) % len;
    }
};
