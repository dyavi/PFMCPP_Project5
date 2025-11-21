/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>


/*
 UDT 1:
 */

struct Book 
{
    float price {19.99f};

    int edition {1};

    int publicationYear;

    std::string title;

    std::string author;

    void updatePrice(float newPrice = 19.9f);

    void updateEdition(int newEdition);

    void showBookInfo();

    Book();

    ~Book();

    // Nested class inside of UDT1 per Instructions #1
    struct Chapter 
    {
        bool isEnjoyable {true};

        char chapterGrade {'A'}; 

        int wordCount {10};

        float readingTimeHours;

        std::string summary;

        void reviewChapter(bool status);

        void updateSummary(std::string newSummary);

        void gradeChapter(char grade = 'A');

        Chapter();

        ~Chapter();
    };

};

Book::Book() : 
publicationYear(2024), 
title("Dieter Rams: As Little Design as Possible"), 
author("Sophie Lovell") 
{}

Book::~Book() 
{
    std::cout << "Class `Book` is now destroyed" << "\n";
}

void Book::updatePrice(float newPrice) 
{
    price = newPrice;

    // simulate some price fluctuations
    if (newPrice < price)
    {
        for (float p = price; p > newPrice; p -= 0.5f)
            price = p;
    }
    else
    {
        for (float p = price; p < newPrice; p += 0.5f)
            price = p;
    }    
}

void Book::updateEdition(int newEdition) 
{
    edition = newEdition;
}

void Book::showBookInfo() 
{
    std::cout << "```\n";
    std::cout << "Book: " << Book::title 
              << "\nAuthor: "  << Book::author 
              << "\nPublished in: "  << Book::publicationYear 
              << "\nPrice: "  << Book::price 
              << "\nEdition: "  << Book::edition << "\n";
    std::cout << "```\n";

}


Book::Chapter::Chapter() : 
readingTimeHours(0.2f), 
summary("NA") 
{}

Book::Chapter::~Chapter() 
{
    std::cout << "Class `Chapter` that is nested inside of `Book` is now destroyed" << "\n";
}

void Book::Chapter::reviewChapter(bool status)
{
    isEnjoyable = status;

    // this is just to use the for/while loop, as per the instructions
    char previousGrade = chapterGrade;
    for (int i = 0; i < 9; ++i) 
    {
        if (i % 5 == 0)
        {
            chapterGrade = 'A';
        }
        else if (i % 3 == 0) 
        {
            chapterGrade = 'D';
        } 
        else 
        {
            chapterGrade = 'C';
        }
    }

    if (chapterGrade == previousGrade) 
        chapterGrade = 'O';
}

void Book::Chapter::updateSummary(std::string newSummary)
{
    summary = newSummary;
}

void Book::Chapter::gradeChapter(char grade)
{
    chapterGrade = grade;
}


/*
 UDT 2:
 */
struct Flight 
{
    int numberOfPassengers {0};

    float durationHours {2.0f};

    std::string flightNumber;

    std::string airline;

    std::string origin;

    std::string destination;

    void updateDuration(float newDuration);

    void showFlightInfo();
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

        void assignPassenger(std::string name, std::string id);

        void requestExtraLegroom(bool request = false);

        void releaseSeat();

        PassengerSeat();

        ~PassengerSeat();
    };
};

//  UDT2: Flight implementation 
Flight::Flight() : 
flightNumber("NA"), 
origin("NA"), 
destination("NA") 
{}

Flight::~Flight() 
{ 
    std::cout << "Deallocation of UDT `Flight`\n"; 
}

void Flight::updateDuration(float newDuration) 
{ 
    durationHours = newDuration; 
}

void Flight::boardPassenger(int count) 
{ 
    std::cout << "\t Preparing to board passengers.\n";

    // for-while loop instructions
    for (int i = 0; i < count; ++i)
    {
        ++numberOfPassengers;
        std::cout << "\t\t-Passenger " << (i + 1) << " boarded.\n";
    }
}

void Flight::showFlightInfo() 
{
    std::cout << "Flight: " << flightNumber
              << "\nFrom: " << origin
              << "\nTo: " << destination
              << "\nPassengers: " << numberOfPassengers
              << "\nDuration: " << durationHours << " hours\n";
}

