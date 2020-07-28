#include <iostream>
#include <string>

using namespace std;

struct Info
{
	int* seat;
	int* Age;
	string destination;
	int price;
	string customer;
	string* passengers;
	string type;
	string designation;
	
};

class Bus
{
public:

	Bus()
	{
		totalsize = 5;
		counter = 0;
		n = new Info[totalsize];
		ebuses = 20;
		oldpeople = 5;
		golds = 15;
	}
	void Ticket(string name);
	void Display(string name);
	int Destination(string, string, int,int&);
	int typePrices(string type, int passengers, int n);
private:
	int totalsize,counter;
	Info* n;
	int golds,oldpeople,ebuses;
	
};

int main()
{
	Bus brs;
	string name;
	char op;


	do
	{
		cout << "1. Buy Ticket\n";
		cout << "2. Display Seating Arrangements\n";
		cout << "Choose: ";
		cin >> op;
		;
		switch (op)
		{
		case '1':
			cin.ignore();
			cout << "Name: ";
			getline(cin, name);
			brs.Ticket(name);
			break;
		case '2':
			cin.ignore();
			cout << "Customer Name: ";
			getline(cin, name);
			brs.Display(name);
			break;
		default:
			cout << "Exiting Program\n\n";
			;
		}
	} while (true);
}

//										DISPLAY FUNCTION

void Bus::Display(string name)
{
	string type = "";
	for (int i = 0; i < counter; i++)
	{
		if (n[i].customer == name)
			type = n[i].type;
	}
	if (type == "");
	else if(type != "CARGO")
	{
		for (int i = 0; i < counter; i++)
		{
			if (n[i].type == type)
			{
				cout << "Customer Name: " << n[i].customer << endl;
				cout << "Designation : " << n[i].designation << endl;
			}
		}
	}
	else if (type == "CARGO")
	{
		for (int i = 0; i < counter; i++)
		{
			if (n[i].type == type)
				cout << "Customer Name: " << n[i].customer << endl;
		}
	}
}

//										TICKET BUYING FUNCTION

void Bus::Ticket(string name)
{
	char op;
	Info* temp = new Info;
	int ticketsbought;
	temp->customer = name;
		cout << "Select type:-\n\n"
			<< "1. GOLD\n"
			<< "2. EBUS\n"
			<< "3. CARGO\n\n"
			<< "Choose: ";
		cin >> op;
		switch (op)
		{
		case '1':
			temp->type = "GOLD";
			break;

		case '2':
			temp->type = "EBUS";
			break;
		case '3':
			temp->type = "CARGO";
			break;
		default:
			cout << "Choose from the given options\n\n";

		}
	if((temp->type == "GOLD" && golds) || (temp->type == "EBUS" && ebuses))
		do
		{
			int seats;
			if (temp->type == "GOLD")
				seats = golds;
			else if (temp->type == "EBUS")
				seats = ebuses;
			cout << "Seats Left: " << seats << endl;
			cout << "How Many: ";
			cin >> ticketsbought;
		
		} while (ticketsbought <= 0 && golds < ticketsbought);
	;
	if (temp->type == "GOLD")
	{
		temp->passengers = new string[ticketsbought];
		temp->Age = new int[ticketsbought];
		temp->seat = new int[ticketsbought];
		
		cin.ignore();
		if (ticketsbought >= 1)
		{
			for (int i = 0; i < ticketsbought; i++)
			{
				cout << "\n\nPassenger " << i + 1 << endl;
				cout << "\nName: ";
				cin.ignore();
				getline(cin, temp->passengers[i]);
				cout << "Age: ";
				cin >> temp->Age[i];
				if (temp->Age[i] > 50)
				{
					if (oldpeople == 5)
						temp->seat[i] = 16;
					else if (oldpeople == 4)
						temp->seat[i] = 17;
					else if (oldpeople == 3)
						temp->seat[i] = 18;
					else if (oldpeople == 2)
						temp->seat[i] = 19;
					else if (oldpeople == 1)
						temp->seat[i] = 20;
					else if (oldpeople == 0)
						temp->seat[i] = golds--;
					oldpeople--;
				}

			}
		}
	}
	else if (temp->type == "EBUS")
	{
		temp->seat = new int[ticketsbought];
		for (int i = 0; i < ticketsbought; i++)
			temp->seat[i] = ebuses--;
	}
	cout << "\nDestination: ";
	cin.ignore();
	getline(cin, temp->destination);
	temp->price = Destination(temp->type, temp->destination, ticketsbought,temp->price);
	n[counter].customer = temp->customer;
	n[counter].type = temp->type;
	n[counter].price = temp->price;
	if (temp->type == "GOLD" || temp->type == "EBUS")
		n[counter].seat = temp->seat;
	n[counter].designation = temp->designation;
	n[counter].destination = temp->destination;
	if (temp->type == "GOLD")
		n[counter].passengers = temp->passengers;
	counter++;
	if (counter >= totalsize)
	{
		Info* temp = new Info[totalsize * 2];
		for (int i = 0; i < totalsize; i++)
			*(temp + i) = *(n + i);
		n = temp;
		totalsize *= 2;
	}
}

int Bus::Destination(string type, string destination, int passengers,int& price)
{
	if (destination == "Multan")
		price = typePrices(type, passengers, 1);
	else if (destination == "Lahore")
		price = typePrices(type, passengers, 2);
	else if (destination == "Abbottabad")
		price = typePrices(type, passengers, 3);
	else return -1;
	cout << "TOTAL PRICE: " << price << endl;
}

int Bus::typePrices(string type,int passengers,int n)
{
	int price;
	int weight;

	if (type == "GOLD")
	{
		if (n == 1)
			price = passengers * 4000;
		else if (n == 2)
			price = passengers * 2000;
		else if (n == 3)
			price = passengers * 1000;
		return price;
	}
	else if (type == "EBUS")
	{
		if (n == 1)
			price = passengers * 3000;
		else if (n == 2)
			price = passengers * 1000;
		else if (n == 3)
			price = passengers * 500;
		return price;

	}
	else if (type == "CARGO")
	{
		do
		{
			cout << "Weight of LuggAge: ";
			cin >> weight;
		} while (weight < 0);
		if (weight <= 25)
		{
			if (n == 1)
				price = weight * 2000;
			else if (n == 2)
				price = weight * 1500;
			else if (n == 3)
			{
				price = weight * 1000;
				int discount = price * 10 / 100;
				price -= discount;
			}
			return price;
		}
		else
		{
			int addition = 0;
			addition = weight - 25;
			addition *= 500;
			if (n == 1)
				price = weight * 2000 + addition;
			else if (n == 2)
				price = weight * 1500 + addition;
			else if (n == 3)
				price = weight * 1000 + addition;
			return price;
		}
	}
}