#include "Wrappers.h"

BookWrapper::BookWrapper(Book* _book) : bookPtr(_book) {}
BookWrapper::~BookWrapper() 
{ 
  delete bookPtr; 
}

FlightWrapper::FlightWrapper(Flight* _flight) : flightPtr(_flight) {}
FlightWrapper::~FlightWrapper() 
{ 
  delete flightPtr; 
}

AirportWrapper::AirportWrapper(Airport* _airport) : airportPtr(_airport) {}
AirportWrapper::~AirportWrapper() 
{ 
  delete airportPtr; 
}

AirlineWrapper::AirlineWrapper(Airline* _airline) : airlinePtr(_airline) {}
AirlineWrapper::~AirlineWrapper() 
{ 
  delete airlinePtr; 
}

TravelerWrapper::TravelerWrapper(Traveler* _traveler) : travelerPtr(_traveler) {}
TravelerWrapper::~TravelerWrapper() 
{ 
  delete travelerPtr; 
}
