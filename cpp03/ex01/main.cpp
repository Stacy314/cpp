#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void turn_a(ClapTrap& attacker, ScavTrap& defender) {
    if (attacker.getHitPoints() == 0 || attacker.getEnergyPoints() == 0)
        return;
    if (attacker.getHitPoints() <= 30) {
        unsigned int heal = (unsigned int)((std::rand() % 50) + 1);
        attacker.beRepaired(heal);
    } 
    attacker.attack(defender.getName());
    defender.takeDamage(attacker.getAttackDamage());
}

static void turn_s(ScavTrap& attacker, ClapTrap& defender) {
    if (attacker.getHitPoints() == 0 || attacker.getEnergyPoints() == 0)
        return;
    if (attacker.getHitPoints() <= 3) {
        unsigned int heal = (unsigned int)((std::rand() % 5) + 1);
        attacker.beRepaired(heal);
    } 
    attacker.attack(defender.getName());
    defender.takeDamage(attacker.getAttackDamage());
}

int main() {
    std::srand((unsigned int)(std::time(0)));

    std::cout << "🤖 Construct ClapTrap DAN-TRP 🤖\n";
    ClapTrap a("DAN-TRP");
    a.printStatus();

    std::cout << "\n🤖 Construct ScavTrap CLAP-9000 🤖\n";
    ScavTrap s("CLAP-9000");
    s.printStatus();

    std::cout << "\n🤖 Show chaining (copy/assign) 🤖\n";
    ScavTrap s2(s);
    s2 = s;
    s2.setName("CLAP-9000v2");
    s.printStatus();
    s2.printStatus();

    std::cout << "\n🤖 Guard gate 🤖\n";
    s.guardGate();

    std::cout << "\n🔫 Duel 🔫\n";
    const unsigned int kMaxRounds = 50;
    for (unsigned int r = 0; r < kMaxRounds && a.getHitPoints() > 0 && s.getHitPoints() > 0; ++r) {
        std::cout << "\n=== Round " << (r + 1) << " ===\n";
        if (a.getEnergyPoints() > 0) turn_a(a, s);
        if (s.getEnergyPoints() > 0 && s.getHitPoints() > 0) turn_s(s, a);
        a.printStatus();
        s.printStatus();
    }

    std::cout << "\n⚰️ Destruction order on exit ⚰️\n";
    return 0;
}
