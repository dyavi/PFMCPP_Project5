#pragma once
#include <string>
#include "LeakedObjectDetector.h"

struct Airport
{
    std::string code;
    std::string city;
    double annualPassengers;
    int totalRunways {4};
    bool isInternational {true};

    void addRunway(int count = 1);
    void showAirportInfo() const;
    void updateAnnualPassengers(double newCount = 0.0);

    Airport();
    ~Airport();

    JUCE_LEAK_DETECTOR(Airport)
};
