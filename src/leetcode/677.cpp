#include <map>

using namespace std;

class MapSum {
public:
    map<string, int> _map;

    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        _map[key] = val;
    }

    int sum(string prefix) {
        int _sum = 0;
        for (auto item = _map.lower_bound(prefix); item != _map.end(); ++item) {
            if (item->first.find(prefix) == 0) {
                _sum += item->second;
            }
        }
        return _sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
