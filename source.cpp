#include <iostream>
#include <string>
#include <list>
using namespace std;

class Hash
{
private: 

    int BUCKET;     // # of buckets

    list<int> *table;   // Ptr to an array containing buckets

public: 
    Hash(int V);    // constructor

    void insertItem(int x); // inserts a key into hash table

    void deleteItem(int key);   // deletes a key from hash table

    int hashFunction(int x)     //hash function to map values to key
    {
        return (x % BUCKET);
    }

    void displayHash();

};


Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}


void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}


void Hash::deleteItem(int key)
{
    int index = hashFunction(key);  // gets the hash index of key

    // find the key in (index)th list
    list <int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            break;
        }
    }

    if (i != table[index].end())    // if key is found in the hash table
    {
        table[index].erase(i);
    }
}


void Hash::displayHash() //function to display hash table
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}


int main()
{

    int a[] = {15, 11, 27, 8, 12};  //array that contains keys to be mapped
    int n = sizeof(a)/sizeof(a[0]);

    Hash h(7);  // insert the keys into the hash table
                // 7 is count of buckets in the hash table

    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

        h.deleteItem(12);

        h.displayHash();

        return 0;
}