#include "ClapTrap.hpp"

/*************************************************HELPER FUNCTIONS************************************************/
bool ClapTrap::isSpaceOnly(const std::string& str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
} 

bool ClapTrap::IsValidName(const std::string& str) {
    if (str.empty() || isSpaceOnly(str)) return false;
    return true;
}

void ClapTrap::printStatus() const {
    std::cout << "[STATUS] " 
              << "Name=" << _name 
              << " | HP=" << _hitPoints 
              << " | EP=" << _energyPoints 
              << " | DMG=" << _attackDamage 
              << "\n";
}
/*****************************************************************************************************************/


/*********************************************ORTHODOX CANONICAL FORM*********************************************/
ClapTrap::ClapTrap()
: _name("No-name brand"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "[ClapTrap] assembled at the factory (default build).\n";
}

ClapTrap::ClapTrap(const std::string& name)
:  _name(IsValidName(name) ? name : "No-name brand"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "[ClapTrap] Unit " << GREEN << _name << RESET << " booted up with shiny new personality module!\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
: _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage){
    std::cout << "[ClapTrap] " << BLUE << _name << RESET << " cloned successfully. Double the trouble!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
    if (this != &src) {
        std::cout << "[ClapTrap] " << YELLOW << _name << RESET << " received a memory transplant from ansrc ClapTrap.\n";
        this->_name = src._name;
        this->_hitPoints = src._hitPoints;
        this->_energyPoints = src._energyPoints;
        this->_attackDamage = src._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "[ClapTrap] " << RED << _name << RESET <<" scrapped for spare parts. Farewell!\n";;
}
/*****************************************************************************************************************/


/*************************************************GETTERS&SETTERS*************************************************/
const std::string& ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }

void ClapTrap::setAttackDamage(unsigned int dmg) { _attackDamage = dmg; }
void ClapTrap::setName(const std::string& name) { 
     if (IsValidName(name))
        _name = name;
    else 
        std::cerr << "Invalid name, keeping old value: \"" << _name << "\"\n";
}
/*****************************************************************************************************************/


void ClapTrap::attack(const std::string& target) {
    if (target == _name){
        std::cerr << "⚠️ [ClapTrap] " << _name << " initiates SELF-DESTRUCT sequence!\n";
        _hitPoints = 0;
        return;
    }

    if (_hitPoints <= 0 || _energyPoints <= 0) 
        std::cerr << "[ClapTrap] " << _name << " can't attack\n";

    if (_attackDamage == 0) {
        std::cerr << "[ClapTrap] " << _name << " tries to attack " << target
                  << " but deals no damage!\n";
        --_energyPoints;
        return;
    }

    --_energyPoints;
    std::cout << "[ClapTrap] " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > 10) { 
        std::cerr << "Error: Invalid damage amount.\n";
        return;
    }
    if (_hitPoints == 0) {
        std::cerr << "[ClapTrap] " << _name << " is already out (no HP)\n";
        return;
    }
    unsigned int before = _hitPoints;
    _hitPoints = (amount >= _hitPoints) ? 0u : (_hitPoints - amount);
    std::cout << "[ClapTrap] " << _name << " takes " << amount
              << " damage (HP " << before << " -> " << _hitPoints << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (amount > 10) { 
        std::cerr << "Error: Invalid repair amount.\n";
        return;
    }
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cerr << "[ClapTrap] " << _name << " can't repair\n";
        return;
    }
    --_energyPoints;
    _hitPoints += (int)(amount);
    if (_hitPoints > 10)
        _hitPoints = 10;    
    std::cout << "[ClapTrap] " << _name << " repairs for " << amount
              << " (HP=" << _hitPoints << ", EP=" << _energyPoints << ")\n";
}
