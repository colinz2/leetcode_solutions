// @Title: Tenth Line
// @Author: colinjxc
// @Date: 2019-01-07T23:52:41+08:00
// @URL: https://leetcode-cn.com/problems/tenth-line


# Read from the file file.txt and output the tenth line to stdout.
awk 'NR==10{print $0}' file.txt


