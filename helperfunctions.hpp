#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// struct to make user objects.
struct customer{
public:
  string name;
  string carBrand;
  string year;
  int isRented; // 0 = haven't rented out a car yet, 1 = rented out a car already
};

int searchForUserInArray(customer* myArray[], int currentSize, string given_name)
{
  for(int i = 0 ; i < currentSize; i++)
  {
    if (myArray[i]->name == given_name)
    {
      //cout << "found" << endl;
      return i; // returns the index of the customer that it found.
    }
  }
  return -1;
}

/*
  function should take the user name and assign it the car in the hash table if its
  not already taken ( you know its taken if the flag in the car struct is set to 0 or 1)
  so you have to find the car name in the hashtable and look at that flag
  if its set to 1
    tell the user the car is taken and ask for a different one or just exit the program
  if its set to 0
    then set the user objects carBrand to that cars name and year, then change its flag to 1
    then exit
*/
// void rentCar(string userName, string brand, string year){
//   cout << "Enter name of car you would like to rent. " << endl;
//   getline(cin,brand);
//   //searchTable(brand);
//
//   cout << "Enter your desire year for the car" << endl;
//   getline(cin,year);
//   customer* newCustomer = new customer;
//   newCustomer->name = userName;
//   newCustomer->carBrand = brand;
//   newCustomer->year = year;
//
// }


/*
  this will be called when the program exits, write out all the information
  currently in the user array to the text file so it can be read from
  and loaded when the program starts. It will be loaded from the function below

  break down each object and write it on its own line

*/
void writeOutAllArrayInformation(customer* myArray[], int currentSize)
{
  ofstream testFileName;
  testFileName.open ("customerinformation.txt");
  if(testFileName.is_open())
  {
  for(int i = 0 ; i < currentSize; i++)
    {
      testFileName << myArray[i]->name << "," << myArray[i]->carBrand << "," << myArray[i]->year << "," << myArray[i]->isRented << endl;
    }
  }
  else
  {
  testFileName.close();
  // write to that text file
  }

}


/*
  read in from this text file and for every line should be a user, and for every user
  create a object and put it in the array.

  everytime you put something in the array increment a counter for currentUser in the array
  then


  need to parse everyline and create new objects
*/
int loadcustomerinformation(customer* myArray[], int size){
    //string textFileName = "customerinformation.txt";
    int currentSize = 0;
    //for loop creates new objects everything from the read in file
    ifstream textFileName;
    string line;
    textFileName.open("customerinformation.txt");

    if(textFileName.is_open())
    {
       for(int i = 0; i < size; i++)
       {
        while(getline(textFileName,line))
        {
        stringstream ss;
        ss << line;
        string item;

        getline(ss,item, ',');
        string tempName = item;

        getline(ss,item, ',');
        string tempCarBrand = item;

        getline(ss,item,',');
        string tempYear = item;

        getline(ss,item,',');
        int tempIsRented = stoi(item);

        customer *newCustomer = new customer;
        newCustomer->name = tempName;
        newCustomer->carBrand = tempCarBrand;
        newCustomer->year = tempYear;
        newCustomer->isRented = tempIsRented;
        myArray[i] = newCustomer;


        currentSize++;
        }
      }
    }
    textFileName.close();


    return currentSize;
}

void carTextFile()
{
  ifstream carFile;
  carFile.open("Cars.txt");

  if(carFile.is_open())
  {
    string line;
    string item;
    while(getline(carFile,line))
    {
      stringstream ss;
      ss << line;


      getline(ss,item,',');
      string tempCar = item;

      getline(ss,item,',');
      string tempYear = item;

      cout << tempCar << " " << tempYear << endl;
    }
  }
}
