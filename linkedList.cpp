#include <iostream>
using namespace std;

class node {  // Node for any type of linked-list
   public:
    int value;   // DATA in the node
    node* next;  // Next node pointer
    node* prev;  // Previous node pointer

    node(int value) {  // Default Instructor
        this->value = value;
        this->next = NULL;
        prev = NULL;
    }
};

class LinkedList {  // Hata k dekh lo...
   public:
    virtual void appendNode(node* n){};
    virtual void deleteNode(int num){};
    virtual void perpendNode(node* n){};
    virtual void insertNode(node* Node, int where){};
    virtual void updateNode(int newValue, int prevValue){};
    virtual void displayList(){};
};

//  ------------------> <--------------------  //

class SingleLinkedList : public LinkedList {
   public:
    node* head;           // Header of the list
    SingleLinkedList() {  // Constructor
        head = NULL;
    }

    // Method to append node, takes a node pointer
    void appendNode(node* Node) {
        node* temp;
        if (head == NULL) {
            head = Node;
        } else {
            temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = Node;
        }
    }

    void perpendNode(node* Node) {
        Node->next = head;
        head = Node;
    }

    // Method to Insert Node after a Node
    void insertNode(node* Node, int where) {
        node* temp = head;
        bool flag = true;
        while (temp) {
            if (temp->value == where) {
                Node->next = temp->next;
                temp->next = Node;
                flag = false;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            cout << "⚠️ Sorry! the insertion point is not Found!!" << endl;
    }

    // Method to Delete Node
    void deleteNode(int which) {
        node* temp = head;
        bool flag = false;
        if (head->value == which) {
            head = head->next;
            flag = true;
            // previous head still exist :(
        } else {
            while (temp->next) {
                if (temp->next->value == which) {
                    temp->next = temp->next->next;
                    flag = true;
                    break;
                    // deleted node still exist :(
                }
                temp = temp->next;
            }
        }
        if (!flag)
            cout << "⚠️ Node Doesn't Exist!!" << endl;
    }

    // Change the data of Node
    void updateNode(int newValue, int prevValue) {
        node* temp = head;
        bool flag = false;
        while (temp) {
            if (temp->value == prevValue) {
                temp->value = newValue;
                cout << "Change has made sucessfully! " << endl;
                flag = true;
                break;
            }
            temp = temp->next;
        }
        if (!temp) {
            cout << "⚠️ Node doesn't exist!!" << endl;
        }
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty! Kindly fill it";
            cout << "haha";
        } else {
            node* temp = head;
            while (temp) {
                cout << "(" << temp->value << ")"
                     << "--->";
                temp = temp->next;
            }
        }
        cout << endl;
    }

};  // end of Class

//  ------------------> <--------------------  //

class CircularLinkedList : public LinkedList {
   public:
    node* head;             // Header of the list
    CircularLinkedList() {  // Constructor
        head = NULL;
    }

    // Method to append node, takes a node pointer
    void appendNode(node* Node) {
        node* temp;
        if (head == NULL) {
            head = Node;
            head->next = head;
        } else {
            temp = head;
            while (temp->next && temp->next != head) {
                temp = temp->next;
            }
            temp->next = Node;
            Node->next = head;
        }
    }

    // Inserting at Tail/ Just before the head
    void perpendNode(node* Node) {
        if (head == NULL) {
            head = Node;
            head->next = head;
        } else {
            node* temp = head;
            while (temp && temp->next != head)
                temp = temp->next;
            temp->next = Node;
            Node->next = head;
            head = Node;
        }
    }

    // Method to Insert Node after a Node
    void insertNode(node* Node, int where) {
        node* tempCurr = head->next;
        node* tempPrev = head;
        bool flag = false;
        while (tempCurr) {
            if (tempPrev->value == where) {
                tempPrev->next = Node;
                Node->next = tempCurr;
                flag = true;
            }
            tempPrev = tempCurr;
            tempCurr = tempCurr->next;
            if (tempPrev == head)
                break;
        }
        if (!flag)
            cout << "⚠️ Sorry! the insertion point is not Found!!" << endl;
    }

    // Method to Delete Node
    void deleteNode(int which) {
        if (head == NULL) {
            cout << "Kindly fill the list, it's empty" << endl;
        } else {
            node* tempCurr = head->next;
            node* tempPrev = head;
            bool flag = false;

            if (head->value == which) {
                if (head->next == head)
                    head = NULL;
                flag = true;
                // previous head still exist :(
            }
            while (tempCurr) {
                if (tempCurr->value == which) {
                    tempPrev->next = tempCurr->next;
                    // head = tempPrev->next;
                    flag = true;
                    break;
                    // deleted node still exist :(
                }
                tempPrev = tempCurr;
                tempCurr = tempCurr->next;
                if (tempPrev == head) {
                    cout << "^^^^" << endl;
                    break;
                }
            }

            if (!flag)
                cout << "⚠️ Node Doesn't Exist!!" << endl;
        }
    }

