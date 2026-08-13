/*
    3. Write a c++ program to implement Multilevel Inheritance. Consider base class1 as Animal, base
    class2 as Dog and derived class as Baby_dog.Consider suitable attributes and function.
*/

#include <iostream>
using namespace std;

class Animal
{
	protected:
		string name;

	public:
		void eat()
		{
			cout << "Animal is eating.";
		}
};

class Dog : public Animal
{
	protected:
		string breed;

	public:
		void bark()
		{
			cout << "Dog is barking.";
		}
};

class BabyDog : public Dog
{
	private:
		string color;

	public:
		void play()
		{
			cout << "Baby Dog is playing.";
		}

		void display()
		{
			name = "Tommy";
			breed = "Labrador";
			color = "Brown";

			cout << "Name: " << name;
			cout << "\nBreed: " << breed;
			cout << "\nColor: " << color;
		}
};

int main()
{
	BabyDog babyDog;

	cout << "Baby Dog Details:\n";
	babyDog.display();

	cout << "\n\n";
	babyDog.eat();

	cout << "\n";
	babyDog.bark();

	cout << "\n";
	babyDog.play();

	return 0;
}