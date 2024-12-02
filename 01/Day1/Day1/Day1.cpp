// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>


int main()
{

    using namespace std::literals;
    std::cout << "Day 1\n";

    const std::chrono::time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();

    // read in input into two vectors, and one frequency map
    std::vector<int> col1;
    std::vector<int> col2;
    std::map<int, size_t> col2Freq;

    std::ifstream infile("input.txt");

    // Use a while loop together with the getline() function to read the file line by line
    int a, b;
    while (infile >> a >> b)
    {
        col1.push_back(a);
        col2.push_back(b);
        // populate hashmap for part two
        if (col2Freq.contains(b))
        {
            col2Freq.at(b) = col2Freq.at(b) + 1;
        } else
        {
            col2Freq.emplace(b, 1);
        }
        
    }

    // Close the file
    infile.close();

    // sort each vector
    std::ranges::sort(col1.begin(), col1.end());
    std::ranges::sort(col2.begin(), col2.end());

    // add pairwise
    unsigned long long part1Sum = 0;
    for (size_t i = 0; i < col1.size(); ++i)
    {
        part1Sum += std::abs((col1.at(i) - col2.at(i)));
    }

    // part two
    unsigned long long part2Sum = 0;
    for (auto val : col1)
    {
        if (col2Freq.contains(val)) {
            part2Sum += val * col2Freq.at(val);
        }
    }

    // report sum
    std::cout << "Part 1: "
        << part1Sum
        << std::endl
        << "Part 2: "
        << part2Sum
        << std::endl;

    const std::chrono::time_point<std::chrono::steady_clock> endTime = std::chrono::steady_clock::now();
    std::cout << "The total elapsed time is: "
              << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()
              << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
