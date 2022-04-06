// @Title: Letter Combinations of a Phone Number
// @Author: colinjxc
// @Date: 2021-05-23T22:38:32+08:00
// @URL: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number


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
