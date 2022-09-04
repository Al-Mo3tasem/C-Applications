#include<string>
#include<iomanip>
#include<iostream>
using namespace std;
int flag=0;
class Phone_Directory {
private:
	string FIRST_NAME, LAST_NAME, PHONE_NEMBER;
	public:
		friend class Lindked_List;
		Phone_Directory() {};
		Phone_Directory(string firstname, string lastname, string phonenumber) {
			FIRST_NAME = firstname;
			LAST_NAME = lastname;
			PHONE_NEMBER = phonenumber;
		}
		void print() {
			cout << FIRST_NAME << "  " << LAST_NAME << "  " << PHONE_NEMBER << endl;
		}
		string Get_Phone_Number() {
			return PHONE_NEMBER;
		}
		string Get_First_Name() {
			return FIRST_NAME;
		}
};
/**********************************************************************************************/
struct Node {
	Phone_Directory p;
	Node* next=NULL;
	Node* prev = NULL;
};
/***********************************************************/
class Lindked_List {
private:
	Node* head;
	Node* tail;
	int length = 0;
public:
	Node* get_head() {
		return head;
	}
	Node* get_tail() {
		return tail;
	}
	int get_length() {
		return length;
	}
	Lindked_List() {
		head = head;
		tail = tail;
	};
	/****************************************/
	void front_add_node() {
		cout << "Please enter first name, last name and phone number:" << endl;
		string f, l, phone;
		cin >> f >> l >> phone;
		cout << endl;
		Phone_Directory obj(f, l, phone);
		Node* n = new Node();
		n->p = obj;
		if (length == 0) {
			n->next = NULL;
			n->prev = NULL;
			head = n, tail = n;
		}
		else  {
			n->prev = tail;
			tail->next = n;
			n->next = NULL;
			tail = n;
		}
		length++;
	}
	/********************************/
	void look_for_by_phone() {
		if (length == 0) {
			cout << "THE DIRECTORY IS EMPTY!" << endl << endl;
		}
		else {
			string phone;
			cout << "Please enter the phone number you looking for: ";
			cin >> phone;
			cout << endl;
			Node* looker = new Node;
			looker = head;
			for (int i = 0;i < length;i++) {
				if (looker->p.PHONE_NEMBER == phone) {
					cout << "Found!" << endl;
					looker->p.print();
					flag = 1;
					looker = NULL;
					delete looker;
					break;
					  
				}
				looker = looker->next;
				if (looker == NULL)
					break;
			}
			if (flag == 0)
				cout << "NOT FOUND!\n" << "NO ENTRY WITH SUCH A NAME!\n\n";
			flag = 0;
			looker = NULL;
			delete looker;
		}
	}
	/*************************/
	void look_for_by_name() {
		if (length == 0) {
			cout << "The directory is empty!" << endl << endl;
		}
		else {
			string name;
			cout << "Please enter the Name you looking for: ";
			cin >> name;
			cout << endl;
			Node* looker = new Node;
			looker = head;
			for (int i = 0;i < length;i++) {
				if (looker->p.FIRST_NAME == name) {
					cout << "Found!" << endl;
					looker->p.print();
					flag = 1;
					looker = NULL;
					delete looker;
					break;

				}
				looker = looker->next;
				if (looker == NULL)
					break;
			}
			if (flag == 0)
				cout << "NOT FOUND!\n" << "NO ENTRY WITH SUCH A NAME!\n\n";
			flag = 0;
			looker = NULL;
			delete looker;
		}
	}
	/*************************/
	void delete_node(){
		if (length == 0) {
			cout << "THE DIRECTORY IS EMPTY!" << endl << endl;
		}
		else {
			string name;
			cout << "Please enter the Name you want to delete: ";
			cin >> name;
			cout << endl;
			Node* looker = new Node;
			looker = head;
			Node* pre = new Node;
			pre = NULL;
			for (int i = 0;i < length;i++) {
				if (i == 0 && length == 1 && looker->p.FIRST_NAME == name) {
					head = NULL;
					tail = NULL;
					delete looker;
					cout << "DELETED SUCCESSFULLY!" << endl;
					length--;
					flag = 1;
					break;
				}
				else if (i == 0 && looker->p.FIRST_NAME == name) {
					head = head->next;
					delete looker;
					head->prev = NULL;
					cout << "DELETED SUCCESSFULLY!" << endl;
					length--;
					flag = 1;
					break;
				}
				else if (i == length - 1 && looker->p.FIRST_NAME == name&&pre!=NULL) {
					tail = pre;
					pre->next = NULL;
					delete looker;
					cout << "DELETED SUCCESSFULLY!" << endl;
					length--;
					flag = 1;
					break;
				}
				else if (looker->p.FIRST_NAME == name&&pre!=NULL) {
					cout << "DELETED SUCCESSFULLY!" << endl;
					pre->next = looker->next;
					pre->next->prev = pre;
					length--;
					delete looker;
					flag = 1;
					break;

				}
				pre= looker;
				looker = looker->next;
				if (looker == NULL)
					break;
			}
			if (flag == 0)
				cout << "NOT FOUND!\n" << "NO ENTRY WITH SUCH A NAME!\n\n";
		   //**********************
			   Bubble_Sort();
		      //Insertion_Sort();
			  //Selection_Sort();
	       //**********************
			flag = 0;
			looker = NULL;
			delete looker;
		
		}
	}
	/********************/
	void swap_nodes( Node* curser,Node*iter) {
		Phone_Directory temp;
		temp = curser->p;
		curser->p = iter->p;
		iter->p = temp;
	}
	/*******************/
	void print_list() {
		if (length == 0) {
			cout << "THE DIRECTORY IS EMPTY!" << endl << endl;
		}
		else {
	 //**********************
			Bubble_Sort();
		   //Insertion_Sort();
		   //Selection_Sort();
	 //**********************
			Node* printer = new Node;
			printer = head;
			for (int i = 0;i <= length;i++) {
				printer->p.print();
				printer = printer->next;
				if (printer == NULL)
					break;
			}
			delete printer;
		}
	}
	/*//////////////////*/
	void Bubble_Sort() {

		Node* curser = new Node;
		curser = get_head();
		Node* iterator = new Node;
		for (int i = 0;i < get_length() - 1;i++) {
			iterator = get_head();
			for (int j = 0;j < get_length() - i - 1;j++) {

				if (iterator != NULL && iterator != iterator->next) {
					if (iterator->p.Get_First_Name() > iterator->next->p.Get_First_Name()) {
						swap(iterator->p, iterator->next->p);
						flag = 1;
					}
					iterator = iterator->next;
					if (iterator == NULL)
						break;
				}

			}
			curser = curser->next;
			if (curser == NULL)
				break;
		}
	}
	void Selection_Sort() {

		Node* curser = new Node;
		curser = get_head();
		Node* iter = new Node;
		for (int i = 0;i < get_length() - 1;i++) {
			iter = curser->next;
			for (int j = i + 1;j < get_length();j++) {
				if (iter != NULL && iter->p.Get_First_Name() < curser->p.Get_First_Name())
					swap_nodes(curser, iter);
				if (iter != NULL)
					iter = iter->next;
				if (iter == NULL)
					break;
			}
			curser = curser->next;
			if (curser == NULL)
				break;
		}

	}

