import heapq
class User(object):
    def __init__(self, user_id):
        self.id = user_id
        self.tweets = []  # List of tweet IDs
        self.follows = set()  # Set of user IDs

    def add_tweet(self, tweet_id, timestamp):
        self.tweets.append((timestamp, tweet_id))

    def get_tweets(self):
        return self.tweets

    def add_follow(self, followee_id):
        self.follows.add(followee_id)

    def remove_follow(self, followee_id):
        self.follows.discard(followee_id)

    def get_follows(self):
        return self.follows

class Twitter(object):
    def __init__(self):
        self.users = {}
        self.timestamp = 0  # Initialize a timestamp counter

    def find_user(self, userId):
        if userId not in self.users:
            self.users[userId] = User(userId)
        return self.users[userId]

    def postTweet(self, userId, tweetId):
        self.timestamp += 1  # Increment the timestamp for each new tweet
        poster = self.find_user(userId)
        poster.add_tweet(tweetId, self.timestamp)

    def getNewsFeed(self, userId):
        user = self.find_user(userId)
        tweets = []
        tweets.extend(user.get_tweets())

        for followed_user_id in user.get_follows():
            followed_user = self.find_user(followed_user_id)
            tweets.extend(followed_user.get_tweets())

        # Sort by timestamp and take the 10 most recent
        output = heapq.nlargest(10, tweets, key=lambda x: x[0])
        return [tweet_id for _, tweet_id in output]
    
    def follow(self, followerId, followeeId):
        user = self.find_user(followerId)
        user.add_follow(followeeId)

    def unfollow(self, followerId, followeeId):
        user = self.find_user(followerId)
        user.remove_follow(followeeId)