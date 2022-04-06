// @Title: Top K Frequent Words
// @Author: colinjxc
// @Date: 2021-05-20T15:08:44+08:00
// @URL: https://leetcode-cn.com/problems/top-k-frequent-words


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