	/*//////////////////////////*/
	void Insertion_Sort() {
		Node* curser = new Node;
		curser = get_head()->next;
		Node* iter = new Node;
		int f1 = 0, f2 = 0;
		int j, i;
		Phone_Directory test;
		for (i = 1; i < get_length(); i++)
		{
			test = curser->p;
			iter = curser->prev;
			j = i - 1;
			while (j >= 0 && iter->p.Get_First_Name() > test.Get_First_Name())
			{
				f2 = 1;
				iter->next->p = iter->p;
				j = j - 1;
				if (iter->prev == NULL)
					break;
				iter = iter->prev;
				f1 = 1;
			}
			if ((iter->prev != NULL || f1 == 1) && (f2 == 1))
				iter->next->p = test;
			else if (f2 == 1)
				iter->p = test;
			curser = curser->next;
			f1 = 0;
			f2 = 0;
			if (curser == NULL)
				break;
		}

	}
};
/*************************************************************************************/

/****************/
  int main()
  {
	  Lindked_List li;
	char choice=' ';
	do {
		cout << "Please select one of the following operations:  \n\n";
		cout << "1: Add an entry to the directory.\n"
			"2: Look up a phone number.\n"
			"3: Look up by first name.\n"
			"4: Delete an entry from the directory.\n"
			"5: List All entries in phone directory.\n"
			"6: Exit form this program.\n\n";

		cin >> choice;
		cout << endl;
		if (choice == '1') {

			li.front_add_node();
		}
		else if (choice == '2') {
			li.look_for_by_phone();

		}
		else if (choice == '3') {
			li.look_for_by_name();
		}
		else if (choice == '4') {
			li.delete_node();
		}
		else if (choice == '5') {
			li.print_list();
		}
		else if (choice == '6') {
			cout << "GOOD BYE :>" << endl;
		}
	} while (choice != '6');
}

  




