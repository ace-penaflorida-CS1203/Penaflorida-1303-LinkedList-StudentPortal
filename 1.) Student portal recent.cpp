#include <iostream>
using namespace std;

bool loopInitializer;

struct Node {
  string sr_code;
  string student_name;
  string subject_code;
  string prof_name;
  string sched_time;
// For Nodes:
  string Value;
  Node* Next;
};


void printLinkedList(Node* element); // prototypes
void appendNode(Node** head, string value);
void searchSrCode(Node** head, int num_input, string sr_code);


int main() {
  do{

    int num_input;
    string sr_code;

    cout << "\n\nNumber of Inputs: ";
    cin >> num_input;
    system("cls");
    

    Node* head[num_input];

    for (int i = 0; i < num_input; i++) {
      head[i] = NULL; // Initialize the head of each linked list to NULL
    }

    for (int i = 0; i < num_input; i++) {
      system("cls");

      Node* student = new Node(); // initialized for every iteration to avoid the overwriting of student's info

      cout << "\n   Student " << i + 1 << " Info: \n\n";
      cout << "\tEnter SR-CODE: ";
      cin >> student->sr_code;
      appendNode(&head[i], student->sr_code); // for each iteraion, new linked list is created for each student that is stored in the head 

      cout << "\tEnter Name: ";
      cin >> student->student_name;
      appendNode(&head[i], student->student_name);

      cout << "\tEnter Subject Code: ";
      cin >> student->subject_code;
      appendNode(&head[i], student->subject_code);

      cout << "\tEnter Prof's Name: ";
      cin >> student->prof_name;
      appendNode(&head[i], student->prof_name);

      cout << "\tEnter Sched Time: ";
      cin >> student->sched_time;
      appendNode(&head[i], student->sched_time);
      cout << endl;
    }

    char nextAct;
    system("cls");
    while(true){
      cout << "\n\tChoose Next Action:\n\t 1: Search Sr-Code\n\t 2: Input Againn\n\t 3: Exit Program\n\n\n\tEnter Here: ";
      cin >> nextAct;

      if (nextAct == '1'){
        loopInitializer = false;
        system("cls");
        cout << "\tEnter SR-CODE to access student information: ";
        cin >> sr_code;
        searchSrCode(head, num_input, sr_code); // invoking this function to access through the linked list based on the sr_code
      }
        
      else if(nextAct == '2'){
        loopInitializer = true;
        system("cls");
        break;
      }

      else if(nextAct == '3'){
        system("cls");
        break;
      }

      else{
        system("cls");
        cout << "Invalid Input.\n";
      }
    }
  
}while(loopInitializer == true);

  return 0;
}



void printLinkedList(Node* element) { // function for displaying the student info
  while (element != NULL) {
    cout << "\t   " << element->Value << "\n";
    element = element->Next;
  }
}

void appendNode(Node** head, string value) { // based on the given cheat_sheet 
  Node* appendedVal, * current;
  appendedVal = new Node();
  appendedVal->Value = value;
  appendedVal->Next = NULL;

  if (*head == NULL)
    *head = appendedVal;
  else {
    current = *head;
    while (current->Next != NULL) {
      current = current->Next;
    }
    current->Next = appendedVal;
  }
}

void searchSrCode(Node** head, int num_input, string sr_code) {
  system("cls");
  for (int i = 0; i < num_input; i++) {
    if (head[i]->Value == sr_code) {
      cout << "\n\tStudent " << i + 1 << " Information:\n";
      printLinkedList(head[i]); // displays the corresponding student info depending on the user's sr_code
      return;
    }
  }
  cout << "Student not found.\n";
}
