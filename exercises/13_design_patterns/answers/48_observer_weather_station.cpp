// 题 48：观察者模式

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(double temperature) = 0;
};

class WeatherStation {
private:
    std::vector<Observer*> observers_;
    double temperature_ = 0.0;

public:
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer),
            observers_.end()
        );
    }

    void setTemperature(double temperature) {
        temperature_ = temperature;
        for (auto* observer : observers_) {
            observer->update(temperature_);
        }
    }
};

class PhoneDisplay : public Observer {
public:
    void update(double temperature) override {
        std::cout << "phone display: " << temperature << '\n';
    }
};

int main() {
    WeatherStation station;
    PhoneDisplay display;

    station.addObserver(&display);
    station.setTemperature(26.5);
}

