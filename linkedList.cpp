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

//  ------------------> <--------------------  //

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
        bool flag = false;
        while (temp) {
            if (temp->value == where) {
                Node->next = temp->next;
                temp->next = Node;
                flag = true;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            cout << ">> ⚠️ Sorry! the insertion point is not Found!!" << endl;
        else
            cout << ">> Operation Sucessful!";
    }

    // Method to Delete Node
    void deleteNode(int which) {
        node* temp = head;
        bool flag = false;
        if (head->value == which) {
            head = head->next;
            flag = true;
        } else {
            while (temp->next) {
                if (temp->next->value == which) {
                    temp->next = temp->next->next;
                    flag = true;
                    break;
                }
                temp = temp->next;
            }
        }
        if (!flag)
            cout << ">> ⚠️ Node Doesn't Exist!!" << endl;
        else
            cout << ">> Operation Sucessful!";
    }

    // Change the data of Node
    void updateNode(int newValue, int prevValue) {
        node* temp = head;
        bool flag = false;
        while (temp) {
            if (temp->value == prevValue) {
                temp->value = newValue;
                cout << ">> Operation Sucessful!" << endl;
                flag = true;
                break;
            }
            temp = temp->next;
        }
        if (!temp)
            cout << ">> ⚠️ Node doesn't exist!!" << endl;
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL)
            cout << "The list is empty! Kindly fill it" << endl;
        else {
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
        appendNode(Node);
        head = Node;
    }

    // Method to Insert Node after a Node
    void insertNode(node* Node, int where) {
        node* temp = head;
        bool flag = false;
        while (temp) {
            if (temp->value == where) {
                Node->next = temp->next;
                temp->next = Node;
                flag = true;
                break;
            }
            temp = temp->next;
            if (temp == head)
                break;
        }
        if (!flag)
            cout << ">> ⚠️ Node Doesn't Exist!!" << endl;
        else
            cout << ">> Operation Sucessful!";
    }

    // Method to Delete Node
    void deleteNode(int which) {
        if (head->next == head) {
            head = NULL;
            return;
        }
        if (head->value == which)
            head = head->next;
        if (head == NULL) {
            cout << ">> Kindly fill the list, it's empty" << endl;
        } else {
            node* temp = head;
            bool flag = false;
            while (temp) {
                if (temp->next->value == which) {
                    temp->next = temp->next->next;
                    flag = true;
                    break;
                }
                temp = temp->next;
                if (temp == head)
                    break;
            }
            if (!flag)
                cout << "⚠️ Sorry! the insertion point is not Found!!" << endl;
            else
                cout << ">> Operation Sucessful!";
        }
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
            if (temp == head)
                break;
        }

        if (!flag)
            cout << ">> ⚠️ Node doesn't exist!!" << endl;
        else
            cout << ">> Operation Sucessful!";
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty! Kindly fill it";
        } else {
            node* temp = head;
            cout << " --> (" << temp->value << ") -->";
            while (temp && temp->next != head) {
                cout << " (" << temp->next->value << ") -->";
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
        } else {
            while (temp->next)  // Taking out Last-Node
                temp = temp->next;

            temp->next = Node;  // Changes at Tail
            Node->prev = temp;
            Node->next = NULL;
        }
    }

    // Inserting at Tail/ Just before the head
    void perpendNode(node* Node) {
        head->prev = Node;
        Node->next = head;
        head = Node;
    }

    // Method to Insert Node after a Node
    void insertNode(node* Node, int where) {
        node* temp = head;
        bool flag = false;
        while (true) {
            if (temp->value == where) {
                node* x = temp->next;
                temp->next = Node;
                Node->prev = temp;
                Node->next = x;
                x->prev = Node;
                flag = true;
                break;
            }
            // tempPrev = tempCurr;
            if (temp->next != NULL)
                temp = temp->next;
            else
                break;
        }
        if (!flag)
            cout << "⚠️ Sorry! the insertion point is not Found!!" << endl;
        else
            cout << ">> Operation Sucessful!";
    }

    // Method to Delete Node
    void deleteNode(int which) {
        bool flag = false;
        if (!head) {
            cout << ">> Empty List, Fill it up Buddy..." << endl;
            return;
        } else if (head->value == which) {
            head = (head->next != NULL) ? head->next : NULL;
            flag = true;
        } else {
            node* temp = head;
            while (temp) {
                if (temp->next->value == which) {
                    temp->next = (temp->next->next != NULL) ? temp->next->next : NULL;
                    flag = true;
                }
                temp = temp->next;
            }
        }
    }

    // Change the data of Node
    void
    updateNode(int newValue, int prevValue) {
        node* temp = head;
        bool flag = false;

        while (temp) {
            if (temp->value == prevValue) {
                temp->value = newValue;
                flag = true;
                break;
            }
            temp = temp->next;
        }
        if (!flag)
            cout << ">> ⚠️ Node doesn't exist!!" << endl;
        else
            cout << ">> Operation Sucessful!!" << endl;
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL) {
            cout << ">> The list is empty! Kindly fill it" << endl;
        } else {
            cout << "(" << head->value << ") --> ";
            if (head->next != NULL) {
                node* temp = head->next;
                while (temp->next) {
                    cout << "<-- (" << temp->value << ") --> ";
                    temp = temp->next;
                }
                cout << "<-- (" << temp->value << ") ";
            }
        }
    }
};  // end of Class

