struct SegmentTreeNode {
    int l, r;
    int max_capacity;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int l, int r) : l(l), r(r), max_capacity(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
private:
    SegmentTreeNode* root;
    vector<int>& data;

    SegmentTreeNode* build(int l, int r) {
        SegmentTreeNode* node = new SegmentTreeNode(l, r);
        if (l == r) {
            node->max_capacity = data[l];
            return node;
        }
        int mid = (l + r) / 2;
        node->left = build(l, mid);
        node->right = build(mid + 1, r);
        node->max_capacity = max(node->left->max_capacity, node->right->max_capacity);
        return node;
    }

    void update(SegmentTreeNode* node, int idx) {
        if (node->l == node->r) {
            node->max_capacity = -1;
            return;
        }
        int mid = (node->l + node->r) / 2;
        if (idx <= mid) {
            update(node->left, idx);
        } else {
            update(node->right, idx);
        }
        node->max_capacity = max(node->left->max_capacity, node->right->max_capacity);
    }

    int query(SegmentTreeNode* node, int q) {
        if (node->max_capacity < q) {
            return -1;
        }
        if (node->l == node->r) {
            return node->l;
        }
        if (node->left->max_capacity >= q) {
            int leftRes = query(node->left, q);
            if (leftRes != -1) {
                return leftRes;
            }
        }
        return query(node->right, q);
    }

public:
    SegmentTree(vector<int>& baskets) : data(baskets) {
        root = build(0, data.size() - 1);
    }

    int findLeftmost(int q) {
        return query(root, q);
    }

    void markUsed(int idx) {
        update(root, idx);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        if (n == 0) return 0;

        SegmentTree st(baskets);
        int unplaced = 0;

        for (int q : fruits) {
            int idx = st.findLeftmost(q);
            if (idx == -1) {
                unplaced++;
            } else {
                st.markUsed(idx);
            }
        }

        return unplaced;
    }
};