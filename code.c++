#include <iostream>
#include <fstream>

using namespace std;

struct Node;
typedef Node* NodePtr;

struct Node
{
	int data_quantity;
	int *data;
	NodePtr link;
};

void array_print(int *in_array, int in_array_length);
void linked_list_print(NodePtr in_database);

int main()
{
	NodePtr database;
	NodePtr actual;
	ifstream myfile;
	int input;

	database = actual = NULL;
	myfile.open("data.txt");
	while ((myfile >> input).eof() != true)
	{
		if (database == NULL)
		{
			database = actual = new Node[1];
			actual->link = NULL;
		}
		else
		{
			actual->link = new Node[1];
			actual = actual->link;
			actual->link = NULL;
		}
		
		actual->data_quantity = input;
		actual->data = new int[actual->data_quantity];
		for (int i = 0; i < actual->data_quantity;i++)
		{
			myfile >> input;
			actual->data[i] = input;
		}
			}
	linked_list_print(database);

	myfile.close();
	return 1;
}

void array_print(int *in_array, int in_array_length)
{
	int i;
	for (i = 0;i < in_array_length; i++)
	{
		cout << in_array[i] << ",";
	}
	cout << endl;
}

void linked_list_print(NodePtr in_database)
{
	int quantity = 0;
	NodePtr sweeper;
	sweeper = in_database;
	while (sweeper != NULL)
	{
		quantity++;
		cout << "-------------\n";
		cout << "Uzol c." << quantity << endl;
		cout << "OBSAH:\n";
		array_print(sweeper->data, sweeper->data_quantity);
		sweeper = sweeper->link;
	}
}
