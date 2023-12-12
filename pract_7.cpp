#include <iostream>
#include <string>
using namespace std;

// Node structure to hold student information
struct Node {
    int prn;
    string name;
    Node* next;
};

class PinnacleClub {
private:
    Node* president; // Pointer to president node
    Node* secretary; // Pointer to secretary node

public:
    PinnacleClub() {
        president = nullptr;
        secretary = nullptr;
    }

    // Function to add a member at the end of the list
    void addMember(int prn, string name) {
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (president == nullptr) {
            president = newNode;
            secretary = newNode;
        } else {
            secretary->next = newNode;
            secretary = newNode;
        }
    }

    // Function to delete a member by PRN
    void deleteMember(int prn) {
        Node* current = president;
        Node* prev = nullptr;

        while (current != nullptr && current->prn != prn) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        if (current == president) {
            president = president->next;
        } else {
            prev->next = current->next;
        }

        if (current == secretary) {
            secretary = prev;
        }

        delete current;
        cout << "Member with PRN " << prn << " deleted successfully." << endl;
    }

    // Function to compute total number of members
    int totalMembers() {
        int count = 0;
        Node* current = president;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    // Function to display all members
    void displayMembers() {
        Node* current = president;

        cout << "Members of Pinnacle Club:" << endl;
        while (current != nullptr) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Function to concatenate two linked lists
    void concatenateLists(PinnacleClub& otherClub) {
        if (president == nullptr) {
            president = otherClub.president;
        } else {
            secretary->next = otherClub.president;
            secretary = otherClub.secretary;
        }
    }
};

int main() {
    PinnacleClub club1, club2;

    // Adding members to club1
    club1.addMember(101, "John");
    club1.addMember(102, "Alice");
    club1.addMember(103, "Bob");

    // Adding members to club2
    club2.addMember(201, "Emma");
    club2.addMember(202, "Mike");

    // Displaying members of each club
    cout << "Club 1:" << endl;
    club1.displayMembers();

    cout << "\nClub 2:" << endl;
    club2.displayMembers();

    // Concatenating two clubs
    club1.concatenateLists(club2);

    // Displaying concatenated list
    cout << "\nConcatenated List:" << endl;
    club1.displayMembers();

    return 0;
}
