// Demonstration of std::list
// Inserts served customers into a list
#include <iostream>
#include <fstream>
#include <list>
#include <ctime>
using namespace std;

const int SZ = 200;  // holds size of array of names from file

int main() {
    // first read names file and store in an array
    ifstream fin("names.txt");
    string names[SZ];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    // create a list of customers served
    list<string> customers;

    // insert a random number (5-12) of random customer names into the list
    srand(time(0));
    int num = rand() % 12 + 5;
    for (int i = 0; i < num; i++)
        customers.push_back( names[rand() % SZ] );

    cout << "Customers served:\n";
    for (string nm : customers)
        cout << "\t" << nm << endl;

    // create a copy to leave the original list unchanged (copy method #1)
    list<string> customers_sorted(customers);
    customers_sorted.sort();

    // output the sorted list
    cout << "Customers served sorted:\n";
    for (string nm : customers_sorted)
        cout << "\t" << nm << endl;

    // create another copy to manipulate (copy method #2)
    list<string> customers_pending;
    customers_pending = customers;
    list<string> customers_processed;
    // process first three customers
    for (int i = 0; i < 3; i++) {
        customers_processed.push_back(customers_pending.front());
        customers_pending.pop_front();
    }
    
    // output the pending and processed lists (two print methods)
    cout << "\nCustomers processed:\n";
    for (string nm : customers_processed)
        cout << "\t" << nm << endl;
    cout << "Customers pending:\n";
    for (auto it = customers_pending.begin(); it != customers_pending.end(); it++)
        cout << "\t" << *it << endl;

    return 0;
}

/*
Common <list> member functions:
.back()              // returns a reference to the last element in the container
.begin()             // returns an iterator to the first element
.clear()             // removes all elements from the list
.emplace(it, args)   // emplaces, but requires an iterator pointing to an existing element
.emplace_back(args)  // emplaces to the back
.emplace_front(args) // emplaces to the front
.empty()             // returns true if empty; false otherwise
.erase(it)           // erases the element pointed to by the iterator
.front()             // returns a reference to the first element in the container
.insert(it, value)   // inserts value before the element at the specified position
.pop_back()          // removes the last element
.pop_front()         // removes the first element
.push_back(value)    // adds an element to the end
.push_front(value)   // adds an element to the front
.remove(value)       // removes all elements equal to value
.reverse()           // reverses the order of the elements
.sort()              // sorts the elements
.size()              // returns the number of elements
.unique()            // deduplicates the list
*/