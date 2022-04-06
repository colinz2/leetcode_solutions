// @Title: Encode and Decode TinyURL
// @Author: colinjxc
// @Date: 2018-12-05T12:41:23+08:00
// @URL: https://leetcode-cn.com/problems/encode-and-decode-tinyurl


class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        url.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(url.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto pos = shortUrl.find_last_of("/");
        return url[stoi(shortUrl.substr(pos + 1))];
    }
    
private:
    vector<string> url;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
