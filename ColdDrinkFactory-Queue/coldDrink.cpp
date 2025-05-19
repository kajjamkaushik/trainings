#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <cmath>

// Constants for verification tolerances
const double LEVEL_TOLERANCE = 5.0;    // 5ml tolerance
const double WEIGHT_TOLERANCE = 8.0;   // 8g tolerance
const double EMPTY_BOTTLE_WEIGHT = 25.0; // 25g for empty bottle

// Bottle status enum
enum BottleStatus {
    EMPTY,
    FILLING,
    FILLED,
    CAPPED,
    REJECTED
};

// Fill state enum for the filling station - RENAMED to avoid conflicts
enum FillState {
    FS_READY,        // Changed from READY
    FS_FILLING,      // Changed from FILLING
    FS_VERIFYING,    // Changed from VERIFYING
    FS_COMPLETE,     // Changed from COMPLETE
    FS_ERROR         // Changed from ERROR
};

// Sensor reading structure
struct SensorReading {
    double value;
    std::string sensorType;
    time_t timestamp;

    SensorReading(double val, const std::string& type)
        : value(val), sensorType(type), timestamp(time(nullptr)) {
    }
};

// Bottle class to represent each bottle in the system
class Bottle {
private:
    static int nextId;
    int bottleId;
    double targetFillLevel;
    double currentFillLevel;
    time_t timeEntered;
    BottleStatus status;
    std::vector<SensorReading> sensorReadings;

public:
    Bottle(double targetLevel = 330.0)
        : bottleId(nextId++),
        targetFillLevel(targetLevel),
        currentFillLevel(0.0),
        timeEntered(time(nullptr)),
        status(EMPTY) {
    }

    int getId() const { return bottleId; }
    double getTargetFillLevel() const { return targetFillLevel; }
    double getCurrentFillLevel() const { return currentFillLevel; }
    BottleStatus getStatus() const { return status; }

    void setCurrentFillLevel(double level) { currentFillLevel = level; }
    void setStatus(BottleStatus newStatus) { status = newStatus; }

    void addSensorReading(const SensorReading& reading) {
        sensorReadings.push_back(reading);
    }

    const std::vector<SensorReading>& getSensorReadings() const {
        return sensorReadings;
    }

    std::string getStatusString() const {
        switch (status) {
        case EMPTY: return "EMPTY";
        case FILLING: return "FILLING";
        case FILLED: return "FILLED";
        case CAPPED: return "CAPPED";
        case REJECTED: return "REJECTED";
        default: return "UNKNOWN";
        }
    }
};

// Initialize static member
int Bottle::nextId = 1000;

// FillingStation class to manage the bottle filling process
class FillingStation {
private:
    Bottle* currentBottle;
    FillState fillState;

    // Simulated sensor readings
    double getOpticalSensorReading() const {
        // In a real system, this would interface with actual hardware
        // For simulation, we return the current fill level with small random variation
        if (!currentBottle) return 0.0;

        double variation = ((rand() % 100) - 50) / 10.0; // -5.0 to 5.0
        return currentBottle->getCurrentFillLevel() + variation;
    }

    double getWeightSensorReading() const {
        // Simulated weight reading
        if (!currentBottle) return EMPTY_BOTTLE_WEIGHT;

        double liquidWeight = currentBottle->getCurrentFillLevel(); // assuming 1ml = 1g
        double variation = ((rand() % 60) - 30) / 10.0; // -3.0 to 3.0
        return EMPTY_BOTTLE_WEIGHT + liquidWeight + variation;
    }

public:
    FillingStation() : currentBottle(nullptr), fillState(FS_READY) {}  // Changed to FS_READY

    bool isReady() const { return fillState == FS_READY; }  // Changed to FS_READY

    void startFill(Bottle* bottle) {
        if (fillState != FS_READY || !bottle) return;  // Changed to FS_READY

        currentBottle = bottle;
        currentBottle->setStatus(FILLING);
        fillState = FS_FILLING;  // Changed to FS_FILLING

        std::cout << "Starting fill for bottle #" << bottle->getId() << std::endl;
    }

    void updateFillLevel(double amount) {
        if (fillState != FS_FILLING || !currentBottle) return;  // Changed to FS_FILLING

        double newLevel = currentBottle->getCurrentFillLevel() + amount;
        currentBottle->setCurrentFillLevel(newLevel);

        // Add sensor reading
        currentBottle->addSensorReading(SensorReading(newLevel, "FLOW_SENSOR"));

        std::cout << "Bottle #" << currentBottle->getId()
            << " fill level: " << std::fixed << std::setprecision(1)
            << newLevel << "ml" << std::endl;

        // Check if target level is reached
        if (newLevel >= currentBottle->getTargetFillLevel()) {
            fillState = FS_VERIFYING;  // Changed to FS_VERIFYING
            std::cout << "Fill complete. Verifying..." << std::endl;
        }
    }

