#include "pch.h"

using namespace System;


void GenerateVector()
{
    int size;

    Console::WriteLine(L"Enter the size of array: ");
    size = Convert::ToInt32(Console::ReadLine());

    array<int>^ data = gcnew array<int>(size);

    Console::WriteLine(L"Enter the element: ");
    for (int c = 0; c < data->Length; c++)
    {
        int result;

        String^ input = Console::ReadLine();

        if (Int32::TryParse(input, result))
        {
            data[c] = result;
        }

        else
        {
            Console::WriteLine(L"Error: the element must be of string type.");
            c--;
            continue;
        }

    }

    Console::WriteLine(L"Your current array:");

    for (int i = 0; i < data->Length; i++)
    {
        Console::Write(data[i] + " ");
    }

    Array::Reverse(data);

    Console::WriteLine(L"\nNew vector:");

    for (int i = 0; i < data->Length; i++)
    {
        Console::Write(data[i] + " ");
    }

}



void Matrix()
{

    int rows;
    int cols;

    Random^ rand = gcnew Random();

    Console::WriteLine(L"\nEnter the number of rows: ");
    rows = Convert::ToInt32(Console::ReadLine());

    Console::WriteLine(L"Enter the number of columns: ");
    cols = Convert::ToInt32(Console::ReadLine());

    array<int, 2>^ firstMatrix = gcnew array<int, 2>(rows, cols);

    array<int, 2>^ secondMatrix = gcnew array<int, 2>(rows, cols);

    array<int, 2>^ finalMatrix = gcnew array<int, 2>(rows, cols);


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int randomNumber = rand->Next(101);
            firstMatrix[i, j] = randomNumber;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int randomSecondNumber = rand->Next(101);
            secondMatrix[i, j] = randomSecondNumber;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            finalMatrix[i, j] = firstMatrix[i, j] - secondMatrix[i, j];
        }
    }

    Console::WriteLine(L"Print matrix: ");

    Console::WriteLine(L"\nFirst matrix: ");
    for (int i = 0; i < firstMatrix->GetLength(0); i++)
    {
        for (int j = 0; j < firstMatrix->GetLength(1); j++)
        {
            Console::Write(firstMatrix[i, j] + "\t");
        }
        Console::WriteLine();
    }

    Console::WriteLine(L"\nSecond matrix: ");
    for (int i = 0; i < secondMatrix->GetLength(0); i++)
    {
        for (int j = 0; j < secondMatrix->GetLength(1); j++)
        {
            Console::Write(secondMatrix[i, j] + "\t");
        }
        Console::WriteLine();
    }

    Console::WriteLine(L"\nFinal matrix: ");
    for (int i = 0; i < finalMatrix->GetLength(0); i++)
    {
        for (int j = 0; j < finalMatrix->GetLength(1); j++)
        {
            Console::Write(finalMatrix[i, j] + "\t");
        }
        Console::WriteLine();
    }
}




int main(array<System::String ^> ^args)
{
    //GenerateVector();
    Matrix();
    return 0;
}


