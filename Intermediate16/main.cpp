//
//  main.cpp
//  Intermediate16
//
//  Created by Atticus Young on 4/14/24.
//

#include <iostream>
using namespace std;

const double growthRate = 0.055; // Stores the annual growth rate (5.5%)

// Global variables to store sales and year information
double sales;
int years = 0;
vector<double> salesList;
vector<int> yearsList;

// Function to print the elements of a double vector
void printSales(vector<double> const &a) {
  cout << "Sales: ";
  for (int i = 0; i < a.size(); i++)
    cout << a.at(i) << ' ';
  cout << endl;
}

// Function to print the elements of an integer vector
void printYears(vector<int> const &a) {
  cout << "Years: ";
  for (int i = 0; i < a.size(); i++)
    cout << a.at(i) << ' ';
  cout << endl;
}

// Function to calculate annual sales increase
static void annualSalesIncrease(double sales) {
  while (true) { // Loop to continuously prompt for sales figures until -1 is entered
    cout << "Enter sales price (enter -1 as the terminator) \n";
    cin >> sales;
    if (sales == -1) {
      goto output; // Jump to the output section when -1 is entered
    }

    // Loop to increase sales based on growth rate until it reaches $150,000
    while (sales < 150000) {
      sales += sales * growthRate;
      years++;
    }

    // Add the final sales figure and year to their respective vectors
    salesList.push_back(sales);
    yearsList.push_back(years);
    years = 0; // Reset years counter for the next iteration
  }

output:  // Label for the jump statement
  printSales(salesList);
  cout << "\n";
  printYears(yearsList);
}

int main(int argc, const char *argv[]) {
  annualSalesIncrease(sales);
  return 0;
}
