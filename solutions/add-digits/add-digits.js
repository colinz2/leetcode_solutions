// @Title: Add Digits
// @Author: colinjxc
// @Date: 2021-10-29T11:11:00+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return (num - 1) % 9 + 1
};
