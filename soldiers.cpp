#include <iostream>
#include <string>
#include <cstdlib> // для rand()
#include <ctime>   // для srand()

class Soldier {
private:
    int health;       
    int age;          
    int experience;   
    bool isAlive;     

public:
    
    Soldier(int initialHealth = 80, int initialAge = 40)
        : health(initialHealth), age(initialAge), experience(0), isAlive(true) {}

    
    int getHealth() const { return health; }

    
    int getAge() const { return age; }

    
    int getExperience() const { return experience; }

    
    bool checkIfAlive() const { return isAlive; }

    //ежедневное уменьшения здоровья
    void dailyHealthLoss() {
        if (isAlive) {
            health -= (rand() % 3 + 1); // уменьшаем здоровье на 1-3 единицы
            if (health <= 0) {
                isAlive = false;
                //std::cout << "Soldier has died due to health loss\n";
            }
        }
    }

    //участие в бою
    void engageInBattle(int enemyHealth) {
        if (!isAlive) {
            //std::cout << "This soldier is already dead and can`t fight\n";
            return;
        }

        //std::cout << "Soldier engages in battle with an enemy (Enemy Health: " << enemyHealth << ")\n";

        while (health > 0 && enemyHealth > 0) {
            int soldierDamage = rand() % 11 + 5; // урон солдата: 5-15 единиц
            int enemyDamage = rand() % 11 + 5;  // урон врага: 5-15 единиц

            //Наносим урон врагу
            enemyHealth -= soldierDamage;
            //std::cout << "Soldier deals " << soldierDamage << " damage. Enemy Health: " << enemyHealth << "\n";

            //Если враг еще жив, он наносит урон солдату
            if (enemyHealth > 0) {
                health -= enemyDamage;
                //std::cout << "Enemy deals " << enemyDamage << " damage. Soldier Health: " << health << "\n";
            }
        }

        // Проверка результата боя
        if (health <= 0) {
            isAlive = false;
            //std::cout << "Soldier has been killed in battle\n";
        } else {
            experience++; // Увеличиваем опыт за победу
            health += 25; // Восстанавливаем здоровье после победы
            //std::cout << "Soldier has won the battle! Experience: " << experience << ", Health: " << health << "\n";
        }
    }

    //метод патрулирования территории
    void patrolTerritory(bool dangerousZoneFound) {
        if (!isAlive) {
            //std::cout << "This soldier is already dead and can`t patrol\n";
            return;
        }

        if (dangerousZoneFound) {
            //std::cout << "Dangerous zone detected! Soldier calls for reinforcements\n";
            // Здесь можно добавить вызов подкрепления (например, создать новых солдат), но пока давайте без этого
        } else {
            //std::cout << "Territory is safe. Soldier continues patrolling.\n";
        }
    }

    //Метод для отступления
    void retreat() {
        if (!isAlive) {
            //std::cout << "This soldier is already dead and can`t retreat\n";
            return;
        }

        if (health < 30) {
            int retreatSuccessChance = rand() % 2; // 50% шанс успешного отступления
            if (retreatSuccessChance == 1) {
                //std::cout << "Soldier successfully retreats\n";
            } else {
                //std::cout << "Soldier fails to retreat and dies.\n";
                isAlive = false;
            }
        } else {
            //std::cout << "Soldier's health is sufficient. No need to retreat\n";
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    //Создаем солдата
    Soldier soldier;

    //Ежедневное уменьшение здоровья
    soldier.dailyHealthLoss();
    std::cout << "Soldier's health after daily loss: " << soldier.getHealth() << "\n";

    soldier.engageInBattle(50);

    soldier.patrolTerritory(true);

    soldier.retreat();

    return 0;
}