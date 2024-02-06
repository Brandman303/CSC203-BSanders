#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int totalCost(int hours, int vehicleCost);

int main() {
    string yesNo;
    int hours;
    int vehicleType;
    int vehicleCost[] = { 2, 3, 4 };
    const string VEHICLE[] = { "car", "bus", "truck" };

    cout << "Do you want to park? y/n" << endl;
    cin >> yesNo;
    transform(yesNo.begin(), yesNo.end(), yesNo.begin(), ::tolower);

    if (yesNo == "y" || yesNo == "yes") {
        bool trueFalse = true;
        while (trueFalse) {
            cout << "Please enter the number of hours you wish to park in integer form." << endl;
            cin >> hours;

            if (hours > 0) {
                cout << "Please enter the number associated with your vehicle type:" << endl;
                cout << "1. car" << endl;
                cout << "2. bus" << endl;
                cout << "3. truck" << endl;
                cin >> vehicleType;

                if (vehicleType >= 1 && vehicleType <= 3) {
                    int finalTotal = totalCost(hours, vehicleCost[vehicleType - 1]);
                    cout << "Total cost: $" << finalTotal << endl;
                    trueFalse = false;
                }
                else {
                    cout << "Incorrect input for vehicle type." << endl;
                }
            }
            else {
                cout << "Not a vaild input for number of hours" << endl;
            }
        
        }
    }
    else {
        cout << "Goodbye" << endl;
        
    }

    return 0;
}

int totalCost(int hours, int vehicleCost) {
    return hours * vehicleCost;
}


