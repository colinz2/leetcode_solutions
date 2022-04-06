// @Title: Design Twitter
// @Author: colinjxc
// @Date: 2022-02-04T23:28:04+08:00
// @URL: https://leetcode-cn.com/problems/design-twitter


class Twitter {
public:
    struct Tweet {
        int time;
        int tweet_id;
        Tweet() : time(0), tweet_id(-1) {}
        Tweet(int tw, int t) : tweet_id(tw), time(t) {}
    };

    class User {
    public:
        User(int id) : id_(id) {}

        bool Follow(int user_id) {
            if (user_id != id_) {
                if (follows_.count(user_id)) {
                    return true;
                }
                follows_.insert(user_id);
                return true;
            }
            return false;
        }

        void UnFollow(int user_id) {
            follows_.erase(user_id);
        }

        void Tweet(int tweetId, int time) {
            Twitter::Tweet *twee = new Twitter::Tweet(tweetId, time);
            tweets_.push_front(twee);
        }

        std::set<int>& Followees() {
            return follows_;
        }

        std::list<Twitter::Tweet*>& Tweets() {
            return tweets_;
        }

    private:
        int id_;
        std::set<int> follows_;
        std::list<Twitter::Tweet*> tweets_;
    };

public:
    Twitter() : time_(0) {

    }
    
    void postTweet(int userId, int tweetId) {
        User* user = nullptr;
        auto it = users_.find(userId);
        if (it == users_.end()) {
            user = new User(userId);
            users_.insert({userId, user});
        } else {
            user = it->second;
        }
        user->Tweet(tweetId, ++time_);
    }
    
    vector<int> getNewsFeed(int userId) {
        std::vector<int> news;
        if (users_.count(userId) == 0) {
            return news;
        }

        std::vector<User*> users;
        auto self = users_[userId];
        users.push_back(self);
        for (int id : self->Followees()) {
            if (users_.count(id)) {
                users.push_back(users_[id]);
            }
        }

        using TweetIterator = std::list<Tweet*>::iterator;
        struct UserTweetIter {
            TweetIterator curr;
            TweetIterator end;
        };
        struct cmp {
            bool operator()(const UserTweetIter a, const UserTweetIter b) {
                return (*a.curr)->time < (*b.curr)->time;
            }
        };

        std::priority_queue<UserTweetIter, std::vector<UserTweetIter>, cmp> pq;
        for (auto user : users) {
            if (user->Tweets().size() > 0) {
                pq.push(UserTweetIter{.curr = user->Tweets().begin(), .end = user->Tweets().end()});
            }
        }

        while (!pq.empty() && news.size() < 10) {
            UserTweetIter userIter = pq.top();
            pq.pop();
            news.push_back((*(userIter.curr))->tweet_id);
            if (++userIter.curr != userIter.end) {
                pq.push(userIter);
            }
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        auto it = users_.find(followerId);
        if (it == users_.end()) {
            auto follower = new User(followerId);
            users_[followerId] = follower;
            follower->Follow(followeeId); 
        } else {
            it->second->Follow(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = users_.find(followerId);
        if (it != users_.end()) {
            it->second->UnFollow(followeeId);
        }
    }
private:
    int time_;
    unordered_map<int, User*> users_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
