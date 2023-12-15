/******************************************************************************

TIME ORGANIZER: FINAL VERSION 

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        string label;
        string timeS;
        double timeD;
        int priority; // 12:00 AM - 12:59 AM = 0, AM = 1, 12:00 PM - 12:59 PM = 2, PM = 3
        string notes;
        
        Node* prev;
        Node* next;
        
        Node () {}
        
        Node (string name) {
            timeS = name;
        }
        
        void printNode();
        string printSNode();
        void setPriority(); // Could use the timeS variable, instead of taking in a parameter
};

void Node:: printNode() {
    string event;
    if (priority <= 1) {event = "AM";}
    else {event = "PM";} // NEED THIS IF USER DECIDEDS TO CHOOSE TIME, but if we figure out priority from with one line function this line of code is not needed.
    
    cout << timeS << " " << event << ", ";
}

void Node:: setPriority() { // Bug If User Inputs Invalid Format. 
    int pos;
    for (int i = 0; i < timeS.length(); i++) {
        if (timeS.substr(i,1) == " ") { //  Could also use: if (line.at(i) == ' ') { // when comparing char use ' ' not " "
            pos = i;    
        }
    }
    string event = timeS.substr(pos+1);
    
    cout << "Event: " << event << endl;
    
    if (event == "AM") {
        cout << "Response: AM IS MORNING" << endl;
        priority = 0;
    }
    
    else {
        cout << "Response: PM IS AFTERNOON" << endl;
        priority = 1;
    }
    return;
}

string Node:: printSNode() {
    string event;
    if (priority == 0) {
        event = "AM";
    }
    else {
        event =  "PM";
    }
    string timeSP = timeS + " " + event;
    return timeSP;
}

void print(Node* n) {
    cout << endl;
    while (n != NULL) {
        //string a = (n->priority <= 1) ? "AM" : "PM";
        cout << n->timeS << ": " << endl;
        cout << n->notes << endl;
        cout << endl;
        //n->printNode();
        //cout << " ";
        n = n->next;
    }
    cout << "End Of Notes" << endl;
    cout << endl;
} 

void printT(Node* n) {
    while (n != NULL) {
        cout << n->timeS << ", ";
        n = n->next;
    }
    cout << endl;
}

#include "reorganizeFINAL.h"

double convert(string time) {
    // Create a Node in here and call append function in here after making a node.
    
    //cout << "Time Inputted: " << time << endl;

    // Could Use Stringstream
    // Remove ":" from string and convert it to a double
    
    int pos;
    bool found = false;
    for (int i = 0; i < time.length(); i++) {
        if (time.substr(i,1) ==  ":") { // could also use: if (time.at(i) ==  ':') {
            pos = i;
            found = true;
        }
    }
    
    if (found == false) {cout << "Invalid Format" << endl;}
    string str1, str2;
    str1 = time.substr(0,pos); //str1 =  (found == true) ? time.substr(0,pos) : "NULL";
    str2 = time.substr(pos+1);
    
    //cout << str1 << str2 << endl;
    
    
    string summ = str1+str2;
    
    int sum = stoi(summ); // int sum = stoi(summ2) either of these 2 works, just wanted to show how to remove AM/PM
        
    double conversion = (double) sum;
    conversion = conversion/100;
    
    //cout << "Fully Converted: " << conversion << endl;
    return conversion;
}


void /*Node::*/ setEventFromOneLine(string line) { // Planning On Making This A Class/Object Function
    // We could set event with one line, we could set event and convert with one line
    int pos;
    for (int i = 0; i < line.length(); i++) {
        if (line.substr(i,1) == " ") { //  Could also use: if (line.at(i) == ' ') { // when comparing char use ' ' not " "
 
            pos = i;    
        }
    }
    string event = line.substr(pos+1);
    
    cout << "Event: " << event << endl;
    return;
}
void append(Node** head_ref, string name) { 
    Node* new_node = new Node(name);
    new_node->timeD = convert(name);
    
    cout << "Time Recorded In Double Form: " << new_node->timeD << endl;
    string event;
    cout << "AM OR PM: "; 
    getline(cin, event);
    cout << endl;
    
    if (event == "AM") {
        cout << "AM is Morning" << endl;
        new_node->priority = 1; // The lesser the priority value is the higher the priority the number has. Priority instance variable can either be 0 or 1
        if (new_node->timeD >= 12.00 && new_node->timeD <= 12.59) {cout << "Time within 12:00 AM - 12:59 AM " << endl; new_node->priority = 0;}
    }
    
    
    else {
        cout << "PM is Afternoon" << endl;
        new_node->priority = 3;
        if (new_node->timeD >=  12.00 && new_node->timeD <= 12.59) {cout << "Time within 12:00 PM - 12:59AM" << endl; new_node->priority = 2;}
    }
    
    // Appending Part:
    
    if ((*head_ref) == NULL) {
        (*head_ref) = new_node; // Head points to the same node new_node points to. Node that was created will be the first node
        new_node->prev = NULL;
        new_node->next = NULL;
        return;
        
    }
    
    Node* current = (*head_ref);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL;
    return;
}
// For reorganize function, when comparing two numbers if priority is greater swap, if priority is the same then make decision based on time2 variable
#include "append2.h"
int main()
{
    //Used append2, so time can be inputted in one line. Could use append function if numbers are the only thing wanted for user input
   Node* head = NULL;
    
    int answ;
    do {
        cout << "Enter 1 To Add Node" << endl;
        cout << "Enter 2 To Print Current List" << endl;
        
        cin >> answ;
        cin.ignore();
        switch(answ) {
            case 1: {
                string input;
                cout << "Input Time: "; getline(cin,input); cout << endl; // this takes 2 steps
                append2(&head,input);
                reorganize(&head);
                cout << endl;
                cout << input << " Inputted Into The List" << endl;
                break;
            }
            case 2: {
                cout << "Original: " << endl;
                print(head);
                cout << endl;            
                break;
            }
            case 3: {
                cout << "Times Inputted: "; printT(head); cout << endl;
                break;
            }
            default: {
                cout << "Exiting Loop" << endl;
                break;
            }
        }
        
    } while (answ == 1 || answ == 2);
    return 0;
}

