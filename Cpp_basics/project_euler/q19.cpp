// q19.cpp

// Problem: Counting Sundays
//
// How many Sundays fell on the first of the month during 
// the twentieth century if 1 Jan 1900 was a Monday?
//
// Iterate through months mod 7

#define DEBUG

#include <iostream>
#include <string>


int main (int argc, char** argv)
{
    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 
        31, 30, 31 };
    int leap, month, day, sundays;
    sundays = 0;
    leap = 29;


    // Sunday is 0, Saturday is 6
    // 1 Jan 1901 was a Tuesday
    day = 2;

    // Up to 1 Jan 2000
    for (int year = 1901; year < 2000; ++year)
    {
        for (month = 0; month < 12; ++month)
        {
            if (month == 1 && (year % 4 == 0))
            {
                // if leap year
                day += leap;
            }
            else 
            {
                // set to next month's first day
                day += months[month];
            }

            // update day
            day = day % 7;

            // check if day is sunday
            if (day == 0)
            {
                ++sundays;
            }
        }
    }

    // Check for year 2000
    for (month = 0; month < 11; ++month)
    {
        day += months[month];

        day = day % 7;

        if (day == 0)
        {
            ++sundays;
        }
    }

    std::cout << "[Q19] There are " << sundays << " Sundays"
        << " in the 20-th century.\n";

    return 0;
}