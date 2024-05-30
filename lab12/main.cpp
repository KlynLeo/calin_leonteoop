#include <iostream>
#include "AddressBook.h"
#include "Contact.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleauge.h"
using namespace std;

int main()
{
	AddressBook a;
	a.Add(new Friend("John"));
	a.Add(new Acquaintance("Silviu"));
	a.Add(new Colleauge("Maria"));
	a.Add(new Friend("Andrew"));

	vector<Contact*> friends = a.FriendList();
	for (auto f : friends)
	{
		cout << f->GetName() << endl;
	}

	string contact = "Maria";
	a.DeleteContact(contact);
	if (a.Search("Maria") == 0)
		cout << "Nu exista Maria";
	else
		cout << "Exista Maria";
	if (a.Search("John") == 0)
		cout << "Nu exista John";
	else
		cout << "Exista John";

}