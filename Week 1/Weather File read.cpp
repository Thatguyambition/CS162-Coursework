//Jesse Lund
//CS162 Week 1 Lab 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Basic setup from instructions
    const int MAX = 15 * 18;
    string date[MAX], low[MAX], high[MAX], rain[MAX], summary[MAX], dummy;

    // Open the file
    ifstream infile("data.txt");

    // Check if file opened
    if (!infile) {
        cout << "File could not be opened!" << endl;
        return 0;
    }

    cout << "Hello World, let's talk weather" << endl;
    cout << "File opened successfully" << endl;

    // Skip the first header line
    getline(infile, dummy);

    // Loop through the data
    for (int count = 0; count < 12; ++count) {
    // Read the specific columns using comma delimiter
        getline(infile, date[count], ',');
        getline(infile, low[count], ',');
        getline(infile, high[count], ',');
        
    // Read the chance of rain 
        getline(infile, rain[count], ',');
        
    // Read the summary
        getline(infile, summary[count], ',');

    // Read the rest of the line into dummy to move to the next row
        getline(infile, dummy);

    // Simple output to match the goal
        cout << date[count] << ": " << low[count] << " to " << high[count] 
             << " degrees and " << rain[count] << "% chance of rain. Overall, " 
             << summary[count] << "." << endl;
    }

    infile.close();
    return 0;
}
