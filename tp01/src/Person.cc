#include "Person.h"

Person::Person()
{
    this->id = -1;
}

void Person::setId(int id)
{
    this->id = id;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setX(int x)
{
    this->x = x;
}

void Person::setY(int y)
{
    this->y = y;
}

void Person::insertVaccinationCenters(vector<VaccinationCenter *> vaccinationCenters)
{
    this->closestVaccinationCenters = vaccinationCenters;
}

int Person::getId()
{
    return this->id;
}

int Person::getAge()
{
    return this->age;
}

int Person::getX()
{
    return this->x;
}

int Person::getY()
{
    return this->y;
}

vector<VaccinationCenter *> Person::getClosestVaccinationCenters()
{
    return this->closestVaccinationCenters;
}