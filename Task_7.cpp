#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
void setupDonationSystem(vector<string>& charityNames, double& total1, double& total2, double& total3);
void recordAndTotalDonation(vector<string>& charityNames, double& total1, double& total2, double& total3);
void showTotalsSoFar(const vector<string>& charityNames, double total1, double total2, double total3);

int main() {
    vector<string> charityNames;
    double total1 = 0.0, total2 = 0.0, total3 = 0.0;

    // Task 1 - Set up the donation system
    setupDonationSystem(charityNames, total1, total2, total3);

    // Task 2 - Record and total each donation
    recordAndTotalDonation(charityNames, total1, total2, total3);

    // Task 3 - Show the totals so far
    showTotalsSoFar(charityNames, total1, total2, total3);

    return 0;
}

void setupDonationSystem(vector<string>& charityNames, double& total1, double& total2, double& total3) {
    

    for (int i = 0; i < 3; ++i) {
        string charityName;
        cout << "Enter the name of Charity " << i + 1 << ": ";
        cin >> charityName;
        charityNames.push_back(charityName);
    }

    cout << "Charity Options:\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << charityNames[i] << endl;
    }
}

void recordAndTotalDonation(vector<string>& charityNames, double& total1, double& total2, double& total3) {
    

    int choice;
    double shoppingBill;

    cout << "Enter -1 to finish recording donations.\n";

    while (true) {
        cout << "Enter the charity choice (1, 2, or 3) or -1 to finish: ";
        cin >> choice;

        if (choice == -1) {
            break;
        }

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            continue;
        }

        cout << "Enter the value of the customer's shopping bill: $";
        cin >> shoppingBill;

        double donation = shoppingBill * 0.01;

        switch (choice) {
            case 1:
                total1 += donation;
                break;
            case 2:
                total2 += donation;
                break;
            case 3:
                total3 += donation;
                break;
        }

        cout << "Donation of $" << donation << " recorded for " << charityNames[choice - 1] << ".\n";
    }
}

void showTotalsSoFar(const vector<string>& charityNames, double total1, double total2, double total3) {
   

    vector<pair<string, double>> totals = {
        {charityNames[0], total1},
        {charityNames[1], total2},
        {charityNames[2], total3}
    };

    sort(totals.begin(), totals.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second > b.second;
    });

    double grandTotal = total1 + total2 + total3;

    cout << "Charity Totals:\n";
    for (const auto& entry : totals) {
        cout << entry.first << ": $" << entry.second << endl;
    }

    cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << grandTotal << endl;
}

