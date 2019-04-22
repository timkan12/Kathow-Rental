#ifndef CAR_HASH_TABLE
#define CAR_HASH_TABLE
#include <string>
#include <iostream>

using namespace std;
struct carName
{
    string name;
    int year;
    int count;
    carName* next;
  //  int isRented;   // flag that will be set if car is already rented.
};

class carHashTable {
  public:
    carHashTable();
    void HashTable(int tableSize);
    ~carHashTable();
    void addCar(string name, int year);
    bool isInTable(string name);
    void incrementCount(string name);
    int getNumCollisions();
    int uniqueCars();
  //  int getTotalUsers();

  private:

    unsigned int getHash(string name);
    carName* searchTable(string name);
    carName** hashTable;
    int hashTableSize;
    int numItems; // num of users
    int numCollisions; // find # of collisions
};

#endif
