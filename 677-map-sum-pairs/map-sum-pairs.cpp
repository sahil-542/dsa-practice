static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class MapSum {
    struct Node { Node* ch[26]={}; int sum=0; };
    Node* root; unordered_map<string,int> mp;
public:
    MapSum() { root = new Node(); }
    void insert(string key, int val) {
        int diff = val - mp[key]; mp[key] = val;
        auto* n = root;
        for (char c : key) {
            if (!n->ch[c-'a']) n->ch[c-'a'] = new Node();
            n = n->ch[c-'a']; n->sum += diff;
        }
    }
    int sum(string prefix) {
        auto* n = root;
        for (char c : prefix) {
            if (!n->ch[c-'a']) return 0;
            n = n->ch[c-'a'];
        }
        return n->sum;
    }
};