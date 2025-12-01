#pragma once
#include <string>
#include "LeakedObjectDetector.h"

struct Book
{
    float price {19.99f};
    int edition {1};
    int publicationYear;
    std::string title;
    std::string author;

    void updatePrice(float newPrice = 19.9f);
    void updateEdition(int newEdition);
    void showBookInfo() const;

    Book();
    ~Book();

    struct Chapter
    {
        bool isEnjoyable {true};
        char chapterGrade {'A'};
        int wordCount {10};
        float readingTimeHours;
        std::string summary;

        void reviewChapter(bool status);
        void updateSummary(const std::string& newSummary);
        void gradeChapter(char grade = 'A');
        void printDetailedMemberInfo() const;

        Chapter();
        ~Chapter();
    };

    JUCE_LEAK_DETECTOR(Book)
};
