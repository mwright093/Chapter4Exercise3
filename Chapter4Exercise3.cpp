// Chapter4Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
    std::cout << "This program will check to see if a date is considered 'sepcial'"
              << " when written in the format MM/DD/YY. \nThe date is considered "
              << "'sepcial' if the two digit year equals the month times the day"
              << endl;

    int month = 0;
    int day   = 0;
    int year  = 0;

    bool validDate   = true;
    bool specialDate = false;

    do
    {
        cout << "\nPlease enter the two digit month: ";
        cin >> month;

        cout << "Please enter the two digit day: ";
        cin >> day;

        cout << "Please enter the two digit year: ";
        cin >> year;

        cout << endl;
        // Check that the month is within the correct range 1-12
        if (month < 0 || month > 12)
        {
            cout << "You entered an invalid number for the month!\n";
            validDate = false;
        }
        else
        {
            // This checks to see if the day is outside the range 1-31
            if (day >= 31 || day <= 0)
            {
                cout << "You entered an invalid number for the day!\n";
                validDate = false;
            }
            else
            {
                // This is checking to see if the day is outside of the range 1-30 
                // for the correct months.
                if ((month == 4 || month == 6 || month == 9 || month == 11)
                    && (day > 30))
                {
                    cout << "You entered an invalid number for"
                         << " the day based your month!\n";
                    validDate = false;
                }       
                else 
                {
                    bool isLeapYear = (year % 4 == 0) ||
                        (year % 100 != 0 && year % 400 == 0);

                    if (month == 2)
                    {
                        if (isLeapYear && day > 29)
                        {
                            cout << "During leap years there is only a max"
                                << "of 29 days in Feburary!!\n";
                            validDate = false;
                        }
                        else if (!isLeapYear && day > 28)
                        {
                            cout << "During non-leap years there is only a max"
                                << "of 28 days in Feburary!!\n";
                            validDate = false;
                        }
                        else
                        {
                            validDate = true;
                        }
                    }
                }
            }
        }


        if (validDate)
        {
            cout << "\nYou entered the date " << month
                << "/" << day << "/" << year << endl;

            cout << "Checking if date is considered special...\n";

            int specialNum = month * day;
            specialDate = specialNum == year;

            if (specialDate)
            {
                cout << "This IS a magic date!!\n";
            }
            else
            {
                cout << "This IS NOT a magic date!!\n";
            }
        }
        else
        {
            cout << "\nYou entered an invalid date!! \nSTARTING OVER!!" << endl;
        }
        
    } while (true);
}