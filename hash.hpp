#ifndef USER_HASH_TABLE
#define USER_HASH_TABLE
#include <string>

using namespace std;
struct userName
{
    string name;
    userName* next;
};

/*
We have add user to store the user's Username
this might handle collisions incase two people have the same namespace

basic constructor and destructor
add user with a string
intable --see if the user is in table
increment count -- increment users with the same name
unique users see how many users there are with the same name
total users - get total users
*/
class HashTable {
  public:
    HashTable(int hashTableSize);
    ~HashTable();
    void addUser(string name);
    bool isInTable(string name);
    void incrementCount(string name);
    int getNumCollisions();
    int uniqueUsers();
  //  int getTotalUsers();

  private:

    unsigned int getHash(string name);
    userName* searchTable(string name);
    userName** hashTable;
    int hashTableSize;
    int numItems; // num of users
    int numCollisions; // find # of collisions
};

#endif
