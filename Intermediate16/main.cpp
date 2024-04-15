//
//  main.cpp
//  Intermediate16
//
//  Created by Atticus Young on 4/14/24.
//

#include <iostream>
using namespace std;

const double growthRate = 0.055;
double sales;
int years = 0;
vector<double> salesList;
vector<int> yearsList;

void printSales(vector <double> const &a) {
   cout << "Sales: ";

   for(int i=0; i < a.size(); i++)
   cout << a.at(i) << ' ';
}

void printYears(vector <int> const &a) {
   cout << "Years: ";

   for(int i=0; i < a.size(); i++)
   cout << a.at(i) << ' ';
}

static void annualSalesIncrease(double sales) {
    while (1) {
        cout << "Enter sales price (enter -1 as the terminator) \n";
        cin >> sales;
        if (sales == -1) {
            goto output;
        }
        
        while (sales < 150000) {
            sales += sales * growthRate;
            years++;
        }
        salesList.push_back(sales);
        yearsList.push_back(years);
        years = 0;
    }
    
    output:
    printSales(salesList);
    cout << "\n";
    printYears(yearsList);
};

int main(int argc, const char * argv[]) {
    annualSalesIncrease(sales);
}

