string getEvent(string line) {
    int pos = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line.substr(i,1) == " ") {pos = i;}
    }
    string event = line.substr(pos+1); // line.substr(pos+i) returns all strings from after the space to the end of string
    return event;
}

void append2(Node** head_ref, string name) { // This append will set event with one line
    Node* new_node = new Node(name);
    new_node->timeD = convert(name);
    
    //cout << "Time Recorded In Double Form: " << new_node->timeD << endl;
    string event = getEvent(name);
    //cout << "Event: " << event << endl;
    if (event == "AM") {
        //cout << "AM is Morning" << endl;
        new_node->priority = 1; // The lesser the priority value is the higher the priority the number has. Priority instance variable can either be 0 or 1
        if (new_node->timeD >= 12.00 && new_node->timeD <= 12.59) {/*cout << "Time within 12:00 AM - 12:59 AM " << endl;*/ new_node->priority = 0;}
    }
    
    
    else {
        //cout << "PM is Afternoon" << endl;
        new_node->priority = 3;
        if (new_node->timeD >= 12.00 && new_node->timeD <= 12.59) {/*cout << "Time within 12:00 PM - 12:59 AM " << endl;*/ new_node->priority = 2;}
    }
    cout << "Notes: ";
    getline(cin, new_node->notes); // could also make this into an object function
    
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