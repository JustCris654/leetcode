class Solution {

private:
    int pivot(vector<int>& nums, int first, int last) {
        int x = nums[first];
        int j = first;
        for (int i = first; i <= last; i++) {
            if (nums[i] < x) {
                j++;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        nums[first] = nums[j];
        nums[j] = x;
        return j;
    }

public:
    int selection(vector<int>& nums, int first, int last, int k) {
        if (first == last) return nums[first];

        int j = pivot(nums, first, last);

        int eqEnd = j;
        for (int i = j + 1; i <= last; i++) {
            if (nums[i] == nums[j]) {
                eqEnd++;
                int tmp = nums[i];
                nums[i] = nums[eqEnd];
                nums[eqEnd] = tmp;
            }
        }

        int qMax = last - j + 1;
        int qMin = last - eqEnd + 1;
        if (k <= qMax && k >= qMin) {
            return nums[j];
        } else if (k > qMax) {
            return selection(nums, first, j-1, k - qMax);
        } else {
            return selection(nums, eqEnd+1, last, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int prev = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > prev) {
                return selection(nums, 0, nums.size() - 1, k);
            } else {
                prev = nums[i];
            }
        }

        return nums[k - 1];
    }
};
