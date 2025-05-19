#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

// The interface of a remote service
class ThirdPartyYouTubeLib {
public:
    virtual ~ThirdPartyYouTubeLib() = default;
    virtual std::vector<std::string> listVideos() = 0;
    virtual std::string getVideoInfo(const std::string& id) = 0;
    virtual void downloadVideo(const std::string& id) = 0;
};

// The concrete implementation of a service connector
class ThirdPartyYouTubeClass : public ThirdPartyYouTubeLib {
public:
    std::vector<std::string> listVideos() override {
        std::cout << "Sending API request to YouTube for video list...\n";
        // Simulate network delay
        std::cout << "Downloading video list from YouTube...\n";

        // Return some dummy data
        return { "Video 1", "Video 2", "Video 3" };
    }

    std::string getVideoInfo(const std::string& id) override {
        std::cout << "Getting metadata for video " << id << " from YouTube...\n";
        // Simulate network delay

        // Return some dummy data
        return "Video " + id + " info: Title, Duration, etc.";
    }

    void downloadVideo(const std::string& id) override {
        std::cout << "Downloading video " << id << " from YouTube...\n";
        // Simulate network delay
    }
};

// Proxy class that implements caching
class CachedYouTubeClass : public ThirdPartyYouTubeLib {
private:
    std::unique_ptr<ThirdPartyYouTubeLib> service;
    std::vector<std::string> listCache;
    std::unordered_map<std::string, std::string> videoCache;
    std::unordered_map<std::string, bool> downloadCache;
    bool needReset;

public:
    explicit CachedYouTubeClass(std::unique_ptr<ThirdPartyYouTubeLib> service)
        : service(std::move(service)), needReset(false) {
    }

    std::vector<std::string> listVideos() override {
        if (listCache.empty() || needReset) {
            std::cout << "Cache miss for video list. Fetching from service...\n";
            listCache = service->listVideos();
        }
        else {
            std::cout << "Returning cached video list...\n";
        }
        return listCache;
    }

    std::string getVideoInfo(const std::string& id) override {
        if (videoCache.find(id) == videoCache.end() || needReset) {
            std::cout << "Cache miss for video " << id << " info. Fetching from service...\n";
            videoCache[id] = service->getVideoInfo(id);
        }
        else {
            std::cout << "Returning cached info for video " << id << "...\n";
        }
        return videoCache[id];
    }

    void downloadVideo(const std::string& id) override {
        if (downloadCache.find(id) == downloadCache.end() || needReset) {
            std::cout << "Cache miss for video " << id << " download. Downloading from service...\n";
            service->downloadVideo(id);
            downloadCache[id] = true;
        }
        else {
            std::cout << "Video " << id << " already downloaded, using cached version...\n";
        }
    }

    void reset() {
        needReset = true;
    }
};

// The GUI class
class YouTubeManager {
protected:
    ThirdPartyYouTubeLib* service;

public:
    explicit YouTubeManager(ThirdPartyYouTubeLib* service) : service(service) {}

    void renderVideoPage(const std::string& id) {
        std::string info = service->getVideoInfo(id);
        std::cout << "Rendering video page with info: " << info << std::endl;
    }

    void renderListPanel() {
        std::vector<std::string> list = service->listVideos();
        std::cout << "Rendering list panel with videos:" << std::endl;
        for (const auto& video : list) {
            std::cout << "  - " << video << std::endl;
        }
    }

    void reactOnUserInput() {
        renderVideoPage("1");
        renderListPanel();
    }
};

// The application class
class Application {
public:
    void init() {
        // Create the real service
        auto youTubeService = std::make_unique<ThirdPartyYouTubeClass>();

        // Create a proxy that wraps the real service
        auto youTubeProxy = std::make_unique<CachedYouTubeClass>(std::move(youTubeService));

        // Create the manager with the proxy
        YouTubeManager manager(youTubeProxy.get());

        // Use the manager
        std::cout << "First request (will use real service):" << std::endl;
        manager.reactOnUserInput();

        std::cout << "\nSecond request (will use cache):" << std::endl;
        manager.reactOnUserInput();

        // Reset the cache
        youTubeProxy->reset();

        std::cout << "\nThird request after reset (will use real service again):" << std::endl;
        manager.reactOnUserInput();
    }
};

int main() {
    Application app;
    app.init();
    return 0;
}


//output :
//First request(will use real service) :
//    Cache miss for video 1 info.Fetching from service...
//    Getting metadata for video 1 from YouTube...
//    Rendering video page with info : Video 1 info : Title, Duration, etc.
//    Cache miss for video list.Fetching from service...
//    Sending API request to YouTube for video list...
//    Downloading video list from YouTube...
//    Rendering list panel with videos :
//- Video 1
//- Video 2
//- Video 3
//
//Second request(will use cache) :
//    Returning cached info for video 1...
//    Rendering video page with info : Video 1 info : Title, Duration, etc.
//    Returning cached video list...
//    Rendering list panel with videos :
//- Video 1
//- Video 2
//- Video 3
//
//Third request after reset(will use real service again) :
//    Cache miss for video 1 info.Fetching from service...
//    Getting metadata for video 1 from YouTube...
//    Rendering video page with info : Video 1 info : Title, Duration, etc.
//    Cache miss for video list.Fetching from service...
//    Sending API request to YouTube for video list...
//    Downloading video list from YouTube...
//    Rendering list panel with videos :
//- Video 1
//- Video 2
//- Video 3
