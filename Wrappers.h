#pragma once
#include "Book.h"
#include "Flight.h"
#include "Airport.h"
#include "Airline.h"
#include "Traveler.h"

struct BookWrapper
{
    BookWrapper(Book* _book);
    ~BookWrapper();
    Book* bookPtr = nullptr;
};

struct FlightWrapper
{
    FlightWrapper(Flight* _flight);
    ~FlightWrapper();
    Flight* flightPtr = nullptr;
};

struct AirportWrapper
{
    AirportWrapper(Airport* _airport);
    ~AirportWrapper();
    Airport* airportPtr = nullptr;
};

struct AirlineWrapper
{
    AirlineWrapper(Airline* _airline);
    ~AirlineWrapper();
    Airline* airlinePtr = nullptr;
};

struct TravelerWrapper
{
    TravelerWrapper(Traveler* _traveler);
    ~TravelerWrapper();
    Traveler* travelerPtr = nullptr;
};
