/*
Program to output mayan numbers and quiz users on them
Author: Jerry Chen
Date: November 12 2021
*/

#include <iostream>
#include <string>

using namespace std;

const int NUMBERBASE = 20;

int findPowerLevel(int number)
{
    // variable to track the largest power of 20 below the input
    int powerLevel = 1;

    // keep dividing the input by 20 until the quotient is below 20
    while (number/ NUMBERBASE >= 1)
    {
        powerLevel *= NUMBERBASE;
        number = number/NUMBERBASE;
    }

    return powerLevel;
}

// outputs each mayan "digit"
void printNumber(int number)
{
         if (number ==  0) cout << "00"   << endl;
    else if (number ==  1) cout << "."    << endl;
    else if (number ==  2) cout << ".."   << endl;
    else if (number ==  3) cout << "..."  << endl;
    else if (number ==  4) cout << "...." << endl;
    else if (number ==  5) cout << "----" << endl;
    else if (number ==  6) cout << "."    << endl << "----" << endl;
    else if (number ==  7) cout << ".."   << endl << "----" << endl;
    else if (number ==  8) cout << "... " << endl << "----" << endl;
    else if (number ==  9) cout << "...." << endl << "----" << endl;
    else if (number == 10) cout << "----" << endl << "----" << endl;
    else if (number == 11) cout << "."    << endl << "----" << endl << "----" << endl;
    else if (number == 12) cout << ".."   << endl << "----" << endl << "----" << endl;
    else if (number == 13) cout << "..."  << endl << "----" << endl << "----" << endl;
    else if (number == 14) cout << "...." << endl << "----" << endl << "----" << endl;
    else if (number == 15) cout << "----" << endl << "----" << endl << "----" << endl;
    else if (number == 16) cout << ". "   << endl << "----" << endl << "----" << endl << "----" << endl;
    else if (number == 17) cout << ".. "  << endl << "----" << endl << "----" << endl << "----" << endl;
    else if (number == 18) cout << "..."  << endl << "----" << endl << "----" << endl << "----" << endl;
    else if (number == 19) cout << "...." << endl << "----" << endl << "----" << endl << "----" << endl;
}

// create a line to separate each "digit"
void printSeperateLine()
{
    cout << "##################################" << endl;
}

void printMayanNumber(int number)
{
    // initializes variables to track the remaining number needing to get converted,
    // the peower of 20 that the remaining number needs to get divided by, and 
    // the quotient and remainder of the division
    int curNumber = number;
    int currentPower = 0;
    int quotient = 0;
    int remain = 0;

    do
    {
        // find the largest power of 20 below the current number
        currentPower = findPowerLevel(curNumber);

        // divide by the "current power", get values for the quotient and remainder
        quotient = curNumber / currentPower;
        remain = curNumber % currentPower;

        // output the mayan numerals for the current power level
        printNumber(quotient);

        // print a line to separate this mayan digit from the next
        printSeperateLine();

        // while loop to run through the remaining "digits",
        // skips through the "power level" and prints 00 
        // if the remainder = 0
        while ( remain < (currentPower / NUMBERBASE))
        {
            // print 00 when smaller
            printNumber(0);

            // line to separate next digit
            printSeperateLine();

            // divide the current power by 20 to find the next
            // lowest "powerlevel"
            currentPower = currentPower / NUMBERBASE;

            // exits the while loop when the 00 with the lowest
            // "power level" is found
            if (currentPower == 1 && remain == 0)
            {
                printNumber(0);
                break;
            }
        }

        // if the function is on the last "power level"
        // print the final digit and exit the loop
        if (remain < NUMBERBASE)
        {
            // don't need to print 00 again if remainder is 0
            // because previously printed in line 102
            if (remain != 0)
            {
                printNumber(remain);
            }

            break;
        }

        // otherwise, set the current number to the remainder
        // and continue running through the loop
        else
        {
            curNumber = remain;
        }

    } while (true);

    // print a line to separate digits
    printSeperateLine();
}

void game()
{
    // gives user instructions and asks for input
    cout << "MAYAN NUMBER GAME" << endl;
    cout << "=================" << endl << "Welcome to the Mayan Number Game!" << endl << endl;
    cout << "Enter a number greater than 10. The game will choose a number" << endl;
    cout << "less than or equal to what you entered. You will then have" << endl;
    cout << "to match the decimal number to its Mayan equivalent." << endl;
    cout << "Or, enter a number less than 10 to exit: " << endl;

    int number;
    cin >> number;

    do {
        // terminate program if number out of range
        if (number < 10)
        {
            break;
        }
        else
        {
            string answer;

            // generate 3 random numbers as options
            int number1 = rand()%number;
            int number2 = rand()%number;
            int number3 = rand()%number;

            // randomly generate the correct selection
            // i.e. option a, b or c
            int answerKey = rand()%3 + 1;
            int answerNumber;

            // prompt the user for the answer to the correct value
            if (answerKey == 1)
            {
                answerNumber = number1;
                cout << "Which of these Mayan numbers is equal to " << number1 << endl;
            }
            else if (answerKey == 2)
            {
                answerNumber = number2;
                cout << "Which of these Mayan numbers is equal to " << number2 << endl;
            }
            else
            {
                answerNumber = number3;
                cout << "Which of these Mayan numbers is equal to " << number3 << endl;
            }

            // output the options
            cout << "a." << endl;
            printMayanNumber(number1);
            cout << endl;

            cout << "b. " << endl;
            printMayanNumber(number2);
            cout << endl;

            cout << "c. " << endl;
            printMayanNumber(number3);
            cout << endl;
            cout << endl;

            // prompt user for answer
            cout << "Enter a, b or c:";
            cin >> answer;

            // determine if answer is correct, provide feedback to user
            if ((answerKey == 1 && answer.compare("a") == 0) ||
                (answerKey == 2 && answer.compare("b") == 0) ||
                (answerKey == 3 && answer.compare("c") == 0))
            {
                cout << "CORRECT!";
            }
            else
            {
                cout << "INCORRECT!";
            }

            // print out correct answer
            cout << " The Mayan representation of " << answerNumber << " is " << endl;

            printMayanNumber(answerNumber);

            cout << "Enter another number, or less than 10 to exit:";
            cin >> number;
        }
    } while (true);
}

int main()
{
    // print the Maya representation of the number 5,212
    printMayanNumber(5212);

    // call Maya number game
    game();

    return 0;
}
