
# [数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array)

## 题目描述

<p>给定整数数组 <code>nums</code> 和整数 <code>k</code>，请返回数组中第 <code><strong>k</strong></code> 个最大的元素。</p>

<p>请注意，你需要找的是数组排序后的第 <code>k</code> 个最大的元素，而不是第 <code>k</code> 个不同的元素。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>[3,2,1,5,6,4] 和</code> k = 2
<strong>输出:</strong> 5
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> <code>[3,2,3,1,2,4,5,5,6] 和</code> k = 4
<strong>输出:</strong> 4</pre>

<p> </p>

<p><strong>提示： </strong></p>

<ul>
	<li><code>1 <= k <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>


## 题解

### cpp [🔗](kth-largest-element-in-an-array.cpp) 
```cpp
class Solution {
private:
    int FindKthLargest_(vector<int> &nums, int k,  int l, int r) {
        if (l >= r) {
            return nums[l];
        }

        int p = Partition(nums, l, r);
        if (p < k) {
            return FindKthLargest_(nums, k, p + 1, r);
        } else if (p > k) {
            return FindKthLargest_(nums, k, l, p - 1);
        } else {
            return nums[p];
        }
    }
    
    int Partition(vector<int> &nums, int l, int r) {
        int ri = random() % (r - l) + l;
        std::swap(nums[l], nums[ri]);

        int pv = nums[l];
        int p = l;

        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > pv) {
                std::swap(nums[++p], nums[i]);
            }
        }
        std::swap(nums[p], nums[l]);
        return p;
    }
    
public:
    int findKthLargest(vector<int> &nums, int k) {
        int r = FindKthLargest_(nums, k - 1, 0, nums.size() - 1);
        return r;
    }
};
```
### golang [🔗](kth-largest-element-in-an-array.go) 
```golang
// 降序
func partioin(nums []int, l int,  r int) int {
    ri := rand.Intn(r-l) % (r-l) + l
    nums[ri], nums[l] = nums[l],nums[ri]
    pv := nums[l]

    i, j := l + 1, r
    for {
        for nums[i] > pv && i < r {
            i++
        }
        for nums[j] < pv && j > l {
            j--
        }

        if i >= j {
            break
        }
        
        nums[i], nums[j] = nums[j], nums[i]
        i++
        j--
    }
    nums[l], nums[j] = nums[j], nums[l]
    return j
}

func findKthLargest0(nums []int, k, l, r int) int {
    if l == r {
        return nums[k]
    }

    p := partioin(nums, l, r)
    if (p > k) {
        return findKthLargest0(nums, k, l, p - 1)
    } else if (p < k) {
        return findKthLargest0(nums, k, p + 1, r)
    } else {
        return nums[p]
    }
}


func findKthLargest(nums []int, k int) int {
    return findKthLargest0(nums, k-1, 0, len(nums) - 1)
}
```
### python3 [🔗](kth-largest-element-in-an-array.py) 
```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(nums, l, r) -> int:
            xx = random.randint(l, r)
            nums[xx], nums[l] = nums[l], nums[xx]
 
            p = l + 1
            for index in range(l+1, r+1):
                # 降序排序，如果发现大的就交换
                if nums[index] > nums[l]:
                    nums[p], nums[index] = nums[index], nums[p]
                    p = p + 1
            # 这块要注意啊，是 p - 1
            nums[p - 1], nums[l] = nums[l], nums[p -1]
            return p-1

    
        def findKth(nums, l, r, k) -> int:
            if l == r:
                return nums[l]

            p = partition(nums, l, r)                
            if p > k :
                return findKth(nums, l, p-1, k)
            elif p < k :
                return findKth(nums, p+1, r, k)
            return nums[k]


        return findKth(nums, 0, len(nums)-1, k -1)

        

    
```


## 相关话题

- [数组](../../tags/array.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [快速选择](../../tags/quickselect.md) 
- [排序](../../tags/sorting.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 


## 相似题目

- [前 K 个高频元素](../top-k-frequent-elements/README.md)  [Medium] 
- [数据流中的第 K 大元素](../kth-largest-element-in-a-stream/README.md)  [Easy] 


## Links

- [Prev](../house-robber-ii/README.md) 
- [Next](../contains-duplicate/README.md) 

