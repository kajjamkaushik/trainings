#include <map>
#include <ctime>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class TimeSeriesAnalyzer {
private:
    // Hour of day -> event counts
    std::map<int, std::map<std::string, int>> hourly_patterns;

public:
    void analyze_events(const std::vector<std::tuple<time_t, std::string, int>>& events) {
        for (const auto& event : events) {
            time_t timestamp = std::get<0>(event);
            std::string event_type = std::get<1>(event);

            // Convert timestamp to hour of day
            struct tm* timeinfo = localtime(&timestamp);
            int hour = timeinfo->tm_hour;

            // Increment appropriate counter
            if (event_type == "light_on") {
                hourly_patterns[hour]["light_on"]++;
            }
            else if (event_type == "person_entry") {
                hourly_patterns[hour]["person_entry"]++;
            }
        }
    }

    void print_hourly_patterns() {
        std::cout << "Hour\tLight On\tPerson Entry" << std::endl;
        for (int hour = 0; hour < 24; hour++) {
            std::cout << hour << "\t"
                << hourly_patterns[hour]["light_on"] << "\t\t"
                << hourly_patterns[hour]["person_entry"] << std::endl;
        }
    }

    int get_busiest_hour() {
        int busiest_hour = 0;
        int max_entries = 0;

        for (const auto& entry : hourly_patterns) {
            int hour = entry.first;
            int entries = entry.second.at("person_entry");

            if (entries > max_entries) {
                max_entries = entries;
                busiest_hour = hour;
            }
        }

        return busiest_hour;
    }
};