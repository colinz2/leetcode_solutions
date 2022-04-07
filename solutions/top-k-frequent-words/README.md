
# [前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words)

## 题目描述

<p>给定一个单词列表&nbsp;<code>words</code>&nbsp;和一个整数 <code>k</code> ，返回前&nbsp;<code>k</code><em>&nbsp;</em>个出现次数最多的单词。</p>

<p>返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， <strong>按字典顺序</strong> 排序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
<strong>输出:</strong> ["i", "love"]
<strong>解析:</strong> "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
<strong>输出:</strong> ["the", "is", "sunny", "day"]
<strong>解析:</strong> "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 500</code></li>
	<li><code>1 &lt;= words[i] &lt;= 10</code></li>
	<li><code>words[i]</code>&nbsp;由小写英文字母组成。</li>
	<li><code>k</code> 的取值范围是&nbsp;<code>[1, <strong>不同</strong> words[i] 的数量]</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>尝试以&nbsp;<code>O(n log k)</code> 时间复杂度和&nbsp;<code>O(n)</code> 空间复杂度解决。</p>


## 题解

### golang [🔗](top-k-frequent-words.go) 
```golang
// 升序
func insertSortAppend(array []string, key string) []string {
	array = append(array, key)
	for i := 0; i < len(array)-1; i++ {
		if array[i] > key {
			for j := len(array) - 1; j != i; j-- {
				array[j] = array[j-1]
			}
			array[i] = key
			return array
		}
	}
	return array
}

func topKFrequent(words []string, k int) []string {
	var res []string
	wordsLen := len(words)
	if wordsLen == 0 {
		return res
	}
	m := make(map[string]int)
	b := make([][]string, wordsLen + 1)
	for _, w := range words {
		m[w]++
	}

	for k, v := range m {
		b[v] = insertSortAppend(b[v], k)
	}

	for i := wordsLen; i != 0; i-- {
		for _, word := range b[i] {
			res = append(res, word)
			if len(res) == k {
				return res
			}
		}
	}
	return nil
}

```


## 相关话题

- [字典树](../../tags/trie.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [桶排序](../../tags/bucket-sort.md) 
- [计数](../../tags/counting.md) 
- [排序](../../tags/sorting.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 


## 相似题目

- [前 K 个高频元素](../top-k-frequent-elements/README.md)  [Medium] 


## Links

- [Prev](../redundant-connection/README.md) 
- [Next](../count-binary-substrings/README.md) 

