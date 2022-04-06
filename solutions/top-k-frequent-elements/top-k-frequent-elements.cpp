// @Title: Top K Frequent Elements
// @Author: colinjxc
// @Date: 2022-02-06T23:16:47+08:00
// @URL: https://leetcode-cn.com/problems/top-k-frequent-elements


class Solution {
public:
    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k) {
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked], v[start]);

        int pivot = v[start].second;
        int index = start;
        for (int i = start + 1; i <= end; i++) {
            if (v[i].second >= pivot) {
                swap(v[++index], v[i]);
            }
        }
        swap(v[start], v[index]);

        if (k <= index - start) {
            // have TOP(index-start+1), big then K
            qsort(v, start, index - 1, ret, k);
        } else {
            // have TOP(index-start+1), but small than K, take them all
            for (int i = start; i <= index; i++) {
                ret.push_back(v[i].first);
            }
            if (k > index - start + 1) {
                qsort(v, index + 1, end, ret, k - (index - start + 1));
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (auto& v: nums) {
            freqs[v]++;
        }

        vector<int> ret;
        vector<pair<int, int>> values(freqs.begin(), freqs.end());
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }
};

