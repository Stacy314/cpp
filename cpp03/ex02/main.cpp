#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

 static void turn_f(FragTrap& attacker, ScavTrap& defender) {
     if (attacker.getHitPoints() == 0 || attacker.getEnergyPoints() == 0)
         return;
     if (attacker.getHitPoints() <= 50) {
         unsigned int heal = (unsigned int)((std::rand() % 30) + 1);
         attacker.beRepaired(heal);
     } 
     attacker.attack(defender.getName());
     defender.takeDamage(attacker.getAttackDamage());
 }

 static void turn_s(ScavTrap& attacker, FragTrap& defender) {
     if (attacker.getHitPoints() == 0 || attacker.getEnergyPoints() == 0)
         return;
     if (attacker.getHitPoints() <= 50) {
         unsigned int heal = (unsigned int)((std::rand() % 30) + 1);
         attacker.beRepaired(heal);
     } 
     attacker.attack(defender.getName());
     defender.takeDamage(attacker.getAttackDamage());
 }

int main() {
    std::srand((unsigned int)(std::time(0)));

    std::cout << "\n🤖 Construct ScavTrap  SC4V-TP 🤖\n";
    ScavTrap s("SC4V-TP");
    s.printStatus();

    std::cout << "\n🤖 Construct FragTrap DAN-TRP 🤖\n";
    FragTrap f("DAN-TRP");
    f.printStatus();

    std::cout << "\n🤖 Show chaining (copy/assign) for ScavTrap 🤖\n";
    ScavTrap s2(s);
    s2 = s;
    s2.setName("SC4V-TPv2");
    s2.printStatus();

    std::cout << "\n🤖 Show chaining (copy/assign) for FragTrap 🤖\n";
    FragTrap f2(f);
    f2 = f;
    f2.setName("DAN-TRP");
    f2.printStatus();

	std::cout << "\n🤖 Special abilities used 🤖\n";
    s.guardGate();
	std::cout << "\n";
	f.highFivesGuys();

    std::cout << "\n🔫 Duel started🔫\n";
    const unsigned int kMaxRounds = 50;
    for (unsigned int r = 0; r < kMaxRounds && f.getHitPoints() > 0 && s.getHitPoints() > 0; ++r) {
        std::cout << "\n=== Round " << (r + 1) << " ===\n";
        if (f.getEnergyPoints() > 0 && s.getHitPoints() > 0) {
			std::cout << "\nFragTrap's turn ➡️\n";
			turn_f(f, s);
		}
        if (s.getEnergyPoints() > 0 && s.getHitPoints() > 0) {
			std::cout << "\nScavTrap's turn ➡️\n";
		 	turn_s(s, f);
		}
		std::cout << "\n";
        f.printStatus();
        s.printStatus();
    }
    if (s.getHitPoints() == 0 && f.getHitPoints() == 0) {
        std::cout << "Both ClapTraps are down — it's a draw!\n";
    } else if (s.getHitPoints() == 0) {
        std::cout << "\n🏆 " << f.getName() << " wins! 🏆\n";
    } else if (f.getHitPoints() == 0) {
        std::cout << "\n🏆 " << s.getName() << " wins! 🏆\n";
    } else {
        std::cout << "Out of energy — no winner this time.\n";
    }
    std::cout << "\n⚰️ Destruction order on exit ⚰️\n";
    return 0;
}
