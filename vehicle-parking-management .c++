#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    string vehicleNo;
    string ownerName;
    string vehicleType;
    int slotNo;

    Vehicle(string vNo, string oName, string vType, int slot) {
        vehicleNo = vNo;
        ownerName = oName;
        vehicleType = vType;
        slotNo = slot;
    }
};

int main() {
    vector<Vehicle> parkingLot;
    int choice, slotCounter = 1;

    do {
        cout << "\n--- Vehicle Parking Management System ---\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Parked Vehicles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string vNo, oName, vType;

            cout << "Enter Vehicle Number: ";
            cin >> vNo;
            cout << "Enter Owner Name: ";
            cin >> oName;
            cout << "Enter Vehicle Type: ";
            cin >> vType;

            parkingLot.push_back(
                Vehicle(vNo, oName, vType, slotCounter)
            );

            cout << "Vehicle parked at Slot "
                 << slotCounter << endl;
            slotCounter++;
            break;
        }

        case 2: {
            string vNo;
            cout << "Enter Vehicle Number to remove: ";
            cin >> vNo;

            bool found = false;
            for (auto it = parkingLot.begin();
                 it != parkingLot.end(); ++it) {
                if (it->vehicleNo == vNo) {
                    cout << "Vehicle removed from Slot "
                         << it->slotNo << endl;
                    parkingLot.erase(it);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Vehicle not found!\n";
            break;
        }

        case 3: {
            if (parkingLot.empty()) {
                cout << "Parking lot is empty.\n";
            } else {
                cout << "\nParked Vehicles:\n";
                cout << "Slot\tVehicle No\tOwner\tType\n";

                for (const auto &v : parkingLot) {
                    cout << v.slotNo << "\t"
                         << v.vehicleNo << "\t\t"
                         << v.ownerName << "\t"
                         << v.vehicleType << endl;
                }
            }
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

