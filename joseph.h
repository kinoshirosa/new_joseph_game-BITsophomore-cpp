#ifndef _JOSEPH_H_
#define _JOSEPH_H_

#include <string>

class Player {
private:
	unsigned long int _ID;
	std::string _name;
	std::string _tel;
	std::string _email;
	std::string _idnum;
	std::string _password;
	unsigned int _score;
	unsigned int _game_number;
public:
	Player();
	~Player();
	Player(const Player& player);
	void operator= (const Player& source);

	void set_ID(const unsigned long int ID);
	void set_name(const std::string& name);
	void set_tel(const std::string& tel);
	void set_email(const std::string& email);
	void set_idnum(const std::string& idnum);
	void set_password(const std::string& password);
	void set_game_number(unsigned int game_number);
	void score_countup() { _score++; };

	void show_self_info();
	void show_other_info();
	unsigned long int show_ID() { return _ID; };
	std::string show_name() { return _name; };
	std::string show_tel() { return _tel; };
	std::string show_email() { return _email; };
	std::string show_idnum() { return _idnum; };
	std::string show_password() { return _password; };
	unsigned int show_game_number() { return _game_number; };
	unsigned int show_score() { return _score; };

	friend void create_account(Player&);
	friend Player& create_account();
	bool get_access();
};
#endif    /*THE END OF _JOSEPH_H_*/