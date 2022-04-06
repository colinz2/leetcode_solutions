// @Title: Unique Email Addresses
// @Author: colinjxc
// @Date: 2018-12-12T15:27:58+08:00
// @URL: https://leetcode-cn.com/problems/unique-email-addresses


func numUniqueEmails(emails []string) int {
	seen := make(map[string]bool)
	for _, email := range emails {
		comp := strings.Split(email, "@")
		if len(comp) == 2 {
			comp[0] = strings.Split(comp[0], "+")[0]
			comp[0] = strings.Replace(comp[0], ".", "", -1)
			finalEmail := strings.Join(comp, "@")
			fmt.Println(finalEmail)
			seen[finalEmail] = true
		}
	}
	return len(seen)
}