//  UDT2's neted UDT: PassengerSeat implementation 
Flight::PassengerSeat::PassengerSeat() : 
seatNumber(1), 
passengerName("NA"), 
passengerID("NA") 
{}

Flight::PassengerSeat::~PassengerSeat() 
{ 
    std::cout << "Deallocation of UDT `PassengerSeat` that is nested inside of `Flight`\n"; 
}

void Flight::PassengerSeat::assignPassenger(std::string name, std::string id) 
{
    passengerName = name;
    passengerID = id;
}

void Flight::PassengerSeat::requestExtraLegroom(bool request) 
{ 
    // simulate malfuntions for the for-while loop requirements
    int count = 5;
    int malfunctions = 0;
    while (malfunctions != count) 
    {
        hasExtraLegroom = ! hasExtraLegroom;
        ++malfunctions;
    }
    // eventually, do the right thing
    hasExtraLegroom = request; 
}

void Flight::PassengerSeat::releaseSeat() 
{
    passengerName = "";
    passengerID = "";
    hasExtraLegroom = false;
}

/*
 UDT 3:
 */

struct Airport 
{
    std::string code;

    std::string city;

    double annualPassengers;

    int totalRunways {4};

    bool isInternational {true};

    void addRunway(int count = 1);

    void showAirportInfo();

    void updateAnnualPassengers(double newCount = 0.0);

    Airport();

    ~Airport();
};

// UDT3: Airport implementation 
Airport::Airport() : 
code("NA"), 
city("NA"), 
annualPassengers(0.0) 
{}

Airport::~Airport() 
{ 
    std::cout << "Deallocation of UDT `Airport`\n"; 
}

void Airport::addRunway(int count) 
{
    for (int i = 0; i < count; ++i)
    {
        ++totalRunways;
        std::cout << "The `" << code << "` Airport just added a new runway! Total runways as of date: " << totalRunways << "\n";
    }

}

void Airport::updateAnnualPassengers(double newCount) 
{ 
    annualPassengers = newCount; 
}

void Airport::showAirportInfo() 
{
    std::cout << "Airport (code): " << code
              << "\nCity: " << city
              << "\nTotal Runways: " << totalRunways
              << "\nAnnual Passengers: " << annualPassengers
              << "\nInternational: " << (isInternational ? "Yes" : "No") << "\n";
}


/*
 new UDT 4:
 */

struct Airline 
{
    Flight mainFlight;   

    Airport originAirport;               

    Airport destinationAirport;       

    void scheduleRoute(std::string originCode, std::string destCode="NA");

    void showAirlineInfo();

    Airline();

    ~Airline();
};

// UDT4: Airline implementation 
Airline::Airline()
{
    mainFlight.airline = "UFO";
    originAirport.code = "NA";
    destinationAirport.code = "NA";
}

Airline::~Airline()
{
    std::cout << "Deallocation of UDT `Airline`\n";
}

void Airline::scheduleRoute(std::string originCode, std::string destCode)
{
    // Set airport codes for origin/destination for simplicity
    originAirport.code = originCode;
    destinationAirport.code = destCode;

    // and tie the flight's origin/destination to the airport codes for simplicity
    mainFlight.origin = originAirport.code;
    mainFlight.destination = destinationAirport.code;

    std::cout << "Airline scheduled route from " 
              << originAirport.code << " to " 
              << destinationAirport.code << "\n";
}

void Airline::showAirlineInfo()
{
    std::cout << "\n=== Airline Information ===\n";
    std::cout << "Main flight details:\n";
    mainFlight.showFlightInfo();

    std::cout << "\nOrigin airport details:\n";
    originAirport.showAirportInfo();

    std::cout << "\nDestination airport details:\n";
    destinationAirport.showAirportInfo();
    std::cout << "===========================\n";
}


/*
 new UDT 5:
 */
struct Traveler 
{
    Book favoriteBook;                

    Flight bookedFlight;              

    Airport departureAirport;         

    Airport arrivalAirport;           

    void checkInAndshowItinerary(std::string passengerName, std::string passengerID);

    void finishChapter(char grade, bool enjoyed);

    Traveler();

    ~Traveler();
};

// UDT5: Traveler implementation 

Traveler::Traveler()
{
    favoriteBook.title  = "Unkown Book";
    favoriteBook.author = "Unknown Author";
}

Traveler::~Traveler()
{
    std::cout << "Deallocation of UDT `Traveler`\n";
}

