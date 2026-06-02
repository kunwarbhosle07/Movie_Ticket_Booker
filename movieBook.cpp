#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 100;

// ---------------- MOVIE STRUCTURE ----------------

struct Movie
{
    int id;
    string name;
    int seats;
};

// ---------------- ARRAY STORAGE ----------------

Movie movies[MAX];
int movieCount = 0;

// ---------------- LINKED LIST ----------------

class Node
{
public:
    Movie data;
    Node* next;

    Node(Movie m)
    {
        data = m;
        next = NULL;
    }
};

Node* head = NULL;

// ---------------- STACK ----------------

stack<string> undoStack;

// ---------------- QUEUE ----------------

queue<string> waitingQueue;

// ---------------- BST ----------------

class BSTNode
{
public:
    Movie data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Movie m)
    {
        data = m;
        left = right = NULL;
    }
};

BSTNode* root = NULL;

// BST Insert

BSTNode* insertBST(BSTNode* root, Movie m)
{
    if(root == NULL)
        return new BSTNode(m);

    if(m.id < root->data.id)
        root->left = insertBST(root->left,m);

    else
        root->right = insertBST(root->right,m);

    return root;
}

// Inorder Traversal

void inorder(BSTNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    cout<<root->data.id<<" "
        <<root->data.name<<" "
        <<root->data.seats<<endl;

    inorder(root->right);
}

// ---------------- ADD MOVIE ----------------

void addMovie()
{
    Movie m;

    cout<<"Movie ID: ";
    cin>>m.id;

    cout<<"Movie Name: ";
    cin>>m.name;

    cout<<"Seats: ";
    cin>>m.seats;

    movies[movieCount++] = m;

    Node* temp = new Node(m);

    if(head == NULL)
        head = temp;

    else
    {
        Node* cur = head;

        while(cur->next)
            cur = cur->next;

        cur->next = temp;
    }

    root = insertBST(root,m);

    cout<<"Movie Added\n";
}

// ---------------- DISPLAY ----------------

void displayMovies()
{
    cout<<"\nMovie List\n";

    for(int i=0;i<movieCount;i++)
    {
        cout<<movies[i].id<<" "
            <<movies[i].name<<" "
            <<movies[i].seats<<endl;
    }
}

// ---------------- LINEAR SEARCH ----------------

int linearSearch(int id)
{
    for(int i=0;i<movieCount;i++)
    {
        if(movies[i].id == id)
            return i;
    }

    return -1;
}

// ---------------- QUICK SORT ----------------

int partition(int low,int high)
{
    int pivot = movies[high].id;

    int i = low-1;

    for(int j=low;j<high;j++)
    {
        if(movies[j].id < pivot)
        {
            i++;

            swap(movies[i],movies[j]);
        }
    }

    swap(movies[i+1],movies[high]);

    return i+1;
}

void quickSort(int low,int high)
{
    if(low<high)
    {
        int pi = partition(low,high);

        quickSort(low,pi-1);

        quickSort(pi+1,high);
    }
}

// ---------------- BINARY SEARCH ----------------

int binarySearch(int id)
{
    int low = 0;
    int high = movieCount-1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(movies[mid].id == id)
            return mid;

        if(movies[mid].id < id)
            low = mid+1;

        else
            high = mid-1;
    }

    return -1;
}

// ---------------- BOOK TICKET ----------------

void bookTicket()
{
    int id;

    cout<<"Enter Movie ID: ";
    cin>>id;

    int index = linearSearch(id);

    if(index==-1)
    {
        cout<<"Movie Not Found\n";
        return;
    }

    if(movies[index].seats>0)
    {
        movies[index].seats--;

        undoStack.push(movies[index].name);

        cout<<"Ticket Booked\n";
    }
    else
    {
        string customer;

        cout<<"Enter Name: ";
        cin>>customer;

        waitingQueue.push(customer);

        cout<<"Added to Waiting Queue\n";
    }
}

// ---------------- UNDO ----------------

void undoBooking()
{
    if(undoStack.empty())
    {
        cout<<"Nothing To Undo\n";
        return;
    }

    cout<<"Undo Booking Of "
        <<undoStack.top()<<endl;

    undoStack.pop();
}

// ---------------- QUEUE DISPLAY ----------------

void displayQueue()
{
    queue<string> temp = waitingQueue;

    while(!temp.empty())
    {
        cout<<temp.front()<<endl;
        temp.pop();
    }
}

// ---------------- MAIN ----------------

int main()
{
    int choice;

    while(true)
    {
        cout<<"\n1.Add Movie";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Book";
        cout<<"\n6.Undo";
        cout<<"\n7.Queue";
        cout<<"\n8.BST Display";
        cout<<"\n9.Exit";

        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addMovie();
                break;

            case 2:
                displayMovies();
                break;

            case 3:
            {
                int id;

                cout<<"ID: ";
                cin>>id;

                int pos = linearSearch(id);

                if(pos!=-1)
                    cout<<"Found\n";
                else
                    cout<<"Not Found\n";

                break;
            }

            case 4:
                quickSort(0,movieCount-1);
                cout<<"Sorted\n";
                break;

            case 5:
                bookTicket();
                break;

            case 6:
                undoBooking();
                break;

            case 7:
                displayQueue();
                break;

            case 8:
                inorder(root);
                break;

            case 9:
                return 0;
        }
    }
}