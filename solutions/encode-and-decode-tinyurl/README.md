
# [TinyURL 的加密与解密](https://leetcode-cn.com/problems/encode-and-decode-tinyurl)

## 题目描述

<p>TinyURL是一种URL简化服务， 比如：当你输入一个URL&nbsp;<code>https://leetcode.com/problems/design-tinyurl</code>&nbsp;时，它将返回一个简化的URL&nbsp;<code>http://tinyurl.com/4e9iAk</code>.</p>

<p>要求：设计一个 TinyURL 的加密&nbsp;<code>encode</code>&nbsp;和解密&nbsp;<code>decode</code>&nbsp;的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。</p>


## 题解

### cpp [🔗](encode-and-decode-tinyurl.cpp) 
```cpp
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
```


## 相关话题

- [设计](../../tags/design.md) 
- [哈希表](../../tags/hash-table.md) 
- [字符串](../../tags/string.md) 
- [哈希函数](../../tags/hash-function.md) 


## 相似题目



## Links

- [Prev](../continuous-subarray-sum/README.md) 
- [Next](../convert-bst-to-greater-tree/README.md) 

