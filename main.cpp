//
//  main.cpp
//  assign 2
//
//  Created by toka magdy ragab  on 3/27/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#include <iostream>
#include "ReservationList.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ReservationList rl;
    bool exit = false;
    int choice;
    node temp;
    string key;
        while (!exit)
        {
            cout << "1-add reservations." << endl
                 << "2-cancel a reservation." << endl
                 << "3-update an existing reservation." << endl
                 << "4-sort the reservation list." << endl
                 << "5-print the list of reservations." << endl
                 << "6-search for a spefic reservation." << endl
                 << "7-load data from a file." << endl
                 << "8-save current list to a file." << endl
                 << "9-exit." << endl;
            cin >> choice;
            try
            {
                switch (choice)
                {
                    case 1:
                        int num;
                        cout << "how many reservations do you want to add? ";
                        cin >> num;
                        for (int i = 0; i < num; i++)
                        {
                            cin >> temp;
                            rl.reserve(temp);
                        }
                        break;
                    case 2:
                        cout << "please enter the ID of the reservation you want to cancel: ";
                        cin >> key;
                        rl.cancel(key);
                        cout << "---------------------------------------------" << endl;
                        break;
                    case 3:
                        cout << "please enter the ID of the reservation you want to update: ";
                        cin >> key;
                        cout << "now enter the updated details of that reservation" << endl;
                        cin >> temp;
                        rl.update(key,temp);
                        break;
                    case 4:
                        while (true)
                        {
                            cout << "1-sort by name" << endl
                                 << "2-sort by ID" << endl;
                            cin >> choice;
                            if (choice != 1 && choice != 2)
                            {
                                cout << "unrecognized choice! try again." << endl;
                                continue;
                            }
                            if (choice == 1)
                                rl.SortByName();
                            else
                                rl.SortByID();
                            cout << "the list has been sorted successfully" << endl;
                            cout << "---------------------------------------------" << endl;
                            break;
                        }
                        break;
                    case 5:
                        while (true)
                        {
                            cout << "1-print the list as it is" << endl
                                 << "2-print the list reversed" << endl;
                            cin >> choice;
                            if (choice == 1)
                            {
                                cout << rl;
                                break;
                            }
                            else if (choice == 2)
                            {
                                rl.PrintReversed();
                                break;
                            }
                            else
                                cout << "unrecognized choice! try again." << endl;
                        }
                        break;
                        case 6:
                        while (true)
                        {
                            cout << "1-search using reservation ID" << endl
                                 << "2-search using traveler's name" << endl
                                 << "3-search using traveler's mobile number" << endl
                                 << "4-search using take-off airport" << endl
                                 << "5-search using destination airport" << endl;
                            cin >> choice;
                            if (choice > 0 && choice < 6)
                            {
                                cout << "enter the keyword: ";
                                cin.ignore();
                                getline(cin,key);
                                cout << rl.check(key, static_cast<type>(choice-1));
                                break;
                            }
                            else cout << "unrecognized choice! try again." << endl;
                        }
                        break;
                        case 7:
                        cout << "please enter the directory of the file you want to load reservations from: ";
                        cin >> key;
                        rl.LoadFromFile(key);
                        cout << "loading has been done successfully" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                        case 8:
                        cout << "please enter the directory of the file you want to save reservations to: ";
                        cin >> key;
                        rl.SaveToFile(key);
                        cout << "saving has been done successfully" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                        case 9:
                        return 0;
                    default:
                        cout << "unrecognized choice! try again." << endl;
                        break;
                }
            }
             catch (const char* x)
            {
                 cout << x << endl;
            }
        }
    return 0;
}
