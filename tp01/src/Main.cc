#include "Person.h"
#include <fstream>
#include <algorithm>

vector<VaccinationCenter *> getVaccinationCenters()
{
    string quantity, capacity, x, y;
    cin >> quantity;
    vector<VaccinationCenter *> vaccinationCenters;
    for (int i = 0; i < stoi(quantity); ++i)
    {
        cin >> capacity >> x >> y;
        VaccinationCenter *vaccinationCenter = new VaccinationCenter();
        vaccinationCenter->setId(i);
        vaccinationCenter->setCapacity(stoi(capacity));
        vaccinationCenter->setX(stoi(x));
        vaccinationCenter->setY(stoi(y));
        vaccinationCenters.push_back(vaccinationCenter);
    }
    return vaccinationCenters;
}

vector<Person *> getPersons()
{
    string quantity, age, x, y;
    cin >> quantity;
    vector<Person *> persons;
    for (int i = 0; i < stoi(quantity); ++i)
    {
        cin >> age >> x >> y;
        Person *person = new Person();
        person->setId(i);
        person->setAge(stoi(age));
        person->setX(stoi(x));
        person->setY(stoi(y));
        persons.push_back(person);
    }
    return persons;
}

bool comparisonByAge(Person *a, Person *b)
{
    if (a->getAge() == b->getAge())
    {
        return a->getId() < b->getId();
    }
    return a->getAge() > b->getAge();
}

bool comparisonByCurrentDistance(VaccinationCenter *a, VaccinationCenter *b)
{
    if (a->getCurrentDistance() == b->getCurrentDistance())
    {
        return a->getId() < b->getId();
    }
    return a->getCurrentDistance() < b->getCurrentDistance();
}

bool comparisonById(VaccinationCenter *a, VaccinationCenter *b)
{
    return a->getId() < b->getId();
}

void prioritizeVaccinationCenters(vector<Person *> &persons, vector<VaccinationCenter *> &vaccinationCenters)
{
    sort(persons.begin(), persons.end(), comparisonByAge);
    for (unsigned int i = 0; i < persons.size(); ++i)
    {
        for (unsigned int j = 0; j < vaccinationCenters.size(); ++j)
        {
            vaccinationCenters[j]->calculateCurrentDistance(persons[i]->getX(), persons[i]->getY());
        }
        sort(vaccinationCenters.begin(), vaccinationCenters.end(), comparisonByCurrentDistance);
        persons[i]->insertVaccinationCenters(vaccinationCenters);
    }
}

void setVaccinationCenters(vector<Person *> &persons)
{
    for (unsigned int i = 0; i < persons.size(); ++i)
    {
        for (unsigned int j = 0; j < persons[i]->getClosestVaccinationCenters().size(); ++j)
        {
            if (persons[i]->getClosestVaccinationCenters()[j]->getCapacity() > 0)
            {
                persons[i]->getClosestVaccinationCenters()[j]->pushPersonId(persons[i]->getId());
                break;
            }
        }
    }
}

void printResult(vector<VaccinationCenter *> &vaccinationCenters)
{
    sort(vaccinationCenters.begin(), vaccinationCenters.end(), comparisonById);
    for (unsigned int i = 0; i < vaccinationCenters.size(); ++i)
    {
        if (vaccinationCenters[i]->getPersonsIds().size() == 0)
            continue;
        cout << vaccinationCenters[i]->getId() << endl;
        for (unsigned int j = 0; j < vaccinationCenters[i]->getPersonsIds().size(); ++j)
        {
            cout << vaccinationCenters[i]->getPersonsIds()[j];
            if (j != vaccinationCenters[i]->getPersonsIds().size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void cleanUp(vector<Person *> &persons, vector<VaccinationCenter *> &vaccinationCenters)
{

    for (unsigned int i = 0; i < vaccinationCenters.size(); ++i)
    {
        delete vaccinationCenters[i];
    }
    for (unsigned int i = 0; i < persons.size(); ++i)
    {
        delete persons[i];
    }
}

int main(int argc, char *argv[])
{
    vector<VaccinationCenter *> vaccinationCenters = getVaccinationCenters();
    vector<Person *> persons = getPersons();
    prioritizeVaccinationCenters(persons, vaccinationCenters);
    setVaccinationCenters(persons);
    printResult(vaccinationCenters);
    cleanUp(persons, vaccinationCenters);
    return 0;
}