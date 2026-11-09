#include "pch.h"
using namespace System;



void Task1()
{
    double carpetPriceSqMt;
    double roomWidth;
    double roomLength;

    Console::Write(L"Enter the length of the room: ");
    roomLength = Double::Parse(Console::ReadLine());

    Console::Write(L"Enter the room width: ");
    roomWidth = Double::Parse(Console::ReadLine());

    Console::Write(L"Enter the price of the carpeting per square meter: ");
    carpetPriceSqMt = Double::Parse(Console::ReadLine());

    double roomArea = roomWidth * roomLength;
    double carpetPrice = roomArea * carpetPriceSqMt;

    Console::WriteLine(L"Room size {0:F2} meters on {1:F2} meters",
        roomLength, roomWidth);

    Console::WriteLine(L"Room area {0:F2} square meters", roomArea);
    Console::WriteLine(L"Price of carpeting {0:F2} UAH", carpetPrice);
}



void Task2()
{
    String^ firstStr;
    String^ secondStr;

    Console::Write(L"Enter the first string: ");
    firstStr = Console::ReadLine();

    Console::Write(L"Enter the second string: ");
    secondStr = Console::ReadLine();

    String^ result = firstStr + L" " + secondStr;

    Console::WriteLine(L"Merged string: {0}", result);
}



void Task3()
{
    String^ strOne;
    String^ strTwo;

    Console::WriteLine(L"Enter two strings to compare: ");

    Console::Write(L"First word: ");
    strOne = Console::ReadLine();

    Console::Write(L"Second word: ");
    strTwo = Console::ReadLine();

    int result = String::Compare(strOne, strTwo, true);

    if (result < 0) {
        Console::WriteLine(L"{0} comes before {1}", strOne, strTwo);
    }
    else if (result == 0) {
        Console::WriteLine(L"These lines are identical");
    }
    else {
        Console::WriteLine(L"{0} comes after {1}", strOne, strTwo);
    }
}



void Task4()
{
    String^ userInput;
    String^ beginStr = L"begin ";
    String^ endStr = L" end";

    String^ result = L"";

    while (true) {
        Console::WriteLine(L"Enter the words: ");
        userInput = Console::ReadLine();

        if (!String::IsNullOrEmpty(userInput)) {
            break;
        }

        Console::WriteLine(
            L"Error: Input cannot be empty! Please try again");
    }

    result = beginStr + userInput + endStr;

    int length = result->Length;

    Console::WriteLine(L"Result string: {0}", result);
    Console::WriteLine(L"Length of the result string: {0}", length);
}


void Task5()
{
    String^ userInput;
    String^ reversedResult = L"";

    while (true) {
        Console::WriteLine(L"Enter the words: ");
        userInput = Console::ReadLine();

        if (!String::IsNullOrEmpty(userInput)) {
            break;
        }

        Console::WriteLine(
            L"Error: Input cannot be empty! Please try again");
    }

    int length = userInput->Length;

    for (int i = length - 1; i >= 0; i--) {
        reversedResult += userInput[i];
    }

    Console::WriteLine(L"Original result: {0}", userInput);
    Console::WriteLine(L"Reversed result: {0}", reversedResult);
}


void Task6()
{
    String^ firstStr;
    String^ secondStr;

    while (true) {
        Console::WriteLine(L"Enter the first line: ");
        firstStr = Console::ReadLine();

        Console::WriteLine(L"Enter the second line: ");
        secondStr = Console::ReadLine();

        if (!String::IsNullOrEmpty(firstStr) &&
            !String::IsNullOrEmpty(secondStr)) {
            break;
        }

        Console::WriteLine(
            L"Error: Input cannot be empty! Please try again");
    }

    int firstLen = firstStr->Length;
    int secondLen = secondStr->Length;

    if (firstLen > secondLen) {
        Console::WriteLine(
            L"The '{0}' is longer than the '{1}'", firstStr, secondStr);
    }
    else if (secondLen > firstLen) {
        Console::WriteLine(
            L"The '{0}' is longer than the '{1}'", secondStr, firstStr);
    }
    else {
        Console::WriteLine(L"Strings of equal length");
    }
}


// Main function
int main(array<System::String^>^ args)
{
    int choice;

    while (true) {
        Console::WriteLine(L"\n---------- MENU ----------");
        Console::WriteLine(L"1. Calculate carpet price");
        Console::WriteLine(L"2. Merge two strings");
        Console::WriteLine(L"3. Compare two strings");
        Console::WriteLine(L"4. Add 'begin' and 'end' to a string");
        Console::WriteLine(L"5. Reverse a string");
        Console::WriteLine(L"6. Compare the length of two strings");
        Console::WriteLine(L"0. Exit");
        Console::WriteLine(L"------------------------------------");

        Console::Write(L"Choose an option: ");

        try {
            choice = Int32::Parse(Console::ReadLine());
        }
        catch (FormatException^) {
            Console::WriteLine(L"Invalid input! Please enter a number.");
            continue;
        }

        switch (choice) {
        case 1:
            Task1();
            break;

        case 2:
            Task2();
            break;

        case 3:
            Task3();
            break;

        case 4:
            Task4();
            break;

        case 5:
            Task5();
            break;

        case 6:
            Task6();
            break;

        case 0:
            Console::WriteLine(L"Program terminated.");
            return 0;

        default:
            Console::WriteLine(L"Invalid menu option! Try again.");
            break;
        }
    }

    return 0;
}