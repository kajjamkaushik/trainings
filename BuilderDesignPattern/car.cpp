#include <iostream>
#include <string>

// Forward declarations
class Car;
class Manual;
class SportEngine;

// Builder interface
class Builder {
public:
    virtual ~Builder() = default;
    virtual void reset() = 0;
    virtual void setSeats(int number) = 0;
    virtual void setEngine(void* engine) = 0;
    virtual void setTripComputer(bool enabled) = 0;
    virtual void setGPS(bool enabled) = 0;
};

// Product classes
class Car {
public:
    int seats = 0;
    void* engine = nullptr;
    bool hasTripComputer = false;
    bool hasGPS = false;

    void display() const {
        std::cout << "Car with " << seats << " seats" << std::endl;
        std::cout << "Engine: " << (engine ? "Installed" : "None") << std::endl;
        std::cout << "Trip Computer: " << (hasTripComputer ? "Yes" : "No") << std::endl;
        std::cout << "GPS: " << (hasGPS ? "Yes" : "No") << std::endl;
    }
};

class Manual {
public:
    std::string seatsInfo;
    std::string engineInfo;
    std::string tripComputerInfo;
    std::string gpsInfo;

    void display() const {
        std::cout << "Manual contents:" << std::endl;
        std::cout << "Seats: " << seatsInfo << std::endl;
        std::cout << "Engine: " << engineInfo << std::endl;
        std::cout << "Trip Computer: " << tripComputerInfo << std::endl;
        std::cout << "GPS: " << gpsInfo << std::endl;
    }
};

// Engine type for demonstration
class SportEngine {
public:
    // Engine properties and methods
};

// Concrete builders
class CarBuilder : public Builder {
private:
    Car* car;

public:
    CarBuilder() {
        reset();
    }

    ~CarBuilder() {
        if (car) {
            delete car;
        }
    }

    void reset() override {
        if (car) {
            delete car;
        }
        car = new Car();
    }

    void setSeats(int number) override {
        car->seats = number;
    }

    void setEngine(void* engine) override {
        car->engine = engine;
    }

    void setTripComputer(bool enabled) override {
        car->hasTripComputer = enabled;
    }

    void setGPS(bool enabled) override {
        car->hasGPS = enabled;
    }

    Car* getProduct() {
        Car* result = car;
        car = nullptr;  // Transfer ownership
        reset();
        return result;
    }
};

class CarManualBuilder : public Builder {
private:
    Manual* manual;

public:
    CarManualBuilder() {
        reset();
    }

    ~CarManualBuilder() {
        if (manual) {
            delete manual;
        }
    }

    void reset() override {
        if (manual) {
            delete manual;
        }
        manual = new Manual();
    }

    void setSeats(int number) override {
        manual->seatsInfo = "This car has " + std::to_string(number) + " seats.";
    }

    void setEngine(void* engine) override {
        manual->engineInfo = engine ? "Sports engine installed. Handle with care!" : "No engine information";
    }

    void setTripComputer(bool enabled) override {
        manual->tripComputerInfo = enabled ?
            "Trip computer: Press the button to access navigation." :
            "This car doesn't have a trip computer.";
    }

    void setGPS(bool enabled) override {
        manual->gpsInfo = enabled ?
            "GPS: Satellite navigation system included." :
            "This car doesn't have a GPS system.";
    }

    Manual* getProduct() {
        Manual* result = manual;
        manual = nullptr;  // Transfer ownership
        reset();
        return result;
    }
};

// Director
class Director {
public:
    void constructSportsCar(Builder* builder) {
        builder->reset();
        builder->setSeats(2);
        builder->setEngine(new SportEngine());
        builder->setTripComputer(true);
        builder->setGPS(true);
    }

    void constructSUV(Builder* builder) {
        builder->reset();
        builder->setSeats(5);
        builder->setEngine(nullptr);  // Different engine would be used
        builder->setTripComputer(false);
        builder->setGPS(true);
    }
};

// Client code
class Application {
public:
    void makeCar() {
        Director director;

        // Build a car
        CarBuilder* carBuilder = new CarBuilder();
        director.constructSportsCar(carBuilder);
        Car* car = carBuilder->getProduct();
        car->display();
        delete car;
        delete carBuilder;

        // Build a manual
        CarManualBuilder* manualBuilder = new CarManualBuilder();
        director.constructSportsCar(manualBuilder);
        Manual* manual = manualBuilder->getProduct();
        manual->display();
        delete manual;
        delete manualBuilder;
    }
};

int main() {
    Application app;
    app.makeCar();
    return 0;
}
//output:
//Car with 2 seats
//Engine : Installed
//Trip Computer : Yes
//GPS : Yes
//Manual contents :
//Seats: This car has 2 seats.
//Engine : Sports engine installed.Handle with care!
//Trip Computer : Trip computer : Press the button to access navigation.
//GPS : GPS : Satellite navigation system included.