// this should be two separate functions, but I'd like to keep it simple for now as per instructions #6
void Traveler::checkInAndshowItinerary(std::string passengerName, std::string passengerID)
{
    Flight::PassengerSeat tempSeat;
    tempSeat.assignPassenger(passengerName, passengerID);
    tempSeat.requestExtraLegroom(true); 

    bookedFlight.boardPassenger();

    std::cout << "\nTraveler " << passengerName 
              << " (ID: " << passengerID << ") has checked in.\n";

    std::cout << "\n--- Itinerary ---\n";
    std::cout << "Departure airport:\n";
    departureAirport.showAirportInfo();

    std::cout << "\nArrival airport:\n";
    arrivalAirport.showAirportInfo();

    std::cout << "\nBooked flight:\n";
    bookedFlight.showFlightInfo();
    std::cout << "-----------------\n";
}

void Traveler::finishChapter(char grade, bool enjoyed)
{
    // Use the nested Book::Chapter UDT to model finishing a chapter
    Book::Chapter chapter;
    chapter.gradeChapter(grade);
    chapter.reviewChapter(enjoyed);

    std::cout << "\nTraveler finished a chapter of the book: " 
              << favoriteBook.title << "\n"
              << "Chapter grade: " << chapter.chapterGrade << "\n"
              << "Enjoyment: " << (chapter.isEnjoyable ? "Yes" : "No") << "\n";
}


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

