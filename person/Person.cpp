#include "Person.hpp"

Person::Person() = default;

Person::Person(string name, string lastName, int age)
{
    this->name = name;
    this->lastName = lastName;
    this->age = age;
}

Person::~Person()
{
}

string Person::getName() const
{
    return name;
}

void Person::setName(string name)
{
    this->name = name;
}

string Person::getLastName() const
{
    return lastName;
}

void Person::setLastName(string lastName)
{
    this->lastName = lastName;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int age)
{
    this->age = age;
}

bool Person::operator<(Person const &otherPerson) const
{
    return age < otherPerson.age;
}

bool Person::operator>(Person const &otherPerson) const
{
    return age > otherPerson.age;
}

bool Person::operator==(Person const &otherPerson) const
{

    return name == otherPerson.name && lastName == otherPerson.lastName && age == otherPerson.age;
}

bool Person::operator!=(Person const &otherPerson) const
{
    return name != otherPerson.name || lastName != otherPerson.lastName || age != otherPerson.age;
}

ostream &operator<<(ostream &os, Person const &person)
{
    os << person.name << " " << person.lastName << " " << person.age;
    return os;
}
