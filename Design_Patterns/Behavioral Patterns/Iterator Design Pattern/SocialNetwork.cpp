#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

// Forward declarations
class Profile;
class ProfileIterator;
class Facebook;

// Profile class to represent user profiles
class Profile {
private:
    std::string id;
    std::string email;
    std::string name;

public:
    Profile(const std::string& id, const std::string& email, const std::string& name)
        : id(id), email(email), name(name) {
    }

    std::string getId() const { return id; }
    std::string getEmail() const { return email; }
    std::string getName() const { return name; }
};

// The common interface for all iterators
class ProfileIterator {
public:
    virtual ~ProfileIterator() = default;
    virtual Profile* getNext() = 0;
    virtual bool hasMore() = 0;
};

// The collection interface
class SocialNetwork {
public:
    virtual ~SocialNetwork() = default;
    virtual std::unique_ptr<ProfileIterator> createFriendsIterator(const std::string& profileId) = 0;
    virtual std::unique_ptr<ProfileIterator> createCoworkersIterator(const std::string& profileId) = 0;
};

// Concrete implementation of Facebook iterator
class FacebookIterator : public ProfileIterator {
private:
    Facebook* facebook;
    std::string profileId;
    std::string type;
    int currentPosition = 0;
    std::vector<Profile*> cache;
    bool cacheInitialized = false;

    void lazyInit();

public:
    FacebookIterator(Facebook* facebook, const std::string& profileId, const std::string& type)
        : facebook(facebook), profileId(profileId), type(type) {
    }

    Profile* getNext() override;
    bool hasMore() override;
};

// Concrete implementation of SocialNetwork
class Facebook : public SocialNetwork {
private:
    std::vector<Profile*> profiles;
    std::unordered_map<std::string, std::vector<std::string>> connections;

public:
    Facebook() {
        // Add some test data
        addProfile(new Profile("1", "alice@example.com", "Alice"));
        addProfile(new Profile("2", "bob@example.com", "Bob"));
        addProfile(new Profile("3", "charlie@example.com", "Charlie"));
        addProfile(new Profile("4", "dave@example.com", "Dave"));

        addConnection("1", "friends", "2");
        addConnection("1", "friends", "3");
        addConnection("1", "coworkers", "4");
        addConnection("2", "coworkers", "3");
    }

    ~Facebook() {
        for (auto profile : profiles) {
            delete profile;
        }
    }

    void addProfile(Profile* profile) {
        profiles.push_back(profile);
    }

    void addConnection(const std::string& profileId, const std::string& type, const std::string& friendId) {
        std::string connectionKey = profileId + ":" + type;
        connections[connectionKey].push_back(friendId);
    }

    Profile* getProfileById(const std::string& profileId) {
        for (auto profile : profiles) {
            if (profile->getId() == profileId) {
                return profile;
            }
        }
        return nullptr;
    }

    std::vector<Profile*> socialGraphRequest(const std::string& profileId, const std::string& type) {
        std::cout << "Facebook: Loading " << type << " for user ID: " << profileId << std::endl;

        // Simulate API delay
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        std::string connectionKey = profileId + ":" + type;
        std::vector<Profile*> result;

        if (connections.find(connectionKey) != connections.end()) {
            for (const auto& friendId : connections[connectionKey]) {
                result.push_back(getProfileById(friendId));
            }
        }

        return result;
    }

    std::unique_ptr<ProfileIterator> createFriendsIterator(const std::string& profileId) override {
        return std::make_unique<FacebookIterator>(this, profileId, "friends");
    }

    std::unique_ptr<ProfileIterator> createCoworkersIterator(const std::string& profileId) override {
        return std::make_unique<FacebookIterator>(this, profileId, "coworkers");
    }

    friend class FacebookIterator;
};

// Implementation of FacebookIterator methods
void FacebookIterator::lazyInit() {
    if (!cacheInitialized) {
        cache = facebook->socialGraphRequest(profileId, type);
        cacheInitialized = true;
    }
}

Profile* FacebookIterator::getNext() {
    if (hasMore()) {
        return cache[currentPosition++];
    }
    return nullptr;
}

bool FacebookIterator::hasMore() {
    lazyInit();
    return currentPosition < cache.size();
}

// Client that uses the iterator
class SocialSpammer {
public:
    void send(ProfileIterator* iterator, const std::string& message) {
        while (iterator->hasMore()) {
            Profile* profile = iterator->getNext();
            std::cout << "Sending email to: " << profile->getEmail() << std::endl;
            std::cout << "Message: " << message << std::endl;
            std::cout << std::endl;
        }
    }
};

// Application class
class Application {
private:
    std::unique_ptr<SocialNetwork> network;
    std::unique_ptr<SocialSpammer> spammer;

public:
    void config(const std::string& networkType) {
        if (networkType == "Facebook") {
            network = std::make_unique<Facebook>();
        }
        // You can add LinkedIn implementation here
        spammer = std::make_unique<SocialSpammer>();
    }

    void sendSpamToFriends(Profile* profile) {
        std::cout << "Sending spam to friends of " << profile->getName() << std::endl;
        auto iterator = network->createFriendsIterator(profile->getId());
        spammer->send(iterator.get(), "Very important message for friends");
    }

    void sendSpamToCoworkers(Profile* profile) {
        std::cout << "Sending spam to coworkers of " << profile->getName() << std::endl;
        auto iterator = network->createCoworkersIterator(profile->getId());
        spammer->send(iterator.get(), "Very important message for coworkers");
    }
};

int main() {
    Application app;
    app.config("Facebook");

    // Create a test profile
    Profile aliceProfile("1", "alice@example.com", "Alice");

    // Send spam to friends and coworkers
    app.sendSpamToFriends(&aliceProfile);
    app.sendSpamToCoworkers(&aliceProfile);

    return 0;
}


///output:
//Sending spam to friends of Alice
//Facebook : Loading friends for user ID : 1
//Sending email to : bob@example.com
//Message : Very important message for friends
//
//Sending email to : charlie@example.com
//Message : Very important message for friends
//
//Sending spam to coworkers of Alice
//Facebook : Loading coworkers for user ID : 1
//Sending email to : dave@example.com
//Message : Very important message for coworkers