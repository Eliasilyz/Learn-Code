class Allocator {
private:
    vector<int> mem;

public:
    Allocator(int n) {
        mem.assign(n, 0);
    }

    int allocate(int size, int mID) {
        int n = mem.size();

        for (int i = 0; i <= n - size; i++) {
            bool free = true;

            for (int j = i; j < i + size; j++) {
                if (mem[j] != 0) {
                    free = false;
                    break;
                }
            }

            if (free) {
                for (int j = i; j < i + size; j++) {
                    mem[j] = mID;
                }

                return i;
            }
        }

        return -1;
    }

    int freeMemory(int mID) {
        int freed = 0;

        for (int i = 0; i < mem.size(); i++) {
            if (mem[i] == mID) {
                mem[i] = 0;
                freed++;
            }
        }

        return freed;
    }
};