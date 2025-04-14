#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  

class Enemy {
private:
    int health;
    int age;

public:
    Enemy(int initialHealth = 40) : health(initialHealth) {}

    int getHealth() const { return health; }

    bool isAlive() const { return health > 0; }

    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            //std::cout << "Enemy has been defeated!\n";
        }
    }

    int attack() const {
        int damage = rand() % 11 + 5; 
        //std::cout << "Enemy attacks with " << damage << " damage\n";
        return damage;
    }
};

class Soldier {
private:
    int health;       
    int experience;   
    bool isAlive;    

public:
    Soldier(int initialHealth = 80) : health(initialHealth), experience(0), isAlive(true) {}

    int getHealth() const { return health; }

    bool checkIfAlive() const { return isAlive; }

    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            isAlive = false;
            //std::cout << "Soldier has died in a battle\n";
        }
    }

    int attack() const {
        int damage = rand() % 11 + 5;
        //std::cout << "Soldier attacks with " << damage << " damage\n";
        return damage;
    }

    void gainExperience() {
        experience++;
        //std::cout << "Soldier gained experience! Total experience: " << experience << "\n";
    }

    void restoreHealth(int amount) {
        if (isAlive) {
            health += amount;
            if (health > 80) {
                health = 80; //eto est' max health
            }
            //std::cout << "Soldier restores health to " << health << ".\n";
        }
    }

    // Метод для сражения с врагом
    void engageInBattle(Enemy& enemy) {
        if (!isAlive) {
            //std::cout << "This soldier is already dead and cannot fight\n";
            return;
        }

        //std::cout << "Soldier engages in battle with an enemy (Enemy Health: " << enemy.getHealth() << ").\n";

        while (isAlive && enemy.isAlive()) {
            int soldierDamage = attack(); //Солдат атакует врага
            enemy.takeDamage(soldierDamage);

            if (enemy.isAlive()) {
                int enemyDamage = enemy.attack(); //Враг атакует солдата
                takeDamage(enemyDamage);
            }
        }

        if (isAlive) {
            gainExperience();          //Увеличиваем опыт за победу
            restoreHealth(25);         //Восстанавливаем здоровье
            //std::cout << "Soldier has won the battle! Experience: " << experience << ", Health: " << health << "\n";
        }
    }
};

class AntHill {
private:
    int strength;                  
    std::vector<Soldier> soldiers; //Список солдат в муравейнике

public:
    AntHill(int initialStrength = 200) : strength(initialStrength) {}

    int getStrength() const { return strength; }

    void addSoldier(const Soldier& soldier) {
        soldiers.push_back(soldier);
        //std::cout << "A new soldier has joined the anthill\n";
    }

    void callSoldiersForDefense(Enemy& enemy) {
        //std::cout << "The anthill is under attack! Calling soldiers for defense\n";

        for (auto& soldier : soldiers) {
            if (soldier.checkIfAlive()) {
                soldier.engageInBattle(enemy);
                if (!enemy.isAlive()) {
                    //std::cout << "The enemy has been defeated. The anthill is safe.\n";
                    break;
                }
            }
        }

        if (enemy.isAlive()) {
            //std::cout << "All soldiers have fallen. The anthill is in danger!!!\n";
        }
    }

    void dailyMaintenance() {
        strength -= (rand() % 2 + 1); //Ежедневное уменьшение прочности
        if (strength <= 0) {
            //std::cout << "The anthill has collapsed.\n";
        } else {
            //std::cout << "Anthill strength after daily maintenance: " << strength << "\n";
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); 

    AntHill antHill;

    antHill.addSoldier(Soldier());
    antHill.addSoldier(Soldier());

    Enemy enemy;

    antHill.dailyMaintenance();

    antHill.callSoldiersForDefense(enemy);

    return 0;
}