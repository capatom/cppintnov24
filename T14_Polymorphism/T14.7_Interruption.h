#pragma once
#include <string>
#include <string_view>
#include <iostream>
#include <format>

class Interruption {
public:
	// modifiers
	virtual void execute() = 0;
	virtual ~Interruption() = default;
protected:
	Interruption(std::string_view name) : _name(name) {}
	std::string _name;
};

class Need_A_Pee : public Interruption {
public:
	enum Gender {MALE, FEMALE};
	Need_A_Pee(std::string_view name, Gender gender) : Interruption(name), _gender(gender) {}
	void execute() override { std::cout << std::format("\n{} gone to {} toilet\n\n", _name, gender()); }
	std::string_view gender() const { return _gender == MALE ? "male" : "female"; }
private:
	Gender _gender;
};

class Dog_Eats_Neighbours_Cat : public Interruption {
public:
	Dog_Eats_Neighbours_Cat(std::string_view name, std::string_view neighbour_name) : Interruption(name), _neighbour_name(neighbour_name) {}
	void execute() override { std::cout << std::format("\n{} is busy on the phone because their dog has eaten {}'s cat\n\n", _name, _neighbour_name); }
private:
	std::string _neighbour_name;
};

class Team_Meeting : public Interruption {
public:
	Team_Meeting(std::string_view name, std::string_view roomNo) : Interruption(name), _roomNo(roomNo) {}
	void execute() override { std::cout << std::format("\n{} is in room {} having a team-meeting\n\n", _name, _roomNo); }
private:
	std::string _roomNo;
};