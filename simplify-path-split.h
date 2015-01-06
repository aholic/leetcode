//https://oj.leetcode.com/problems/simplify-path/

class Solution {
public:
    vector<string> split(string line, char delim) {
        vector<string> ret;
        stringstream ss(line);
        string item;
        while (getline(ss, item, delim)) ret.push_back(item);
        return ret;
    }

    string simplifyPath(string path) {
        vector<string> tmp = split(path, '/');

        auto itr = tmp.begin();
        while (itr != tmp.end()) {
            if (*itr == "" || *itr == ".") {
                itr = tmp.erase(itr);
                continue;
            }
            if (*itr == "..") {
                itr = tmp.erase(itr);
                if (itr != tmp.begin()) itr = tmp.erase(itr-1);
                continue;
            }
            itr++;
        }

        string ret = "";
        for (int i = 0; i < tmp.size(); i++) ret = (ret + "/" + tmp[i]);

        if (ret == "") return string("/");
        return ret;
    }
};
