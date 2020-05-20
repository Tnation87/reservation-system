//
//  ReservationList.cpp
//  assign 2
//
//  Created by toka magdy ragab  on 3/29/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#include "ReservationList.hpp"
#include <fstream>
#include <cstring>

ReservationList::ReservationList()
{
    head = tail = 0;
}

ReservationList::~ReservationList()
{
    while (head != 0 && head->next != 0)
    {
        head = head->next;
        delete head->prev;
    }
    if (tail != 0)
    delete tail;
        
 }

bool ReservationList::isEmpty() const
{
    return head == 0;
}

void ReservationList::setToNull() {
    head = tail = 0;
}

void ReservationList::reserve(node info)
{
    if (isEmpty())
    {
        head = new node(info.RsservationID,info.Traveler_Name,info.Traveler_mob,info.TakeOffAirport,info.Dest_Airport);
        tail = head;
    }
    else
    {
        string c = (this->check(info.RsservationID, id)).RsservationID;
        if (c != "not found")
            throw "ID already exists";
        node *temp = new node(info.RsservationID,info.Traveler_Name,info.Traveler_mob,info.TakeOffAirport,info.Dest_Airport,0,tail);
        tail->next = temp;
        tail = temp;
    }
}

void ReservationList::update(string id,node info)
{
    node *temp;
    for (temp = head; temp->RsservationID != id && temp != 0; temp = temp->next);
    if (temp == 0)
        throw "given ID not on the list";
    else
    {
        temp->RsservationID = info.RsservationID;
        temp->Traveler_Name = info.Traveler_Name;
        temp->Traveler_mob = info.Traveler_mob;
        temp->TakeOffAirport = info.TakeOffAirport;
        temp->Dest_Airport = info.Dest_Airport;
    }
}

void ReservationList::cancel(string id)
{
    node *temp;
    for (temp = head; temp->RsservationID != id && temp != 0; temp = temp->next);
    if (temp == 0)
        throw "given ID not on the list";
    else if (temp == head)
    {
        head = head->next;
        head->prev = 0;
    }
    else if (temp == tail)
    {
        tail = tail->prev;
        tail->next = 0;
    }
    else
    {
        (temp->next)->prev = temp->prev;
        (temp->prev)->next = temp->next;
    }
    delete temp;
    
}

void ReservationList::SortByName()
{
    if(isEmpty() || head == tail)
        return;
    node *temp = new node;
    for (node *i = head->next,*j; i != 0; i = i->next)
    {
        temp->RsservationID = i->RsservationID;
        temp->Traveler_Name = i->Traveler_Name;
        temp->Traveler_mob = i->Traveler_mob;
        temp->TakeOffAirport = i->TakeOffAirport;
        temp->Dest_Airport = i->Dest_Airport;
        for (j = i; j != head && temp->Traveler_Name < j->prev->Traveler_Name; j = j->prev)
        {
            j->RsservationID = j->prev->RsservationID;
            j->Traveler_Name = j->prev->Traveler_Name;
            j->Traveler_mob = j->prev->Traveler_mob;
            j->TakeOffAirport = j->prev->TakeOffAirport;
            j->Dest_Airport = j->prev->Dest_Airport;
        }
        j->RsservationID = temp->RsservationID;
        j->Traveler_Name = temp->Traveler_Name;
        j->Traveler_mob = temp->Traveler_mob;
        j->TakeOffAirport = temp->TakeOffAirport;
        j->Dest_Airport = temp->Dest_Airport;
    }
    delete temp;
}

void ReservationList::SortByID()
{
    if(isEmpty() || head == tail)
        return;
    node *temp = new node;
    for (node *i = head->next,*j; i != 0; i = i->next)
    {
        temp->RsservationID = i->RsservationID;
        temp->Traveler_Name = i->Traveler_Name;
        temp->Traveler_mob = i->Traveler_mob;
        temp->TakeOffAirport = i->TakeOffAirport;
        temp->Dest_Airport = i->Dest_Airport;
        for (j = i; j != head && temp->RsservationID < j->prev->RsservationID; j = j->prev)
        {
            j->RsservationID = j->prev->RsservationID;
            j->Traveler_Name = j->prev->Traveler_Name;
            j->Traveler_mob = j->prev->Traveler_mob;
            j->TakeOffAirport = j->prev->TakeOffAirport;
            j->Dest_Airport = j->prev->Dest_Airport;
        }
        j->RsservationID = temp->RsservationID;
        j->Traveler_Name = temp->Traveler_Name;
        j->Traveler_mob = temp->Traveler_mob;
        j->TakeOffAirport = temp->TakeOffAirport;
        j->Dest_Airport = temp->Dest_Airport;
    }
    delete temp;
}


void ReservationList::PrintReversed()
{
    for (node *tmp = tail; tmp != 0; tmp = tmp->prev)
        cout << *tmp;
}

node ReservationList::check(string key,type t)
{
    node *temp, val;
    bool GetOutOfLoop = false;
    for (temp = head; temp != 0; temp = temp->next)
    {
        switch (t)
        {
            case 0:
                if (temp->RsservationID == key)
                    GetOutOfLoop = true;
                break;
            case 1:
                if (temp->Traveler_Name == key)
                    GetOutOfLoop = true;
                break;
            case 2:
                if (temp->Traveler_mob == key)
                    GetOutOfLoop = true;
                break;
            case 3:
                if (temp->TakeOffAirport == key)
                    GetOutOfLoop = true;
                break;
            case 4:
                if (temp->Dest_Airport == key)
                    GetOutOfLoop = true;
                break;
            default:
                throw "unrecognized type";
        }
        if (GetOutOfLoop)
            break;
    }
    if (temp == 0)
    {
        val.RsservationID = "not found";
        val.Traveler_Name = "not found";
        val.Traveler_mob = "not found";
        val.TakeOffAirport = "not found";
        val.Dest_Airport = "not found";
    }
    else
    {
        val.RsservationID = temp->RsservationID;
        val.Traveler_Name = temp->Traveler_Name;
        val.Traveler_mob = temp->Traveler_mob;
        val.TakeOffAirport = temp->TakeOffAirport;
        val.Dest_Airport = temp->Dest_Airport;
    }
    return val;
}

void ReservationList::SaveToFile(string directory)
{
    fstream file(directory, ios::out);
    for (node *temp = head; temp != 0; temp = temp->next)
    {
        file.write((temp->RsservationID).c_str(),(temp->RsservationID).size());
        file << endl;
        file.write((temp->Traveler_Name).c_str(),(temp->Traveler_Name).size());
        file << endl;
        file.write((temp->Traveler_mob).c_str(),(temp->Traveler_mob).size());
        file << endl;
        file.write((temp->TakeOffAirport).c_str(),(temp->TakeOffAirport).size());
        file << endl;
        file.write((temp->Dest_Airport).c_str(),(temp->Dest_Airport).size());
        file << endl;
    }
    file.close();
}

void ReservationList::LoadFromFile(string directory)
{
    fstream file(directory, ios::in);
    node temp;
    if(file.is_open())
    {
        while (!(file.eof()))
        {
            getline(file, temp.RsservationID);
            getline(file, temp.Traveler_Name);
            getline(file, temp.Traveler_mob);
            getline(file, temp.TakeOffAirport);
            getline(file, temp.Dest_Airport);
            reserve(temp);
        }
        file.close();
    }
    else
        throw "couldn't open file";
}
