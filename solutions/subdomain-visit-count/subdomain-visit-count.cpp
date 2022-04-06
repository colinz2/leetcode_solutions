// @Title: Subdomain Visit Count
// @Author: colinjxc
// @Date: 2019-10-03T13:08:23+08:00
// @URL: https://leetcode-cn.com/problems/subdomain-visit-count


class Solution {
public:
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<std::string, long> domain_table;
        for (auto& record : cpdomains) {
            auto space_index = record.find(" ");
            long count = std::stol(record.substr(0, space_index));
            std::string domain = record.substr(space_index + 1);
            domain_table[domain] += count;
            
            size_t pos = std::string::npos;
            while ((pos = domain.find(".")) != std::string::npos) {
                std::string sub_domain = domain.substr(pos + 1);
                domain = sub_domain;
                domain_table[domain] += count;
            }
        }
        
        vector<string> res;
        for (auto& kv : domain_table) {
            std::string r = std::to_string(kv.second) + " " + kv.first;
            res.emplace_back(r);
        }
        return res;
    }
};
