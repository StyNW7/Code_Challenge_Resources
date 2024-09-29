// Link: https://leetcode.com/problems/all-oone-data-structure/

class AllOne {
public:

    unordered_map<string, int> count;
    set<pair<int, string>> setPair;

    AllOne() {
        count.clear();
    }
    
    void inc(string key) {
        int n = count[key];
        count[key]++;
        setPair.erase({n, key});
        setPair.insert({n+1, key});
    }
    
    void dec(string key) {
        int n = count[key];
        count[key]--;
        setPair.erase({n, key});
        if (count[key] > 0) setPair.insert({n-1, key});
        else count.erase(key);
    }
    
    string getMaxKey() {
        if (!setPair.empty()) return setPair.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if (!setPair.empty()) return setPair.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
