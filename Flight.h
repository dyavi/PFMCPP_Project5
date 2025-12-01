#pragma once
#include <string>
#include "LeakedObjectDetector.h"

struct Flight
{
    int numberOfPassengers {0};
    float durationHours {2.0f};
    std::string flightNumber;
    std::string airline;
    std::string origin;
    std::string destination;

    void updateDuration(float newDuration);
    void showFlightInfo() const;
    void boardPassenger(int count = 1);

    Flight();
    ~Flight();

    struct PassengerSeat
    {
        bool hasExtraLegroom {false};
        char seatClass {'E'};
        int seatNumber {0};
        std::string passengerName;
        std::string passengerID;

        void assignPassenger(const std::string& name, const std::string& id);
        void requestExtraLegroom(bool request = false);
        void releaseSeat();
        void printDetailedMemberInfo() const;

        PassengerSeat();
        ~PassengerSeat();
    };

    JUCE_LEAK_DETECTOR(Flight)
};
