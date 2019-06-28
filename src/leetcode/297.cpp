#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        string s;
        _serialize(root, s);
        return s;
    }

    TreeNode *deserialize(string data) {
        if (data.empty())
            return nullptr;
        vector<int> res;
        split(data, res, '_');
        int pos = 0;
        TreeNode *newHead = _deserialize(res, pos);
        return newHead;
    }

private:
    void _serialize(TreeNode *cur, string &s) {
        if (cur == nullptr) {
            s += "#_";
            return;
        }
        s += to_string(cur->val) + "_";
        _serialize(cur->left, s);
        _serialize(cur->right, s);
    }

    void split(const string &src, vector<int> &vec, const char delimiter) {//不要用string去接收结果
        vec.clear();
        istringstream iss(src);
        string tmp;
        while (getline(iss, tmp, delimiter)) {
            if (tmp == "#")
                vec.push_back(0x3f3f3f3f);
            else
                vec.push_back(stoi(tmp));
        }
    }

    TreeNode *_deserialize(const vector<int> &data, int &idx) {
        if (data.empty() || idx >= data.size() || data[idx] == 0x3f3f3f3f)
            return nullptr;
        auto *cur = new TreeNode(data[idx]);
        cur->left = _deserialize(data, ++idx);
        cur->right = _deserialize(data, ++idx);
        return cur;
    }
};