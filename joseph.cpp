/*
* JOSEPH.CPP ---------
* METHODS OF JOSEPH.H
*/
#include "joseph.h"
#include <iostream>
#include <iomanip>

const extern std::string default_name = "default_name";
const extern std::string none = "none";
extern int player_counter = 0;

Player::Player() {
	_ID = 0;
	_name = default_name;
	_tel = none;
	_email = none;
	_idnum = none;
	_password = none;
	_score = 0;
	_game_number = 0;
}
Player::~Player() {}
Player::Player(const Player& player) {
	_ID = player._ID;
	_name = player._name;
	_tel = player._tel;
	_email = player._email;
	_idnum = player._idnum;
	_password = player._password;
	_score = 0;
	_game_number = 0;
}
void Player::operator= (const Player& source) {
	_ID = source._ID;
	_name = source._name;
	_tel = source._tel;
	_email = source._email;
	_idnum = source._idnum;
	_password = source._password;
	_score = source._score;
}

void Player::set_ID(const unsigned long int ID) {
	_ID = ID;
}
void Player::set_name(const std::string& name) {
	_name = name;
}
void Player::set_tel(const std::string& tel) {
	_tel = tel;
}
void Player::set_email(const std::string& email) {
	_email = email;
}
void Player::set_idnum(const std::string& idnum) {
	_idnum = idnum;
}
void Player::set_password(const std::string& password) {
	_password = password;
}
void Player::set_game_number(unsigned int game_number) {
	_game_number = game_number;
}

void Player::show_self_info() {
	if (get_access()) {
		std::cout << "username: " << show_name() << std::endl;
		std::cout << "\tID:\t" << show_ID() << std::endl;
		std::cout << "\ttel:\t" << show_tel() << std::endl;
		std::cout << "\temail:\t" << show_email() << std::endl;
		std::cout << "\tIDnum:\t" << show_idnum() << std::endl;
		std::cout << "\tscore:\t" << show_score() << std::endl;
	}
	else {
		return;
	}
}
void Player::show_other_info() {
	std::cout << "username: " << show_name() << std::endl;
	std::cout << "\tID:\t" << show_ID() << std::endl;
	std::cout << "\ttel:\t" << show_tel() << std::endl;
	std::cout << "\temail:\t" << show_email() << std::endl;
}

void create_account(Player& player) {
	std::string str_in;
	bool password_access = true;
	player._ID = ++player_counter;
	std::cout << "You are now sign in an account. Please follow the instructor." << std::endl;
	std::cout << "[username] "; std::cin >> str_in; player._name = str_in;
	std::cout << "[telephone]"; std::cin >> str_in; player._tel = str_in;
	std::cout << "[e-mail]   "; std::cin >> str_in; player._email = str_in;
	std::cout << "[IDnumber] "; std::cin >> str_in; player._idnum = str_in;
	while (password_access) {
		std::cout << "[password] "; std::cin >> str_in; player._password = str_in;
		std::cout << "please check your password\n[password] ";
		std::cin >> str_in;
		if (str_in == player._password) {
			password_access = false;
			std::cout << "Your account has already been built." << std::endl;
		}
		else {
			std::cout << "Your password doesn't match, please input again!" << std::endl;
		}
	}
}
Player& create_account() {
	Player* p_player = new Player;
	Player& ref_player = *p_player;
	std::string str_in;
	bool password_access = true;
	p_player->_ID = ++player_counter;
	std::cout << "You are now sign in an account. Please follow the instructor." << std::endl;
	std::cout << "[username] "; std::cin >> str_in; p_player->_name = str_in;
	std::cout << "[telephone]"; std::cin >> str_in; p_player->_tel = str_in;
	std::cout << "[e-mail]   "; std::cin >> str_in; p_player->_email = str_in;
	std::cout << "[IDnumber] "; std::cin >> str_in; p_player->_idnum = str_in;
	while (password_access) {
		std::cout << "[password] "; std::cin >> str_in; p_player->_password = str_in;
		std::cout << "please check your password\n[password] ";
		std::cin >> str_in;
		if (str_in == p_player->_password) {
			password_access = false;
			std::cout << "Your account has already been built." << std::endl;
		}
		else {
			std::cout << "Your password doesn't match, please input again!" << std::endl;
		}
	}
	return ref_player;
}
bool Player::get_access() {
	std::string password_input;
	std::cout << "Your are not accessibe to the infomation, please input password: \n[password] ";
	std::cin >> password_input;
	if (password_input == _password) {
		std::cout << "****SUCCESSFUL****" << std::endl;
		return true;
	}
	else {
		std::cout << "*****REJECTED*****" << std::endl;
		return false;
	}
}