#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void turn(ClapTrap& attacker, ClapTrap& defender) {
    if (attacker.getHitPoints() <= 3) {
      unsigned int heal = (unsigned int)((std::rand() % 5) + 1);
      attacker.beRepaired(heal);
    }
    unsigned int dmg = (unsigned int)(std::rand() % 11);
    attacker.setAttackDamage(dmg);
    attacker.attack(defender.getName());
    defender.takeDamage(dmg);
}

int main() {
    std::srand((unsigned int)(std::time(0)));

    ClapTrap a("CL4P-TP");
    ClapTrap b("TR4P-CL");

    const unsigned int kMaxRounds = 10;
    unsigned int round = 0;

    while (a.getHitPoints() > 0 && b.getHitPoints() > 0 && round < kMaxRounds) {
        std::cout << "\n=== Round " << (round + 1) << " ===\n";
        if (a.getEnergyPoints() > 0 && a.getHitPoints() > 0) {
            turn(a, b);
        }
        if (b.getHitPoints() > 0 && b.getEnergyPoints() > 0) {
            turn(b, a);
        }
        ++round;
    }

    std::cout << "\n=== Result ===\n";
    std::cout << a.getName() << " HP=" << a.getHitPoints()
              << " EP=" << a.getEnergyPoints() << "\n";
    std::cout << b.getName() << " HP=" << b.getHitPoints()
              << " EP=" << b.getEnergyPoints() << "\n";
    std::cout << "\n";

    if (a.getHitPoints() == 0 && b.getHitPoints() == 0) {
        std::cout << "Both ClapTraps are down — it's a draw!\n";
    } else if (a.getHitPoints() == 0) {
        std::cout << "🏆 " << b.getName() << " wins! 🏆\n";
    } else if (b.getHitPoints() == 0) {
        std::cout << "🏆 " << a.getName() << " wins! 🏆\n";
    } else {
        std::cout << "Out of energy — no winner this time.\n";
    }
    std::cout << "\n";

    return 0;
}
