#pragma once
#include <iostream>

class User
{
	std::string name;
	std::string address;
	std::string email;

	int age;

public:
	User() : User("", 0) {}
	User(std::string name, int age) : name{ name }, age{ age } {}

	friend bool operator<(User u1, User u2)
	{
		return u1.name < u2.name;
	}

	std::string& operator[](std::string key)
	{
		if (key == "name")
			return this->name;
		if (key == "address")
			return this->address;
		if (key == "email")
			return this->email;
	}

	int& Age() { return age; }

	friend std::ostream& operator<<(std::ostream& out, User u)
	{
		out << "Name: " << u.name;
		out << " Age: " << u.age;
		//out << ", Address: " << u.address;
		//out << ", Email: " << u.email;
		return out;
	}
};


class UserSortAge
{
public:
	bool operator()(User u1, User u2)
	{
		return u1.Age() < u2.Age();
	}
};

