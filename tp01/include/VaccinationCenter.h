#ifndef VACCINATION_CENTER_H
#define VACCINATION_CENTER_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class VaccinationCenter
{

public:
    VaccinationCenter();
    void setId(int id);
    void setCapacity(int capacity);
    void setX(int x);
    void setY(int y);
    void calculateCurrentDistance(int x, int y);
    void pushPersonId(int personId);
    int getId();
    int getCapacity();
    int getX();
    int getY();
    vector<int> getPersonsIds();
    int getCurrentDistance();

private:
    int id;
    int capacity;
    int x;
    int y;
    vector<int> personsIds;
    int currentDistance;
};

#endif
