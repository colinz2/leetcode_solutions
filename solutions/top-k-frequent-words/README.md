
# [](https://leetcode-cn.com/problems/top-k-frequent-words)

## 题目描述



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



## 相似题目



## Links

- [Prev](../redundant-connection/README.md) 
- [Next](../count-binary-substrings/README.md) 

