/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

// FINAL VERISON

void reorganize(Node** head_ref) {
    Node* current = (*head_ref); // current points to the node, which head points to.
    Node* last =  current;
    while (last->next != NULL) {last = last->next;}
   // cout << "last: " << last->printSNode() << endl;
    while (current != last) { // /= while node, which current points to, next pointer does not point to the last node in the DLL. Note: the last node current will end up pointing to is the node before the last node.
        //cout << "\ncurrent at: " << current->printSNode() << endl; 
        //cout << "Orignal List: ";
        //print((*head_ref));
        cout <<endl;
        Node* current2 = current->next; // created a pointer named current2, current2 will point to the node that if after the node, which current points to. Note: current2 is declared inside the while loop, so it will be declared for each iteration with a potentially new value
        
        while (current2 != NULL) { // /= while node, which current2 points to, next pointer does not point to NULL
            if (current->priority >= current2->priority) {
                if (current->timeD > current2->timeD && current->priority == current2->priority || current->priority > current2->priority ) { // /= if node, which current points to, printSNode() variable is greater than the node, which current2 points to, printSNode() variable
                    //cout << current->printSNode() << " > " << current2->printSNode() << endl;
                    // Store the prev and next pointer of the corresponding nodes:
                    if (current->next == current2) { // /= if the two nodes are beside each other:
                        //cout << "Next To Each Other" << endl;
                        if (current->prev == NULL) {
                            //cout << "current is the head" << endl;
                            Node* current_next = current->next;
                            
                            Node* current2_next = current2->next;
                            Node* current2_prev = current2->prev;
                            
                            // current2 is not the last node:
                            if (current2->next != NULL) {
                                current2->next->prev = current;
                            
                                //For Surrounding Nodes:
                                current2->next->prev = current;
                                //
                            
                                current->next = current2_next;
                                current->prev = current2;
                            
                                current2->next = current;
                                current2->prev = NULL;
                                
                                (*head_ref) = current2;
                            }
                            
                            // current2 is the last node: // This would only be plausible if there were 2 nodes in the last
                            else {
                                //cout << "current2 is the last node" << endl;
                                current2->next = current;
                                current2->prev = NULL;
                                
                                current->next = NULL;
                                current->prev = current2;
                                
                                (*head_ref) = current2;
                                last = current; // last points to the new last node
                            }
                            
                            Node* temp = current;
                            current = current2;
                            current2 = temp;
                            //cout << "Node That Contains: " << current->printSNode() << " Swapped Positions WIth Node That Contains: " << current2->printSNode() << endl;
                            //cout << "Altered List: "; print((*head_ref)); //cout << endl;
                            //reverseP((*head_ref));
                            //cout << endl;
                            current2 = current2->next;
    
                            //(*head_ref) = current; // head now points to the new first node
    
                            continue;
                        }
                        Node* current_next = current->next;
                        Node* current_prev = current->prev;
                        
                        Node* current2_next = current2->next;
                        Node* current2_prev = current2->prev;
                        
                        if (current2->next != NULL) { // default
                            current->next = current2->next;
                            current->prev = current2;
                            current_prev->next = current2;
                        
                            current2_next->prev = current;
                            current2->next = current;
                            current2->prev = current_prev;
                        }
                        
                        else { // current2 is the last node
                            current2->next = current;
                            current2->prev = current->prev;
                            
                            current_prev->next = current2;
                            current->prev = current2;
                            current->next = NULL;
                            
                            last = current; // now last points to the new last node
                        }
                        Node* temp = current;
                        current = current2;
                        current2 = temp;
                    
                        //cout << "Node That Contains: " << current->printSNode() << " Swapped Positions WIth Node That Contains: " << current2->printSNode() << endl;
                        //cout << "Altered List: "; print((*head_ref)); //cout << endl;
                        //reverseP((*head_ref)); cout << endl; cout << endl;
                        current2 = current2->next;
                        continue;
                    }
                    if (current->next == current2->prev) { // a node is in between them
                        //cout << "In Between " << endl;
                        if (current->prev == NULL) {
                            //cout << "current is the head" << endl;
                            Node* current_next = current->next;
                
                            Node* current2_next = current2->next;
                            Node* current2_prev = current2->prev;
                            
                            // default/ current2 is not the last node:
                            if (current2->next != NULL) {
                                current2->next->prev = current;
                                current->next = current2_next;
                                current->prev = current2;
                                current2->next = current;
                                current2->prev = NULL;
                            }
                            // end
                            
                            //current2 is the last node
                            else {
                                current->next->next = current;
                                current->next->prev = current2;
                                current2->next = current2_prev;
                                current2->prev = NULL;
                                current->next = NULL;
                                
                                last = current;
                            }                            
                            // end
                            
                            Node* temp = current;
                            current = current2;
                            current2 = temp;
                            
                            (*head_ref) = current; // head now points to the new first node
    
                            //cout << "Node That Contains: " << current->printSNode() << " Swapped Positions WIth Node That Contains: " << current2->printSNode() << endl;
                            //cout << "Altered List: "; print((*head_ref)); //cout << endl;
                            //reverseP((*head_ref));
                            cout << endl;
                            current2 = current2->next;
                            continue;
                        }
                        Node* current_next = current->next;
                        Node* current_prev = current->prev;
                        Node* current2_next = current2->next;
                        Node* current2_prev = current2->prev;
                        
                        // defualt. Note: current is not the head
                        if (current2->next != NULL) {
                            current->prev->next = current2;
                       
                             // For the Node In Between:
                            current->next->next = current;
                            current->next->prev = current2;
                        
                            current2->next->prev = current;
                    
                            current->next = current2_next;
                            current->prev = current2_prev;
                        
                            current2->next = current_next;
                            current2->prev = current_prev;
                        }
                        // end
                        
                        // current2 is the last node and current is not the head.
                        else {
                            current->next->next = current;
                            current->next->prev = current2;
                            current->prev->next = current2;
                            current->next = NULL;

                            current->prev = current_next;
                            
                            current2->prev = current_prev;
                            current2->next = current2_prev; // Note current2_prev and current_next point to the same node
                            
                            last = current;
                        }
                        //end
                        //cout << "current: " << current->prev->printSNode() << " <- " << current->printSNode() << " -> " << current->next->printSNode() << endl;
                        //cout << "current2: " << current2->prev->printSNode() << " <- " << current2->printSNode() << " -> " << current2->next->printSNode() << endl; <- this would break the code if current2 pointed to the last node or current points to the last node
    
                        Node* temp = current;
                        current = current2;
                        current2 = temp;
                    
                        //cout << "Node That Contains: " << current->printSNode() << " Swapped Positions WIth Node That Contains: " << current2->printSNode() << endl;
                        //cout << "Altered List: "; print((*head_ref)); //cout << endl;
                        //reverseP((*head_ref)); */
                        cout << endl;
                        current2 = current2->next;
                        continue;
                    }
                    //else {
                        //cout << "Other" << endl;
                        //cout << "current: " << current->printSNode() << " current2: " << current2->printSNode() << endl;
                        if (current->prev == NULL) {
                            //cout << "current at head" << endl;
                            Node* current_next = current->next;
                            
                            Node* current2_next = current2->next;
                            Node* current2_prev = current2->prev;
                            
                            //default:
                            if (current2->next != NULL) {
                                //cout << " THIS IS THE BUGG " << endl;
                                current2->next->prev = current;
                                current2->prev->next = current;
                            
                                current->next->prev = current2;
                            
                                current->next = current2_next;
                                current->prev = current2_prev;
                            
                                current2->next = current_next;
                                //cout << current->prev->printSNode() << " <- " << current->printSNode() << " - > " << current->next->printSNode() << endl;
                                current2->prev = NULL;
                                
                            }
                            // end
                            
                            // current2 is the last node
                            else {
                                current_next->prev = current2;
                                current2_prev->next = current;
                                
                                current->next = NULL;
                                current->prev = current2_prev;
                                current2->prev = NULL;
                                current2->next = current_next;
                                
                                last = current;
                            }
                            //end 
                            
                            Node* temp = current;
                            current = current2;
                            current2 = temp;
                            
                            (*head_ref) = current; // head now points to the new first node
                            //cout << "Node That Contains: " << current->printSNode() << " Swapped Positions WIth Node That Contains: " << current2->printSNode() << endl;
                            //cout << "Altered List: "; print((*head_ref)); //cout << endl;
                            //reverseP((*head_ref));
                            //cout << endl;
                            
                            continue;
                        }
                        Node* current_next = current->next;
                        Node* current_prev = current->prev;
                        
                        Node* current2_next = current2->next;
                        Node* current2_prev =  current2->prev;
                        
                        //Make the nodes around current, apporiate pointer point to current2:
                        current->prev->next = current2;
                        current->next->prev = current2;
                        
                        //Same for current2, except there's a case where current2 can be equal to the last node.
                        if (current2->next == NULL) {
                            //cout << "CASE" << endl;
                            current2->prev->next = current;
                        }
                        else {
                            current2->prev->next = current;
                            current2->next->prev = current;
                        }
                        
                        //Swap the pointers variabels of the nodes:
                        current->prev = current2_prev;
                        current->next = current2_next;
                        
                        current2->prev = current_prev;
                        current2->next = current_next;
                    //}    
                    // Since nodes swapped position, swap pointers.
                    //cout << current->prev->printSNode() << " of current:" << current->printSNode() << " next:" << current->next->printSNode() << endl;
                    //cout << current2->prev->printSNode() << " of current2:" << current2->printSNode() << " next:" << current2->next->printSNode() << endl;
    
                    Node* temp = current;
                    current = current2;
                    current2 = temp;
            
                    //cout << "Node That Contains: " << current->printSNode() << " Swapped Positions WIth Node That Contains: " << current2->printSNode() << endl;
                    //cout << "Altered List: "; print((*head_ref)); //cout << endl;
                    //reverseP((*head_ref));
                    cout << endl;
                }
            }    
            //cout << current->next << endl;
            current2 = current2->next;
            //cout << "current 2 = " << current2->printSNode() << endl;
        }
    
        //cout << "Altered List: "; print((*head_ref)); cout << endl;
        //cout << "Moving Onto The Next Node:" << current->next; 
        current = current->next;
        //cout << "current now at: " << current->printSNode() << endl;
    }
    //cout << "End Of Loop" << endl;
}
