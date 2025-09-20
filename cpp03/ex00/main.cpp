#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

static void turn(ClapTrap& attacker, ClapTrap& defender) {
    attacker.beRepaired(10);
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

    std::cout << "\n🤖 Construct ClapTraps 🤖\n";
    ClapTrap a("CL4P-TP");
    a.printStatus();
    std::cout << "\n";
    ClapTrap b("TR4P-CL");
    b.printStatus();

	std::cout << "\n🤖 Show chaining (copy/assign) 🤖\n";
    ClapTrap a2(a);
    a2 = a;
    a2.setName("CL4P-TPv2");
    a2.printStatus();

    const unsigned int kMaxRounds = 10;
	std::cout << "\n🔫 Duel started 🔫\n";
    for (unsigned int r = 0; a.getHitPoints() > 0 && b.getHitPoints() > 0 && r < kMaxRounds 
        && (a.getEnergyPoints() > 0 || b.getEnergyPoints() > 0); ++r) {
        std::cout << "\n=== Round " << (r + 1) << " ===\n";
        if (a.getEnergyPoints() > 0 && a.getHitPoints() > 0) {
            turn(a, b);
        }
        if (b.getHitPoints() > 0 && b.getEnergyPoints() > 0) {
            turn(b, a);
        }
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

    std::cout << "\n⚙️ Additional tests ⚙️\n";
    ClapTrap c;
    c.printStatus();
    c.setName("");
    c.setName(" ");
    std::cout << "\n";
    ClapTrap d("");
    d.printStatus();
    std::cout << "\n";
    ClapTrap e("   ");
    e.printStatus();
    std::cout << "\n";
    c.attack(c.getName());
    d.takeDamage(2147483647);
    d.beRepaired(2147483647);
    c.printStatus();

    std::cout << "\n⚰️ Destruction order on exit ⚰️\n";
    return 0;
}
