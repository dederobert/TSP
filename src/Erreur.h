#pragma once
#include <string>
#include <sstream>

class Erreur {
	std::string _message;
	int _code;
	Erreur* _parent;
public:
	Erreur(const std::string message, const int code = 0, Erreur* parent = NULL) :_message(message), _code(code), _parent(parent){}
	const std::string getMessage() const { return _message; }
	const int getCode() const { return _code; }
	const Erreur* getParent() const { return _parent; }
	const std::string trace() const {
		std::ostringstream oss;
		oss << "Error with code " << getCode() << ": " << getMessage();
		if (_parent != NULL) {
			oss << "\ncaused by " << _parent->trace();
		}
		return oss.str();
	}
};