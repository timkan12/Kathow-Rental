#include <iostream>
#include "Carhash.hpp"
using namespace std;

carHashTable::carHashTable()
{

}
void carHashTable::HashTable(int tableSize)
{
  hashTableSize = tableSize;
  hashTable = new carName *[hashTableSize];
  for(int i = 0; i < tableSize; i++)
  {
    hashTable[i] = NULL;
  }
  numItems = 0;
  numCollisions = 0;
}

carHashTable::~carHashTable()
{
  for(int i = 0; i < hashTableSize; i++)
  {
    carName *temp = hashTable[i];
    while(temp != NULL)
    {
      carName *del = temp->next;
      delete temp;
      temp = del;
    }
  }
  delete [] hashTable;
}

void carHashTable::addCar(string name, int year)
{
  carName *newCar = new carName;
  newCar->name = name;
  newCar->year = year;
  newCar->next = NULL;
  newCar->count = 1;
  newCar->isRented = 0;

  int index = getHash(name);
  carName *temp = hashTable[index];

  if(temp != NULL)
  {
    numCollisions = numCollisions + 1;
    newCar->next = hashTable[index];
    hashTable[index] = newCar;
  }
  else
  {
    hashTable[index] = newCar;
  }
  numItems++;
}

bool carHashTable::isInTable(string name)  // use this when user enters car name, and search the table
{
  int index = getHash(name);
  if(hashTable[index] == NULL)
  {
    return false;
  }
  else
  {
    bool check = false;
    carName *temp = hashTable[index];
    while(temp != NULL)
    {
      if(temp->name == name)
      {
        return true;
      }
      temp = temp->next;
    }
    return check;
  }
}

void carHashTable::incrementCount(string name) // not using
{
  carName *temp = searchTable(name);
  temp->count = temp->count+1;
}

int userHashTable::getNumCollisions()  // not using
{
  return numCollisions;
}

int carHashTable::uniqueCar()    // not using
{
  int index = 0;
  for(int i = 0; i < hashTableSize; i++)
  {
    carName *temp = hashTable[i];
    while(temp != NULL)
    {
      index = index + temp->count;
      temp = temp->next;
    }
  }
  return index;
}

unsigned int carHashTable::getHash(string name);
{
  int length = name.length();
  for(int i = 0; i < length; i++)
  {
    hashValue = ((hashValue<<5) + word[i]);
  }
  hashValue %= hashTableSize;

  return hashValue;
}

carName* carHashTable::searchTable(string name)  // when they enter the car name, it will look for the car.
{
  carName *newCar = hashTable[getHash(name)];  // changed word , to name
  while(newCar != NULL && newCar->name != name)
  {
    newCar = newCar->next;
  }
  return newCar;
}