    // Change the data of Node
    void updateNode(int newValue, int prevValue) {
        node* temp = head;
        bool flag = false;

        if (head->value == prevValue) {
            cout << "head Value: " << head->value;
            head->value = newValue;
            flag = true;
        } else {
            while (temp) {
                temp = temp->next;
                cout << "here I'm";
                if (temp->value == prevValue && temp != head) {
                    temp->value = newValue;
                    cout << "Change has made sucessfully! " << endl;
                    flag = true;
                    break;
                }
                if (temp->next == head)
                    break;
            }
        }
        if (!flag) {
            cout << "⚠️ Node doesn't exist!!" << endl;
        }
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty! Kindly fill it";
        } else {
            node* temp = head;
            cout << " <-- (" << temp->value << ") --> ";
            while (temp && temp->next != head) {
                cout << " (" << temp->next->value << ") --> ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

};  // end of Class

//  ------------------> <--------------------  //

class DoubleLinkedList : public LinkedList {
   public:
    node* head;           // Header of the list
    DoubleLinkedList() {  // Constructor
        head = NULL;
    }

    // Method to append node, takes a node pointer
    void appendNode(node* Node) {
        node* temp = head;
        if (head == NULL) {
            head = Node;
            head->next = head;
            head->prev = head;
        } else {
            while (temp->next && temp->next != head)  // Taking out Last-Node
                temp = temp->next;

            temp->next = Node;  // Changes at Tail
            Node->prev = temp;
            Node->next = head;  // Changes at Head
            head->prev = Node;
        }
    }

    // Inserting at Tail/ Just before the head
    void perpendNode(node* Node) {
        appendNode(Node);
        head = Node;
    }

    // Method to Insert Node after a Node
    void insertNode(node* Node, int where) {
        node* tempCurr = head->next;
        node* tempPrev = head;
        bool flag = false;
        while (tempCurr) {
            if (tempPrev->value == where) {
                tempPrev->next = Node;
                Node->prev = tempPrev;
                Node->next = tempCurr;
                tempCurr->prev = Node;
                flag = true;
                break;
            }
            tempPrev = tempCurr;
            tempCurr = tempCurr->next;
            if (tempPrev == head)
                break;
        }
        if (!flag)
            cout << "⚠️ Sorry! the insertion point is not Found!!" << endl;
    }

    // Method to Delete Node
    void deleteNode(int which) {
        cout << (head->prev == head) << endl;
        node* tempCurr = head->next;
        node* tempPrev = head;
        bool flag = false;

        if (head == NULL) {
            cout << "Kindly fill the list, it's empty" << endl;
        } else if (head->value == which) {
            if (head->next != head) {
                node* p = head->prev;
                head = head->next;
                head->prev = p;
                flag = true;
            } else
                head = NULL;
        } else
            while (tempCurr) {
                if (tempCurr->value == which) {
                    tempPrev->next = tempCurr->next;
                    tempCurr->next->prev = tempPrev;
                    flag = true;
                    cout << "Deleted Successfully" << endl;
                    break;
                    // deleted node still exist :(
                }
                tempPrev = tempCurr;  // Traversing
                tempCurr = tempCurr->next;
                if (tempPrev == head) {
                    cout << "^^^^" << endl;
                    break;
                }
            }

        if (!flag)
            cout << "⚠️ Node Doesn't Exist!!" << endl;
        cout << "Exiting..." << endl;
    }

    // Change the data of Node
    void
    updateNode(int newValue, int prevValue) {
        node* temp = head;
        bool flag = false;

        if (head->value == prevValue) {
            head->value = newValue;
            flag = true;
        } else {
            while (temp) {
                temp = temp->next;
                if (temp->value == prevValue && temp != head) {
                    temp->value = newValue;
                    cout << "Change has made sucessfully! " << endl;
                    flag = true;
                    break;
                }
                if (temp->next == head)
                    break;
            }
        }
        if (!flag) {
            cout << "⚠️ Node doesn't exist!!" << endl;
        }
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty! Kindly fill it";
        } else {
            node* temp = head;
            cout << " <-- (" << temp->value << ") --> ";
            while (temp && temp->next != head) {
                cout << "<--- (" << temp->next->value << ") --> ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};  // end of Class

int main() {
    LinkedList* list;
    int choice;
    cout << "Welcome to LINKED-LISTS: " << endl
         << "0. Exit" << endl
         << "1. Singly-Linked List" << endl
         << "2. Circular-Linked List" << endl
         << "3. Double-Linked List" << endl
         << ">> ";
    cin >> choice;

    if (choice == 0) {
        cout << "\nThanks for being Here!";
    } else if (choice == 1) {
        cout << "\nLet's build Singly-Linked List: " << endl;
        SingleLinkedList l;
        list = &l;
    } else if (choice == 2) {
        cout << "\nLet's build Circular-Linked List: ";
        CircularLinkedList l;
        list = &l;
    } else if (choice == 3) {
        cout << "\nLet's build Double-Linked List: ";
        DoubleLinkedList l;
        list = &l;
    }

    while (choice != 0) {
        int option, num;
        cout << "\nKindly choose suitable option: " << endl
             << "0. Exit            "
             << "1. Append Node " << endl
             << "2. Perpend Node    "
             << "3. Insert Node " << endl
             << "4. Update Node     "
             << "5. Delete Node " << endl
             << "6. Display List    "
             << ">>  ";
        cin >> option;
        if (option == 0) {
            cout << "Thanks for being here";
            list->displayList();
            break;

        } else if (option == 1) {
            cout << "Enter the Node-Value to append: ";
            cin >> num;
            list->appendNode(new node(num));

        } else if (option == 2) {
            cout << "Enter the Node-Value to perpend: ";
            cin >> num;
            list->perpendNode(new node(num));

        } else if (option == 3) {
            cout << "Enter the Node-Value to insert: ";
            cin >> num;
            int where;
            cout << "Where you want to insert: ";
            cin >> where;
            list->insertNode(new node(num), where);

        } else if (option == 4) {
            cout << "Enter the New Value of Node: ";
            cin >> num;
            int which;
            cout << "Enter Previous Value of Node: ";
            cin >> which;
            list->updateNode(num, which);

        } else if (option == 5) {
            cout << "Enter the Node Value to Delete: ";
            cin >> num;
            list->deleteNode(num);
        } else if (option == 6) {
            cout << endl;
            list->displayList();
        } else
            cout << "Valid Input please!!" << endl;
    }

    return 0;
}