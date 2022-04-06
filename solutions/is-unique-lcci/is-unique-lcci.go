// @Title: Is Unique LCCI
// @Author: colinjxc
// @Date: 2021-07-18T23:46:53+08:00
// @URL: https://leetcode-cn.com/problems/is-unique-lcci


func isUnique(astr string) bool {
    var mask uint32
    for i := range astr {
        bitN := uint32(1 << int(astr[i] - 'a'))
        if bitN & mask > 0 {
            return false
        }
        mask |= bitN
    }
    return true
}
