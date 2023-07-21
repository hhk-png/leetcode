



// https://leetcode.cn/problems/all-oone-data-structure/solution/quan-o1-de-shu-ju-jie-gou-by-leetcode-so-7gdv/

/*

class AllOne {
public:
    unordered_map<string, int> mp;
    priority_queue<pair<int, string>> maxVal;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> minVal;
    AllOne() {
    }

    void inc(string key) {
        ++mp[key];
        maxVal.emplace(mp[key], key);
        minVal.emplace(mp[key], key);
    }

    void dec(string key) {
        if(mp.count(key) && mp[key]) {
            --mp[key];
            if(mp[key]) {
                minVal.emplace(mp[key], key);
                maxVal.emplace(mp[key], key);
            }
        }
    }

    string getMaxKey() {
        while(!maxVal.empty()) {
            auto [val, str] = maxVal.top();
            if(mp[str] == val) {
                return str;
            }
            maxVal.pop();
        }
        return "";
    }

    string getMinKey() {
        while(!minVal.empty()) {
            auto [val, str] = minVal.top();
            if(mp[str] == val) {
                return str;
            }
            minVal.pop();
        }
        return "";
    }
};


*/