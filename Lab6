/
Documentation Citations & References:
1. std::list Overview: https://en.cppreference.com/w/cpp/container/list
2. std::list::push_back: https://en.cppreference.com/w/cpp/container/list/push_back
3. std::list::erase: https://en.cppreference.com/w/cpp/container/list/erase
4. std::list::const_iterator:https://en.cppreference.com/w/cpp/container/list/begin
/

#include <iostream>
#include <string>
#include <list>

// Class Definition: Person //
class Person {
private:
    std::string name_;
    std::string job_title_;
    std::string department_;

public:
    // Default Constructor
    Person() {
        this->name_ = "";
        this->job_title_ = "";
        this->department_ = "";
    }

    // Parameterized Constructor
    Person(const std::string& initial_name, 
           const std::string& initial_job_title, 
           const std::string& initial_department) {
        this->name_ = initial_name;
        this->job_title_ = initial_job_title;
        this->department_ = initial_department;
    }

    // Destructor
    ~Person() {
        // Explicit cleanup hook on object destruction
    }

    // Getter Methods (Marked const for Const-Correctness)
    std::string Get_name() const {
        return this->name_;
    }

    std::string Get_jobtitle() const {
        return this->job_title_;
    }

    std::string Get_department() const {
        return this->department_;
    }

    // Print method to display all attributes of the person
    void print_out() const {
        std::cout << "Name:       " << this->name_ << "\n";
        std::cout << "Job Title:  " << this->job_title_ << "\n";
        std::cout << "Department: " << this->department_ << "\n";
        std::cout << "----------------------------------------\n";
    }
};

// Helper Functions for Directory Operations//

/**
 * Print all objects currently stored inside the std::list container.
 */
void PrintAllPersons(const std::list<Person>& person_list) {
    std::cout << "\n========================================\n";
    std::cout << "       CURRENT PERSON DIRECTORY         \n";
    std::cout << "========================================\n";

    if (person_list.empty() == true) {
        std::cout << "Directory is currently empty.\n";
        return;
    }

    // Citation: Iterator traversal pattern from https://en.cppreference.com/w/cpp/container/list/begin
    std::list<Person>::const_iterator iterator = person_list.begin();
    while (iterator != person_list.end()) {
        iterator->print_out();
        // Explicit iterator advancement
        std::advance(iterator, 1);
    }
}

/**
 * Search the list for any object containing an attribute matching the query term.
 */
void SearchPerson(const std::list<Person>& person_list, const std::string& query) {
    std::cout << "\n>>> Searching directory for query term: \"" << query << "\"\n";
    bool match_found = false;

    // Citation: Iterator traversal pattern from https://en.cppreference.com/w/cpp/container/list/begin
    std::list<Person>::const_iterator iterator = person_list.begin();
    while (iterator != person_list.end()) {
        if (iterator->Get_name() == query || 
            iterator->Get_jobtitle() == query || 
            iterator->Get_department() == query) {
            
            std::cout << "[MATCH FOUND]:\n";
            iterator->print_out();
            match_found = true;
        }
        std::advance(iterator, 1);
    }

    if (match_found == false) {
        std::cout << "No person matching term \"" << query << "\" was found in the directory.\n";
    }
}

/**
 * Remove a Person object from the std::list by matching the name attribute.
 */
void RemovePersonByName(std::list<Person>& person_list, const std::string& target_name) {
    std::cout << "\n>>> Attempting to remove person with name: \"" << target_name << "\"\n";
    bool removal_occurred = false;

    std::list<Person>::iterator iterator = person_list.begin();
    while (iterator != person_list.end()) {
        if (iterator->Get_name() == target_name) {
            // Citation: std::list::erase returns an iterator to the next valid element
            // Reference: https://en.cppreference.com/w/cpp/container/list/erase
            iterator = person_list.erase(iterator);
            removal_occurred = true;
            std::cout << "Successfully removed \"" << target_name << "\" from the list.\n";
        } else {
            std::advance(iterator, 1);
        }
    }

    if (removal_occurred == false) {
        std::cout << "Remove failed: \"" << target_name << "\" was not found in directory.\n";
    }
}

// Main Function//
int main() {
    // Instantiating the STL List container
    // Citation: https://en.cppreference.com/w/cpp/container/list
    std::list<Person> directory;

    // Populating list with 5 distinct Person objects using push_back
    // Citation: https://en.cppreference.com/w/cpp/container/list/push_back
    directory.push_back(Person("Samantha Diaz", "Systems Engineer", "Information Technology"));
    directory.push_back(Person("Alex Hormozi", "Managing Director", "Acquisitions"));
    directory.push_back(Person("Leila Hormozi", "Chief Executive Officer", "Operations"));
    directory.push_back(Person("Emma Grede", "Brand Strategist", "Marketing"));
    directory.push_back(Person("David Malan", "Senior Lecturer", "Computer Science"));

    // Step 1: Print Initial State
    PrintAllPersons(directory);

    // Step 2: Test Search Functionality (Exact matches & non-existent query)
    SearchPerson(directory, "Systems Engineer");
    SearchPerson(directory, "Emma Grede");
    SearchPerson(directory, "Finance");

    // Step 3: Test Removal Functionality
    RemovePersonByName(directory, "Alex Hormozi");

    // Step 4: Verify Directory State Post-Removal
    PrintAllPersons(directory);

    return 0;
}
