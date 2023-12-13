#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	//test functions:
  	
    int num = 0;
    int val = 0;

    cout << "Tester functions: " << endl;
    cout <<"Warning. Validation has not been added to input values. Preceed with caution." << endl;
    cout <<"\nNode number for insertion: ";
    cin >> num;

    cout << "Value added: ";
    cin >> val;
    
    //Function calls:
    insertAtN(head, num, val); 
    printNth(head, num);
    
    //rpint modified list:
    //cout << "The list after modifications: " << endl; 
   
    display(head);
    destroy(head);    
    return 0;
}
