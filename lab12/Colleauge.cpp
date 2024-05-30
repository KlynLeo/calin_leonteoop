#include "Colleauge.h"

Colleauge::Colleauge(string nume)
{
	name = nume;
}

string Colleauge::GetName() {
	return name;
}

ContactType Colleauge::GetType()
{
	return ContactType::Friend;
}