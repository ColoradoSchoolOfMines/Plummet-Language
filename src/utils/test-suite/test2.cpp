#include <iostream>
#include <utility>
#include <string>
#include <vector>

#include "TestSuite.hpp"

class Person {
	private:
		std::string name;
		int age;

	public:
		Person(std::string name, int age) : name(name), age(age) {}

		std::string getPerson() {
			return "Person: [name: " + name + ", age: " + std::to_string(age) + "]";
		}
};

int main() {
	TestSuite ts("Class Test");

	std::vector<Person*> people;
	std::vector<std::pair<std::string, int>> peopleInformation = {
		std::make_pair("John", 20),
		std::make_pair("Jane", 21),
		std::make_pair("Jack", 22),
	};

	ts.beforeAll([&]() {
			people.push_back(new Person("Jill", 19));
			return true;
	});

	ts.beforeEach([&]() {
		static size_t index = 0;

		// Make sure that if more tests are added, they will fail
		if (index >= peopleInformation.size()) {
			return false;
		}

		// Add person to list
		std::string name = peopleInformation[index].first;
		int age = peopleInformation[index].second;
		people.push_back(new Person(name, age));

		index++;
		return true;
	});

	ts.addTest("Person 1 and 2", [&]() {
		std::string person1 = people[0]->getPerson();
		std::string person2 = people[1]->getPerson();
		std::string actual1 = "Person: [name: Jill, age: 19]";
		std::string actual2 = "Person: [name: John, age: 20]";
		return person1 == actual1 && person2 == actual2;
	});

	ts.addTest("Person 3", [&]() {
		std::string person3 = people[2]->getPerson();
		std::string actual3 = "Person: [name: Jane, age: 21]";
		return person3 == actual3;
	});

	ts.addTest("Person 4", [&]() {
		std::string person4 = people[3]->getPerson();
		std::string actual4 = "Person: [name: Jack, age: 22]";
		return person4 == actual4;
	});

	ts.runTests();
}
