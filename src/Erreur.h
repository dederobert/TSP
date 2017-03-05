#pragma once
#include <string>
#include <sstream>

/**
* Class pour la gestion des erreurs
*/
class Erreur {
	/**
	* @var _message Message de l'erreur
	*/
	std::string _message;
	/**
	* @var _code Code de l'erreur
	*/
	int _code;
	/**
	* @var _parent Erreur parente dans la trace
	*/
	Erreur* _parent;
public:
	/**
	* Constructeur <br/>
	* Construit une erreur avec un message, un code et un parent
	* @param message Message de l'erreur
	* @param code Code de l'erreur <i>Optionel</i>
	* @param parent Parent de l'erreur <i>Optionel</i>
	*/
	Erreur(const std::string message, const int code = 0, Erreur* parent = NULL) :_message(message), _code(code), _parent(parent){}
	/**
	* Retourne le message de l'erreur
	* @return Message de l'erreur
	*/
	const std::string getMessage() const { return _message; }
	/**
	* Retourne le code de l'erreur
	* @return Code de l'erreur
	*/
	const int getCode() const { return _code; }
	/**
	* Retourne le parent de l'erreur
	* @return Parent de l'erreur
	*/
	const Erreur* getParent() const { return _parent; }
	/**
	* Permet d'otenir le trace de l'erreur
	* @return Trace des erreurs
	*/
	const std::string trace() const {
		std::ostringstream oss;
		oss << "Error with code " << getCode() << ": " << getMessage();
		if (_parent != NULL) {
			oss << "\ncaused by " << _parent->trace();
		}
		return oss.str();
	}
};