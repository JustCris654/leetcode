class KthLargest {
private:
    vector<int> heap;
    int size = 0;

    int parent(int pos) { return (pos - 1) / 2; }

    int rightChild(int pos) { return pos * 2 + 1; }

    int leftChild(int pos) { return pos * 2 + 2; }

    void swap(int pos1, int pos2) {
        int tmp = heap[pos1];
        heap[pos1] = heap[pos2];
        heap[pos2] = tmp;
    }

    void insert(int n) {
        int pos;
        if (size < heap.size()) {
            pos = size++;
            heap[pos] = n;

            while (true) {
                if (pos == 0)
                    break;

                int p = parent(pos);
                if (heap[p] > n) {
                    swap(p, pos);
                    pos = p;
                } else {
                    break;
                }
            }
        } else {
            if (n <= heap[0]) return;
            
            pos = 0;
            heap[pos] = n;
            while (true) {
                int smallest = pos;

                int r = rightChild(pos);
                int l = leftChild(pos);

                if (r < heap.size() && heap[smallest] > heap[r]) {
                    smallest = r;
                }

                if (l < heap.size() && heap[smallest] > heap[l]) {
                    smallest = l;
                }

                if (smallest == pos) break;
                swap(smallest, pos);
                pos = smallest;
            }
        }
    }

public:
    KthLargest(int k, vector<int>& nums) : heap(k) {
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
        }
    }

    int add(int val) {
        insert(val);
        return heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
