#pragma once
#include <string>
#include "LeakedObjectDetector.h"
#include "Book.h"
#include "Flight.h"
#include "Airport.h"

struct Traveler
{
    Book favoriteBook;
    Flight bookedFlight;
    Airport departureAirport;
    Airport arrivalAirport;

    void checkInAndshowItinerary(const std::string& passengerName, const std::string& passengerID);
    void finishChapter(char grade, bool enjoyed);
    void printDetailedMemberInfo() const;

    Traveler();
    ~Traveler();

    JUCE_LEAK_DETECTOR(Traveler)
};
