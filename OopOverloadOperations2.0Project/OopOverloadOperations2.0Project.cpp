#include <iostream>
#include "Money.h"
#include "Vector.h"
#include "User.h"

void PrintVector(Vector v)
{
    for (int i = 0; i < v.Size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

void UsersSort(User* users, int size, UserSortAge* obj = nullptr)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = size - 1; j > i; j--)
            if(obj ? (*obj)(users[j], users[j - 1]) : users[j] < users[j - 1])
            {
                User temp = users[j];
                users[j] = users[j - 1];
                users[j - 1] = temp;
            }
    }
}

int main()
{
    /*
    Money m1(10, 45);
    std::cout << m1 << "\n";
    ++m1;
    std::cout << m1 << "\n";

    srand(time(nullptr));
    Vector v1(10);

    for (int i = 0; i < v1.Size(); i++)
        v1[i] = rand() % 100;
    
    for (int i = 0; i < v1.Size(); i++)
        std::cout << v1[i] << " ";
    std::cout << "\n";

    User user;
    user["name"] = "Bob";
    user["address"] = "Moscow, Tverskaya";
    user["email"] = "user@gmail.com";

    std::cout << user << "\n";
    */
    // 1
    //Vector v1(5);
    //Vector v2 = v1;
    
    //
    //Vector v3(5);
    //PrintVector(v3);

    User users[5];
    users[0]["name"] = "Sam";
    users[0].Age() = 32;
    users[1]["name"] = "Joe";
    users[1].Age() = 19;
    users[2]["name"] = "Tim";
    users[2].Age() = 40;
    users[3]["name"] = "Bob";
    users[3].Age() = 31;
    users[4]["name"] = "Leo";
    users[4].Age() = 28;

    for (int i = 0; i < 5; i++)
        std::cout << users[i] << "\n";
    std::cout << "\n";

    UsersSort(users, 5, new UserSortAge());

    for (int i = 0; i < 5; i++)
        std::cout << users[i] << "\n";
    std::cout << "\n";
}
