
# [电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number)

## 题目描述

<p>给定一个仅包含数字&nbsp;<code>2-9</code>&nbsp;的字符串，返回所有它能表示的字母组合。答案可以按 <strong>任意顺序</strong> 返回。</p>

<p>给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png" style="width: 200px;" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = "23"
<strong>输出：</strong>["ad","ae","af","bd","be","bf","cd","ce","cf"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = ""
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = "2"
<strong>输出：</strong>["a","b","c"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= digits.length &lt;= 4</code></li>
	<li><code>digits[i]</code> 是范围 <code>['2', '9']</code> 的一个数字。</li>
</ul>


## 题解

### cpp [🔗](letter-combinations-of-a-phone-number.cpp) 
```cpp
class Solution {
private:
    string digitStr[10] = {"", "", "abc", "def", "ghi", 
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        dfs(0, digits, "", res);
        return res;
    }

    void dfs(int index, string& digits, const string& tmp, vector<string>& res) {
        if (digits.size() == 0) return;
        if (index == digits.size()) {
            res.emplace_back(tmp);
            return;
        }
        int num = digits[index] - '0';
        for (auto& ch : digitStr[num]) {
            dfs(index + 1, digits, tmp + ch, res);
        }
    }
};
```
### golang [🔗](letter-combinations-of-a-phone-number.go) 
```golang
var (
	letterMap = []string{
		" ",    //0
		"",     //1
		"abc",  //2
		"def",  //3
		"ghi",  //4
		"jkl",  //5
		"mno",  //6
		"pqrs", //7
		"tuv",  //8
		"wxyz", //9
	}
)

func findCombinations(digits *string, index int, combine string, res *[]string) {
	if len(*digits) == index {
		*res = append(*res, combine)
		return
	}
	digit := (*digits)[index] - '0'
	digitLetters := letterMap[digit]

	for i := 0; i < len(digitLetters); i++ {
		findCombinations(digits, index+1, combine+string(digitLetters[i]), res)
	}
}

func letterCombinations(digits string) []string {
	var res []string
	if len(digits) == 0 {
		return res
	}
	findCombinations(&digits, 0, "", &res)
	return res
}
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [回溯](https://leetcode-cn.com/tag/backtracking) 


## 相似题目

- [括号生成](../generate-parentheses/README.md)  [Medium] 
- [组合总和](../combination-sum/README.md)  [Medium] 


## Links

- [Prev](../3sum/README.md) 
- [Next](../remove-nth-node-from-end-of-list/README.md) 

