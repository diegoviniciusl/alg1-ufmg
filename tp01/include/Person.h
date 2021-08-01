#ifndef PERSON_H
#define PERSON_H

#include "VaccinationCenter.h"

class Person
{

public:
    Person();
    void setId(int id);
    void setAge(int age);
    void setX(int x);
    void setY(int y);
    void insertVaccinationCenters(vector<VaccinationCenter *> vaccinationCenters);
    int getId();
    int getAge();
    int getX();
    int getY();
    vector<VaccinationCenter *> getClosestVaccinationCenters();

private:
    int id;
    int age;
    int x;
    int y;
    vector<VaccinationCenter *> closestVaccinationCenters;
};

#endif
