#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <tuple>

class ElevatorMonitor {
private:
    // Counters
    int light_on_count;
    int light_off_count;
    int person_entry_count;
    int person_exit_count;

    // Current state
    bool light_status;  // false = off, true = on
    int people_inside;

    // Timestamps for analysis - (timestamp, event_type, value)
    std::vector<std::tuple<time_t, std::string, int>> events;

public:
    ElevatorMonitor() :
        light_on_count(0),
        light_off_count(0),
        person_entry_count(0),
        person_exit_count(0),
        light_status(false),
        people_inside(0) {
    }

    void record_light_change(bool status, time_t timestamp) {
        if (status && !light_status) {  // Light turned on
            light_on_count++;
            events.push_back(std::make_tuple(timestamp, "light_on", 0));
        }
        else if (!status && light_status) {  // Light turned off
            light_off_count++;
            events.push_back(std::make_tuple(timestamp, "light_off", 0));
        }

        light_status = status;
    }

    void record_person_entry(time_t timestamp) {
        person_entry_count++;
        people_inside++;
        events.push_back(std::make_tuple(timestamp, "person_entry", people_inside));
    }

    void record_person_exit(time_t timestamp) {
        person_exit_count++;
        people_inside--;
        events.push_back(std::make_tuple(timestamp, "person_exit", people_inside));
    }

    std::map<std::string, int> get_statistics() {
        std::map<std::string, int> stats;
        stats["light_on_count"] = light_on_count;
        stats["light_off_count"] = light_off_count;
        stats["total_person_count"] = person_entry_count;
        stats["current_occupancy"] = people_inside;
        return stats;
    }

    std::map<std::string, double> analyze_correlation() {
        std::map<std::string, double> analysis;

        int light_events_count = 0;
        int person_events_count = 0;

        for (const auto& event : events) {
            std::string event_type = std::get<1>(event);
            if (event_type == "light_on" || event_type == "light_off") {
                light_events_count++;
            }
            else if (event_type == "person_entry" || event_type == "person_exit") {
                person_events_count++;
            }
        }

        analysis["light_events"] = light_events_count;
        analysis["person_events"] = person_events_count;
        analysis["ratio"] = person_events_count > 0 ?
            static_cast<double>(light_events_count) / person_events_count : 0;

        return analysis;
    }
};