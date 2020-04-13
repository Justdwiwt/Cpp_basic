#include <list>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int RECENT_TWEETS = 10;

struct Tweets {
    int time;
    int id;

    explicit Tweets(const int &_time = int(), const int &_id = int()) : time(_time), id(_id) {}

    bool operator<(const Tweets &rhs) const { return rhs.time < time; }

    bool operator<(Tweets &rhs) { return rhs.time < time; }
};

class Twitter {
    int curTime;
    unordered_map<int, list<Tweets> > posts;
    unordered_map<int, unordered_set<int> > followers;
public:
    /** Initialize your data structure here. */
    Twitter() {
        curTime = int();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (posts.end() == posts.find(userId)) posts.insert(make_pair(userId, list<Tweets>()));
        list<Tweets> &l = posts.at(userId);
        if (l.size() == RECENT_TWEETS) l.pop_back();
        l.push_front(Tweets(curTime++, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by
     * users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweets> pq;
        for (Tweets tweet : posts[userId]) pq.push(tweet);
        for (int iter : followers[userId])
            for (Tweets tweet : posts[iter])
                if (pq.size() == RECENT_TWEETS) {
                    if (pq.top().time < tweet.time) {
                        pq.pop();
                        pq.push(tweet);
                    } else break;
                } else pq.push(tweet);
        vector<int> ans;
        while (!pq.empty()) {
            ans.insert(ans.begin(), pq.top().id);
            pq.pop();
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followers[followerId].erase(followeeId);
    }
};