//  ------------------> <--------------------  //

class DoubleCircularList : public LinkedList {
   public:
    node* head;             // Header of the list
    DoubleCircularList() {  // Constructor
        head = NULL;
    }

    // Method to append node, takes a node pointer
    void appendNode(node* Node) {
        if (head == NULL) {
            Node->next = Node;
            Node->prev = Node;
            head = Node;
        } else {
            node* temp = head;
            while (temp->next != head) {  // Taking out Last-Node
                temp = temp->next;
                if (temp == head)
                    break;
            }
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
        node* temp = head;
        bool flag = false;

        while (temp) {
            if (temp->value == where) {
                Node->next = temp->next;  // Changes After
                temp->next->prev = Node;

                temp->next = Node;  // Changes Before
                Node->prev = temp;
                flag = true;
                break;
            }
            temp = temp->next;
            if (temp == head)
                break;
        }

        if (!flag)
            cout << "⚠️ Sorry! the insertion point is not Found!!" << endl;
        else
            cout << ">> Operation Sucessful!" << endl;
    }

    // Method to Delete Node
    void deleteNode(int which) {
        bool flag = false;
        if (!head) {
            cout << ">> Empty List, Fill it up Buddy..." << endl;
            return;
        } else if (head->value == which && head->next == head) {
            head = (head->next != NULL) ? head->next : NULL;
            flag = true;
        } else {
            node* temp = head;
            while (temp) {
                if (temp->next->value == which) {
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                    flag = true;
                    break;
                }
                temp = temp->next;
                if (temp == head)
                    break;
            }
        }
        if (!flag)
            cout << "⚠️ Sorry! the Deletion point is not Found!!" << endl;
        else
            cout << ">> Operation Sucessful!" << endl;
    }

    // Change the data of Node
    void updateNode(int newValue, int prevValue) {
        node* temp = head;
        bool flag = false;

        while (temp) {
            if (temp->value == prevValue) {
                temp->value = newValue;
                flag = true;
                break;
            }
            temp = temp->next;
            if (temp == head)
                break;
        }
        if (!flag)
            cout << ">> ⚠️ Node doesn't exist!!" << endl;
        else
            cout << ">> Operation Sucessful!!" << endl;
    }

    // Method to Display whole List
    void displayList() {
        if (head == NULL) {
            cout << ">> The list is empty! Kindly fill it" << endl;
        } else {
            node* temp = head;
            while (temp) {
                cout << "<--( " << temp->value << " )-->";
                temp = temp->next;
                if (temp == head)
                    break;
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
         << "2. Single-Circular List" << endl
         << "3. Double-Linked List" << endl
         << "4. Double-Circular List" << endl
         << ">> ";
    cin >> choice;

    if (choice == 0) {
        cout << "\nThanks for being Here!";
    } else if (choice == 1) {
        cout << "\nLet's build Singly-Linked List: " << endl;
        SingleLinkedList l;
        list = &l;
    } else if (choice == 2) {
        cout << "\nLet's build Single-Circular List: ";
        CircularLinkedList l;
        list = &l;
    } else if (choice == 3) {
        cout << "\nLet's build Double-Linked List: ";
        DoubleLinkedList l;
        list = &l;
    } else if (choice == 4) {
        cout << "\nLet's build Double-Circular List: ";
        DoubleCircularList l;
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
            cout << "Thanks for being here" << endl;
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