#include <iostream>
#include <cstdlib>
#include <fstream>
#include "DataType.h"
#include "BinaryTree.h"

using namespace std;


int main(int argc, char* argv[])
{
	//create objects
	BinaryTree BT;
	DataType item;
	int input;
	fstream fs;

	//read argument for filename and opens
	fs.open(argv[1], fstream::in);
	if(fs.is_open())
	{
		//read input from file
		fs >> input;
		while (!fs.eof())
		{
			item.initialize(input);
			BT.insert(item);
			cout<<input<<" inserted"<<endl;
			fs >> input;
		}
		//insert last file item
		item.initialize(input);
		BT.insert(item);
		cout<<input<<" inserted"<<endl;
	}
	else {//error has occurred
		cout << "Failed to open the input file" << endl;
		exit(1);
	}
	//print list of commands
	cout<<endl<<"COMMANDS: insert(i), delete (d), retrieve (r), length(l), in-order (n), pre-order (p), post-order (o), get non-siblings (c), quit(q)"
  <<endl<<endl;

  char command;

  do// loop for commands
   {
    cout<<"Enter a command: ";
    cin>>command;

    //series of if statements. each for an implemented command
    if(command == 'i' ||command == 'I')
    {
      int input;

      cout<<endl<<"NUMBER TO INSERT: ";
      cin>>input;
      item.initialize(input);
      BT.insert(item);
      cout<<endl<<"IN-ORDER: ";
      BT.inOrder();
      cout<<endl<<endl;
    }
    else if(command == 'd' || command == 'D' )
    {
      cout<<endl<<"ITEM TO DELETE: ";
      cin>>input;
      item.initialize(input);
      BT.deleteItem(item);
      cout<<endl<<"IN-ORDER: ";
      BT.inOrder();
      cout<<endl<<endl;
    }
    else if(command == 'r' || command =='R')
      {
    	bool inTree = false;
        cout<<endl;
        cout<<"ITEM TO BE RETRIEVED: ";
        cin>>input;
        item.initialize(input);
        BT.retrieve(item, inTree);
        if(inTree)
        	cout<<"ITEM FOUND IN TREE";
        else
        	cout<<"ITEM NOT IN TREE";
        cout<<endl<<endl;
      }
    else if(command == 'l' || command == 'L')
    {
      cout<<endl<<"LIST LENGTH: " << BT.getLength() <<endl<<endl;
    }
    else if(command == 'n' || command == 'N')
      {
    	 cout<<endl<<"IN-ORDER: ";
    	 BT.inOrder();
    	 cout<<endl<<endl;
      }
    else if(command == 'p' || command == 'P')
      {
        cout<<endl<<"PRE-ORDER: ";
        BT.preOrder();
        cout<<endl<<endl;
      }
    else if(command == 'o' || command == 'O')
      {
        cout<<endl<<"POST-ORDER: ";
        BT.postOrder();
        cout<<endl<<endl;
      }
    else if(command == 'c' || command == 'C')
    {
    	cout<<endl<<"ITEM TO FIND SAME LEVEL NONSIBLINGS: ";
    	cin>>input;
    	item.initialize(input);
    	BT.getSameLevelNonsiblings(item);
    	cout<<endl<<endl;
    }

    else if(command == 'q' || command =='Q')
    {
    	BT.~BinaryTree();
    	cout<<endl<<"QUITING PROGRAM..."<<endl<<endl;
    	exit(0);
    }
    else
    {
      cout<<endl<<"COMMAND NOT RECOGNISED. TRY AGAIN."<<endl<<endl;
    }
  }//do

  //while user has not exited
   while (command != 'q' ||command != 'Q');
}