    bool verifyFill() {
        if (fillState != FS_VERIFYING || !currentBottle) return false;  // Changed to FS_VERIFYING

        // Get optical sensor reading for fill level
        double opticalLevel = getOpticalSensorReading();
        currentBottle->addSensorReading(SensorReading(opticalLevel, "OPTICAL_SENSOR"));

        // Get weight sensor reading
        double weightReading = getWeightSensorReading();
        currentBottle->addSensorReading(SensorReading(weightReading, "WEIGHT_SENSOR"));

        // Calculate expected weight based on target fill
        double expectedWeight = EMPTY_BOTTLE_WEIGHT + currentBottle->getTargetFillLevel();

        // Check if readings are within acceptable tolerances
        bool levelAccurate = std::abs(opticalLevel - currentBottle->getTargetFillLevel()) <= LEVEL_TOLERANCE;
        bool weightAccurate = std::abs(weightReading - expectedWeight) <= WEIGHT_TOLERANCE;

        std::cout << "Verification - Optical: " << opticalLevel << "ml, Weight: "
            << weightReading << "g" << std::endl;
        std::cout << "Level accurate: " << (levelAccurate ? "YES" : "NO")
            << ", Weight accurate: " << (weightAccurate ? "YES" : "NO") << std::endl;

        // Both checks must pass for verification
        bool verified = levelAccurate && weightAccurate;

        if (verified) {
            fillState = FS_COMPLETE;  // Changed to FS_COMPLETE
            currentBottle->setStatus(FILLED);
        }
        else {
            fillState = FS_ERROR;  // Changed to FS_ERROR
            currentBottle->setStatus(REJECTED);
        }

        return verified;
    }

    Bottle* completeFill() {
        if (fillState != FS_COMPLETE && fillState != FS_ERROR) return nullptr;  // Changed to FS_COMPLETE and FS_ERROR

        Bottle* finishedBottle = currentBottle;
        currentBottle = nullptr;
        fillState = FS_READY;  // Changed to FS_READY

        std::cout << "Bottle #" << finishedBottle->getId()
            << " processing complete. Status: "
            << finishedBottle->getStatusString() << std::endl;

        return finishedBottle;
    }
};

// ConveyorSystem class to manage the bottle queue
class ConveyorSystem {
private:
    std::queue<Bottle*> bottleQueue;
    FillingStation fillingStation;
    int processedCount;
    int rejectedCount;

public:
    ConveyorSystem() : processedCount(0), rejectedCount(0) {}

    ~ConveyorSystem() {
        // Clean up any remaining bottles in the queue
        while (!bottleQueue.empty()) {
            delete bottleQueue.front();
            bottleQueue.pop();
        }
    }

    void addNewBottle(double targetFillLevel = 330.0) {
        Bottle* newBottle = new Bottle(targetFillLevel);
        bottleQueue.push(newBottle);
        std::cout << "New bottle #" << newBottle->getId()
            << " added to conveyor. Target fill: "
            << targetFillLevel << "ml" << std::endl;
    }

    void processNextStep() {
        // If filling station is ready and we have bottles, start filling next bottle
        if (fillingStation.isReady() && !bottleQueue.empty()) {
            Bottle* nextBottle = bottleQueue.front();
            bottleQueue.pop();
            fillingStation.startFill(nextBottle);

            // Simulate filling process (in real system, this would happen over time)
            double fillRate = 50.0; // 50ml per step
            double targetLevel = nextBottle->getTargetFillLevel();

            // Fill in steps to simulate time passing
            while (nextBottle->getCurrentFillLevel() < targetLevel) {
                double remainingToFill = targetLevel - nextBottle->getCurrentFillLevel();
                double thisStep = std::min(fillRate, remainingToFill);
                fillingStation.updateFillLevel(thisStep);
            }

            // Verify the fill
            bool fillVerified = fillingStation.verifyFill();

            // Complete the filling process
            Bottle* processedBottle = fillingStation.completeFill();

            // Update statistics
            processedCount++;
            if (processedBottle->getStatus() == REJECTED) {
                rejectedCount++;
            }

            // In a real system, the bottle would move to the next station
            // Here we'll just delete it to prevent memory leaks in our simulation
            delete processedBottle;
        }
    }

    int getQueueSize() const {
        return bottleQueue.size();
    }

    void printStatistics() const {
        std::cout << "\n--- Conveyor System Statistics ---" << std::endl;
        std::cout << "Bottles in queue: " << bottleQueue.size() << std::endl;
        std::cout << "Bottles processed: " << processedCount << std::endl;
        std::cout << "Bottles rejected: " << rejectedCount << std::endl;
        std::cout << "Rejection rate: " << (processedCount > 0 ?
            (rejectedCount * 100.0 / processedCount) : 0) << "%" << std::endl;
    }
};

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    ConveyorSystem conveyor;

    std::cout << "=== Cold Drink Bottle Filling System Simulation ===" << std::endl;

    // Add bottles with different target fill levels
    conveyor.addNewBottle(330.0);  // Standard can
    conveyor.addNewBottle(500.0);  // Medium bottle
    conveyor.addNewBottle(330.0);  // Standard can
    conveyor.addNewBottle(1000.0); // Large bottle
    conveyor.addNewBottle(330.0);  // Standard can

    // Process all bottles
    while (conveyor.getQueueSize() > 0) {
        std::cout << "\n--- Processing next bottle ---" << std::endl;
        conveyor.processNextStep();
    }

    // Display final statistics
    conveyor.printStatistics();

    return 0;
}