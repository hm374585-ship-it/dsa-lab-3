#include <iostream>
#include <string>
using namespace std;

struct BookRequestNode
{
    int studentID;
    string studentName;
    int bookID;
    string bookTitle;
    BookRequestNode* next;
};

class Queue
{
private:
    BookRequestNode* front;
    BookRequestNode* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool IsEmpty()
    {
        return front == NULL;
    }

    bool IsNotEmpty()
    {
        return front != NULL;
    }

    // add a request at the REAR
    void EnQueue(BookRequestNode* node)
    {
        node->next = NULL;
        if (IsEmpty())
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }

    // remove a request from the FRONT
    BookRequestNode* DeQueue()
    {
        if (IsEmpty())
            return NULL;

        BookRequestNode* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        temp->next = NULL;
        return temp;
    }

    // display from FRONT to REAR
    void PrintQueue()
    {
        if (IsEmpty())
        {
            cout << "No requests in the queue.\n";
            return;
        }
        BookRequestNode* current = front;
        while (current != NULL)
        {
            cout << "Student: " << current->studentID << " - " << current->studentName
                 << " | Book: " << current->bookID << " - " << current->bookTitle << endl;
            current = current->next;
        }
    }

    ~Queue()
    {
        while (IsNotEmpty())
            delete DeQueue();
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\n===== Library Book Request Management System =====\n";
        cout << "1. Add Book Request\n";
        cout << "2. Serve Next Request\n";
        cout << "3. Display All Requests\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Not Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            BookRequestNode* node = new BookRequestNode;
            cout << "Student ID: ";
            cin >> node->studentID;
            cin.ignore();
            cout << "Student Name: ";
            getline(cin, node->studentName);
            cout << "Book ID: ";
            cin >> node->bookID;
            cin.ignore();
            cout << "Book Title: ";
            getline(cin, node->bookTitle);
            q.EnQueue(node);
            cout << "Request added.\n";
        }
        else if (choice == 2)
        {
            BookRequestNode* served = q.DeQueue();
            if (served == NULL)
                cout << "Queue is empty. No request to serve.\n";
            else
            {
                cout << "Serving: " << served->studentID << " - " << served->studentName
                     << " | " << served->bookID << " - " << served->bookTitle << endl;
                delete served;
            }
        }
        else if (choice == 3)
        {
            q.PrintQueue();
        }
        else if (choice == 4)
        {
            if (q.IsEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
        }
        else if (choice == 5)
        {
            if (q.IsNotEmpty())
                cout << "Queue is not empty.\n";
            else
                cout << "Queue is empty.\n";
        }
        else if (choice == 6)
        {
            cout << "Exiting program.\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
