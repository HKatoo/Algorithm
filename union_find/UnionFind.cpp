#include <vector>
using namespace std;

struct UnionFind {
    //親の番号を格納する．
    //該当番号が親の場合は -(その集合のサイズ）
    vector<int> parent;
    UnionFind(int size) {
        parent = vector<int>(size, -1);
    }
    int root(int a) {
        if (parent[a] < 0) {
            return a;
        } else {
            return parent[a] = root(parent[a]);
        }
    }
    int size(int a) {
        return -parent[root(a)];
    }
    bool merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) {
            return false;
        } else {
            if (size(a) < size(b)) {
                swap(a, b);
            }
            parent[a] += parent[b];
            parent[b] = a;
            return true;
        }
    }
};
