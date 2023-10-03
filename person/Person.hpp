#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <ostream>

using namespace std;

class Person
{
private:
    string name;
    string lastName;
    int age;

public:
    /* Constructor and Destructor */
    Person();
    Person(string name, string lastName, int age);
    ~Person();

    /* Getters and Setters */
    string getName() const;
    void setName(string name);

    string getLastName() const;
    void setLastName(string lastName);

    int getAge() const;
    void setAge(int age);

    /* Operators */

    bool operator<(Person const &otherPerson) const;
    bool operator>(Person const &otherPerson) const;

    bool operator==(Person const &otherPerson) const;

    bool operator!=(Person const &otherPerson) const;

    friend ostream &operator<<(ostream &os, Person const &person);
};
#include "Person.cpp"
#endif // PERSON_HPP
