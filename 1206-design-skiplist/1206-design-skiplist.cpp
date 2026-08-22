class Skiplist {
    static const int MAX_LEVEL = 16;

    struct Node {
        int val;
        vector<Node*> next;

        Node(int val, int level) : val(val), next(level, nullptr) {}
    };

    Node* head;

    int randomLevel() {
        int level = 1;

        while ((rand() & 1) && level < MAX_LEVEL)
            level++;

        return level;
    }

    Node* findPrev(int target, vector<Node*>& update) {
        Node* cur = head;

        for (int level = MAX_LEVEL - 1; level >= 0; level--) {
            while (
                cur->next[level] &&
                cur->next[level]->val < target
            ) {
                cur = cur->next[level];
            }

            update[level] = cur;
        }

        return cur;
    }

public:
    Skiplist() {
        head = new Node(-1, MAX_LEVEL);
        srand(time(nullptr));
    }

    bool search(int target) {
        Node* cur = head;

        for (int level = MAX_LEVEL - 1; level >= 0; level--) {
            while (
                cur->next[level] &&
                cur->next[level]->val < target
            ) {
                cur = cur->next[level];
            }
        }

        cur = cur->next[0];

        return cur && cur->val == target;
    }

    void add(int num) {
        vector<Node*> update(MAX_LEVEL);

        findPrev(num, update);

        int level = randomLevel();
        Node* node = new Node(num, level);

        for (int i = 0; i < level; i++) {
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }

    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL);

        findPrev(num, update);

        Node* target = update[0]->next[0];

        if (!target || target->val != num)
            return false;

        for (int i = 0; i < MAX_LEVEL; i++) {
            if (update[i]->next[i] != target)
                break;

            update[i]->next[i] = target->next[i];
        }

        delete target;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */