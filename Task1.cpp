#include "task1.h"

#include <iostream>
using std :: cin;
using std :: cout;
void Ticket :: erase(){
 delete[] ePoint;
 delete[] sPoint;
}
void Ticket :: copy (Ticket& other){
this->setEPoint(other.ePoint);
this->setSPoint(other.sPoint);
this->setTime(other.time);
this->setPrice(other.price);
this->setDuration(other.duration);
this->setBusinessClass(other.businessClass);
this->setFlightSeat(other.flightSeat);
}
Ticket :: ~Ticket(){
    this->erase();
}
Ticket& Ticket :: operator= (Ticket& other){
    if(this!=&other){
        this->erase();
        this->copy(other);
    }
return *this;
}
int Ticket :: getDuration(){
return this->duration; 
}
void Ticket :: setEPoint(char *ePoint){
strcpy(this->ePoint,ePoint);
}
void Ticket :: setSPoint(char *sPoint){
strcpy(this->sPoint,sPoint);
}
void Ticket :: setTime (char time[11]){
strcpy(this->time, time);
}


double Ticket :: getPrice()
{
    return this->price;
}

void Ticket :: setPrice(double price)
{
    this->price = price;
}


int Ticket :: getFlightSeat()
{
    return this->flightSeat;
}

void Ticket :: setFlightSeat(int flightSeat)
{
    this->flightSeat = flightSeat;
}


int Ticket :: getDuration()
{
    return this->duration;
}


void Ticket :: setDuration(int duration)
{
    this->duration = duration;
}


bool Ticket :: isBusinessClass()
{
    return this->businessClass;
}


void Ticket :: setBusinessClass(bool businessClass)
{
    this->businessClass = businessClass;
}

int main(){


}