int main()
{

    std::cout << "=================================== Testing UDT1: `Book` and its nested UDT: `Chapter` ===================================\n";

    std::cout << "\n********************************\nExample 1. `Book` Instance #1\n********************************\n" ;

    Book book1;

    std::cout << "\nBook1 Info before being updated (price and edition will be updated):\n";

    book1.showBookInfo();
    book1.updatePrice(29.99f);
    book1.updateEdition(2);

    std::cout << "\nBook1 Info after being updated:\n";

    book1.showBookInfo();

    std::cout << "\n********************************\nExample 2. `Book` Instance #2\n********************************\n" ;

    Book book2;

    book2.title = "Atomic Habits";
    book2.author = "James Clear";
    book2.publicationYear = 2018;
    book2.price = 18.88f;  

    std::cout << "\nBook2 Info before being updated (price and edition will be updated):\n";

    book2.showBookInfo();
    book2.updatePrice(22.50f);
    book2.updateEdition(2);

    std::cout << "\nBook2 Info after being updated:\n";

    book2.showBookInfo();

    std::cout << "\n";

    std::cout << "\n********************************\nExample 3. `Book::Chapter` Instance #1\n********************************\n" ;

    Book::Chapter chapter1;

    chapter1.updateSummary("Chapter 1 shows some really cool designs!.");

    std::cout << "Original assumed grade before reading: B" << "\n";

    chapter1.gradeChapter('B');
    chapter1.reviewChapter(true);

    std::cout << "Chapter1 summary: " << chapter1.summary
              << "\nEnjoyable: " << (chapter1.isEnjoyable ? "Yes" : "No")
              << "\nGrade (final/in the end): " << chapter1.chapterGrade << "\n\n";

    std::cout << "\n********************************\nExample 4. `Book::Chapter` Instance #2\n********************************\n" ;

    Book::Chapter chapter2;

    chapter2.updateSummary("Chapter 2 introduces identity-based habits and small wins.");

    std::cout << "Original assumed grade (before reading): C" << "\n";

    chapter2.gradeChapter('C');
    chapter2.reviewChapter(true);

    std::cout << "Chapter2 summary: " << chapter2.summary
              << "\nEnjoyable: " << (chapter2.isEnjoyable ? "Yes" : "No")
              << "\nGrade (final/in the end): " << chapter2.chapterGrade << "\n\n";

    std::cout << "=================================== Finished testing UDT1: `Book` and its nested UDT: `Chapter` =================================== \n\n";


    std::cout << "=================================== Testing UDT2: `Flight` and its nested UDT: `PassengerSeat` ===================================\n";

    std::cout << "\n********************************\nExample 5. `Flight` Instance #1\n********************************\n" ;

    Flight flight1;

    // Initialize flight1
    flight1.flightNumber = "AA101";
    flight1.airline      = "American Airlines";
    flight1.origin       = "JFK";
    flight1.destination  = "LAX";

    // Call all member functions on flight1
    flight1.boardPassenger(2);
    flight1.updateDuration(6.0f);       
    flight1.showFlightInfo();

    std::cout << "\n********************************\nExample 6. `Flight` Instance #2\n********************************\n" ;

    Flight flight2;

    flight2.flightNumber = "DL220";
    flight2.airline      = "Delta Air Lines";
    flight2.origin       = "ATL";
    flight2.destination  = "SFO";

    flight2.boardPassenger(4);
    flight2.updateDuration(5.0f);
    flight2.showFlightInfo();

    std::cout << "\n********************************\nExample 7. `Flight::PassengerSeat` Instance #1\n********************************\n" ;

    Flight::PassengerSeat seat1;

    seat1.seatNumber = 12;
    seat1.seatClass  = 'E'; // Economy
    seat1.assignPassenger("Mr. Johnson", "ALC12345");

    std::cout << "Seat1 originally assigned to: " << seat1.passengerName
              << " (ID: " << seat1.passengerID << ")"
              << ", seat number: " << seat1.seatNumber
              << ", extra legroom: " << (seat1.hasExtraLegroom ? "Yes" : "No")
              << "\n";

    seat1.requestExtraLegroom(true);

    std::cout << "After 30 mins this passenger requested extra legroom: " << seat1.passengerName
              << " (ID: " << seat1.passengerID << ")"
              << ", seat number: " << seat1.seatNumber
              << ", extra legroom: " << (seat1.hasExtraLegroom ? "Yes" : "No")
              << "\n";

    seat1.releaseSeat(); 

    std::cout << "Seat1 after release, passenger name: \"" 
              << seat1.passengerName << "\"\n\n";

    std::cout << "\n********************************\nExample 8. `Flight::PassengerSeat` Instance #2\n********************************\n" ;

    Flight::PassengerSeat seat2;

    seat2.seatNumber = 3;
    seat2.seatClass  = 'B'; 

    seat2.assignPassenger("Esther Smith", "BOB98765");
    seat2.requestExtraLegroom(true);

    std::cout << "Seat2 assigned to: " << seat2.passengerName
              << " (ID: " << seat2.passengerID << ")"
              << ", seat number: " << seat2.seatNumber
              << ", seat class: " << seat2.seatClass
              << ", extra legroom: " << (seat2.hasExtraLegroom ? "Yes" : "No")
              << "\n";

    seat2.releaseSeat();

    std::cout << "Seat2 after release, passenger name: \"" 
              << seat2.passengerName << "\"\n\n";


    std::cout << "=================================== Finished testing UDT2: `Flight` and its nested UDT: `PassengerSeat` ===================================\n";

    std::cout << "\n=================================== Testing UDT3: `Airport ` (no nested UDT here) ===================================\n";

    std::cout << "\n********************************\nExample 9. `Airport` Instance #1\n********************************\n" ;

    Airport airport1;

    // Initialize airport1: JFK, New York
    airport1.code = "JFK";
    airport1.city = "New York";
    airport1.isInternational = true;
    airport1.totalRunways = 4;

    airport1.updateAnnualPassengers(75000000.0);
    airport1.showAirportInfo();   

    std::cout << "After adding one more runaway to the airport...\n";

    airport1.addRunway();         
    airport1.showAirportInfo(); 

    std::cout << "\n********************************\nExample 10. `Airport` Instance #2\n********************************\n" ;

    Airport airport2;
    airport2.code = "LAX";

    airport2.city = "Los Angeles";
    airport2.isInternational = true;

    airport2.updateAnnualPassengers(88900000.0);
    airport2.showAirportInfo();
    airport2.addRunway(2);

    std::cout << "After adding two more runaway to the airport...\n";

    airport2.showAirportInfo();

    std::cout << "\n=================================== Finished testing UDT3: `Airport ` (no nested UDT here) ===================================\n";

    std::cout << "\n=================================== Testing UDT4: `Airline` ===================================\n";

    std::cout << "\n********************************\nExample 11. `Airport` Instance #1\n********************************\n" ;

    Airline airline1;

    airline1.mainFlight.flightNumber = "AA101";
    airline1.mainFlight.airline      = "American Airlines";
    airline1.mainFlight.boardPassenger(6);

    airline1.originAirport.code      = "JFK";
    airline1.originAirport.city      = "New York";
    airline1.originAirport.annualPassengers = 75000000.0;

    airline1.destinationAirport.code = "LAX";
    airline1.destinationAirport.city = "Los Angeles";
    airline1.destinationAirport.annualPassengers = 88900000.0;

    airline1.scheduleRoute("JFK", "LAX");
    airline1.showAirlineInfo();

    std::cout << "\n********************************\nExample 12. `Airport` Instance #2\n********************************\n" ;

    Airline airline2;

    airline2.mainFlight.flightNumber = "DL220";
    airline2.mainFlight.airline      = "Delta Air Lines";

    airline2.mainFlight.boardPassenger(5);

    airline2.originAirport.code      = "ATL";
    airline2.originAirport.city      = "Atlanta";
    airline2.originAirport.annualPassengers = 5670000.0;

    airline2.destinationAirport.code = "SFO";
    airline2.destinationAirport.city = "San Francisco";
    airline2.destinationAirport.annualPassengers = 10348000.0;

    airline2.scheduleRoute("ATL", "SFO");
    airline2.showAirlineInfo();

    std::cout << "\n=================================== Finished testing UDT4: `Airline` ===================================\n";

    std::cout << "\n=================================== Testing UDT5: `Traveler` ===================================\n";

    std::cout << "\n********************************\nExample 13. `Airport` Instance #1\n********************************\n" ;

    Traveler traveler1;

    traveler1.favoriteBook.title  = "The 7 Habits of Highly Effective People";
    traveler1.favoriteBook.author = "Stephen R. Covey";

    traveler1.bookedFlight.flightNumber = "AA101";
    traveler1.bookedFlight.airline      = "American Airlines";
    traveler1.bookedFlight.origin       = "NY";
    traveler1.bookedFlight.destination  = "LA";

    traveler1.departureAirport.code     = "JFK";
    traveler1.departureAirport.city     = "New York";
    traveler1.departureAirport.annualPassengers = 20678970.0;

    traveler1.arrivalAirport.code       = "LAX";
    traveler1.arrivalAirport.city       = "Los Angeles";
    traveler1.arrivalAirport.annualPassengers = 10678000.0;

    traveler1.checkInAndshowItinerary("Chuck Norris", "HWC176545");
    traveler1.finishChapter('A', true);

    std::cout << "Traveler1's favorite book: " << traveler1.favoriteBook.title 
              << " by " << traveler1.favoriteBook.author << "\n";
    std::cout << "Traveler1's flight: " << traveler1.bookedFlight.flightNumber 
              << " (" << traveler1.bookedFlight.airline << ") from " 
              << traveler1.departureAirport.code << " to " 
              << traveler1.arrivalAirport.code << "\n\n";


    std::cout << "\n********************************\nExample 14. `Airport` Instance #2\n********************************\n" ;

    Traveler traveler2;

    traveler2.favoriteBook.title  = "Sapiens: A Brief History of Humankind";
    traveler2.favoriteBook.author = "Yuval Noah Harari";

    traveler2.bookedFlight.flightNumber = "DL220";
    traveler2.bookedFlight.airline      = "Delta Air Lines";
    traveler2.bookedFlight.origin       = "ATL";
    traveler2.bookedFlight.destination  = "SF";

    traveler2.departureAirport.code     = "ATL";
    traveler2.departureAirport.city     = "Atlanta";
    traveler2.departureAirport.annualPassengers = 234232.0;

    traveler2.arrivalAirport.code       = "SFO";
    traveler2.arrivalAirport.city       = "San Francisco";
    traveler2.arrivalAirport.annualPassengers = 534232.0;

    traveler2.checkInAndshowItinerary("Dua Lee", "BOB98765");
    traveler2.finishChapter('B', true);

    std::cout << "Traveler2's favorite book: " << traveler2.favoriteBook.title 
              << " by " << traveler2.favoriteBook.author << "\n";
    std::cout << "Traveler2's flight: " << traveler2.bookedFlight.flightNumber 
              << " (" << traveler2.bookedFlight.airline << ") from " 
              << traveler2.departureAirport.code << " to " 
              << traveler2.arrivalAirport.code << "\n\n";

    std::cout << "\n=================================== Finished testing UDT5: `Traveler` ===================================\n";

    std::cout << "good to go!" << std::endl;
}
