// @Title: Unique Email Addresses
// @Author: colinjxc
// @Date: 2018-12-12T15:43:31+08:00
// @URL: https://leetcode-cn.com/problems/unique-email-addresses


class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        seen = set()
        for email in emails:
            sep = email.split("@")
            sep[0] = sep[0].split("+")[0]
            sep[0] = sep[0].replace(".", "")

            seen.add("@".join(sep))
        return len(seen)
