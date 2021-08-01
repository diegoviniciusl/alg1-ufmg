#include "VaccinationCenter.h"

VaccinationCenter::VaccinationCenter()
{
    this->id = -1;
    this->capacity = 0;
}

void VaccinationCenter::setId(int id)
{
    this->id = id;
}

void VaccinationCenter::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void VaccinationCenter::setX(int x)
{
    this->x = x;
}

void VaccinationCenter::setY(int y)
{
    this->y = y;
}

void VaccinationCenter::calculateCurrentDistance(int x, int y)
{
    this->currentDistance = pow((x - this->x), 2) + pow((y - this->y), 2);
}

void VaccinationCenter::pushPersonId(int personId)
{
    this->personsIds.push_back(personId);
    this->capacity--;
}

int VaccinationCenter::getId()
{
    return this->id;
}

int VaccinationCenter::getCapacity()
{
    return this->capacity;
}

int VaccinationCenter::getX()
{
    return this->x;
}

int VaccinationCenter::getY()
{
    return this->y;
}

vector<int> VaccinationCenter::getPersonsIds()
{
    return this->personsIds;
}

int VaccinationCenter::getCurrentDistance()
{
    return this->currentDistance;
}
