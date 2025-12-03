#pragma once
#include <string>
#include "LeakedObjectDetector.h"
#include "Flight.h"
#include "Airport.h"

struct Airline
{
    Flight mainFlight;
    Airport originAirport;
    Airport destinationAirport;

    void scheduleRoute(const std::string& originCode, const std::string& destCode = "NA");
    void showAirlineInfo() const;

    Airline();
    ~Airline();

    JUCE_LEAK_DETECTOR(Airline)
};
