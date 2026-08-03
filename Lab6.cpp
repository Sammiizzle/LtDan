// Lab 6 - Person List using STL
// (Citations: used cppreference.com for list documentation)

#include <iostream>
#include <string>
#include <list>
using namespace std;
// CITATION: Used cppreference.com to review std::list functions.
// CITATION: Used cplusplus.com for iterator erase() examples.

// Simple Person class
class Person {
private:
    string name;
    string jobTitle;
    string department;
public:
    
// Constructor
    Person(string n, string jt, string dept) {
        name = n;
        jobTitle = jt;
        department = dept;
    }
    
// Destructor (not doing anything special)
    ~Person() {}
    // Getters
    string Get_name() const { return name; }
    string Get_jobtitle() const { return jobTitle; }
    string Get_department() const { return department; }
    // Print everything abt the person
    void print_out() const {
        cout << "Name: " << name << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << "Department: " << department << endl;
        cout << "-------------------------" << endl;
    }
};
// Add a new person to the list (wraps emplace_back so the list ops are all in one place)
void AddPerson(list<Person>& people, string n, string jt, string dept) {
    people.emplace_back(n, jt, dept);
}
// Print all ppl in the list
void PrintAllPersons(const list<Person>& people) {
    for (const auto& p : people) {
        p.print_out();
    }
}

// Search for a person by ANY attribute
void SearchPerson(const list<Person>& people, const string& key) {
    bool found = false;
    for (const auto& p : people) {
        if (p.Get_name() == key ||
            p.Get_jobtitle() == key ||
            p.Get_department() == key) {
            cout << "Match found:" << endl;
            p.print_out();
            found = true;
        }
    }
    if (!found) {
        cout << "No match found for: " << key << endl;
    }
}
// Remove person by name
void RemovePersonByName(list<Person>& people, const string& name) {
    for (auto it = people.begin(); it != people.end(); ++it) {
        if (it->Get_name() == name) {
            people.erase(it);
            cout << "Removed: " << name << endl;
            return;
        }
    }
    cout << "Person not found: " << name << endl;
}
int main() {
    list<Person> people;
    // Adding some people (just hardcoding them, now going through AddPerson)
    AddPerson(people, "Samantha", "Analyst", "IT");
    AddPerson(people, "Owen", "Engineer", "Mechanical");
    AddPerson(people, "Dan", "Engineer", "Electrical");
    AddPerson(people, "Anna", "Designer", "Marketing");
    AddPerson(people, "Emma", "Technician", "Support");
    cout << "All People:" << endl;
    PrintAllPersons(people);
    cout << "\nSearching for 'Designer':" << endl;
    SearchPerson(people, "Designer");
    cout << "\nRemoving 'Charlie':" << endl;
    RemovePersonByName(people, "Charlie");
    cout << "\nAll People After Removal:" << endl;
    PrintAllPersons(people);
    return 0;
}
