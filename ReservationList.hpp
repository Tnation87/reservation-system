//
//  ReservationList.hpp
//  assign 2
//
//  Created by toka magdy ragab  on 3/29/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#ifndef ReservationList_hpp
#define ReservationList_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

enum type {id, name, mob, takeoff, dest};

class node
{
    public:
    string RsservationID, Traveler_Name, Traveler_mob, TakeOffAirport, Dest_Airport;
    node *next;
    node *prev;
    
    
    node()
    {
        next = prev = NULL;
    }
    
    node(node *n, node* p)
    {
        next = n;
        prev = p;
    }
    
    node(string ID, string name, string mob, string takeOff, string Dest, node *n = NULL, node *p = NULL)
    {
        next = n;
        prev = p;
        RsservationID = ID;
        Traveler_Name = name;
        Traveler_mob = mob;
        TakeOffAirport = takeOff;
        Dest_Airport = Dest;
    }
    
    friend istream& operator>>(istream& in, node& n)
    {
        cout << "reservation ID: ";
        in >> n.RsservationID;
        in.ignore();
        cout << "traveler's name: ";
        getline(in,n.Traveler_Name);
        cout << "traveler's mobile number: ";
        in >> n.Traveler_mob;
        in.ignore();
        cout << "take-off airport: ";
        getline(in,n.TakeOffAirport);
        cout << "destination airport: ";
        getline(in,n.Dest_Airport);
        cout << "---------------------------------------------" << endl;
        return in;
    }
    
     friend ostream& operator<<(ostream& out, const node& tmp)
    {
        out << "reservation ID: " << tmp.RsservationID << endl;
        out << "traveler's name: " << tmp.Traveler_Name << endl ;
        out << "traveler's mobile number: " << tmp.Traveler_mob << endl ;
        out << "take-off airport: " << tmp.TakeOffAirport << endl ;
        out << "destination airport: " << tmp.Dest_Airport << endl ;
        out << "---------------------------------------------" << endl;
        return out;
    }
};

class ReservationList
{
public:
    ReservationList();
    ~ReservationList();
    bool isEmpty() const;
    void setToNull();
    void reserve(node);
    void cancel(string);
    void update(string,node);
    void SortByName();
    void SortByID();
    void PrintReversed();
    void SaveToFile(string);
    void LoadFromFile(string);
    node check(string, type);
    
protected:
    node *head, *tail;
    friend ostream& operator<<(ostream& out, const ReservationList& dll)
    {
        for (node *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << *tmp;
        return out;
    }
};

#endif /* ReservationList_hpp */
