#include <iostream>
#include <cstdlib> // для rand()
#include <ctime>   // для srand()

class Enemy {
private:
    int health;       
    int age;          
    bool isAlive;     

public:
    
    Enemy(int initialHealth = 40, int initialAge = 0)
        : health(initialHealth), age(initialAge), isAlive(true) {}

    int getHealth() const { return health; }

    int getAge() const { return age; }

    bool checkIfAlive() const { return isAlive; }

    void growOlder() {
        if (isAlive) {
            age++;
            if (age > 30) {
                isAlive = false;
                //std::cout << "Enemy has died of old age\n";
            }
        }
    }

    //атака
    int attack() const {
        if (!isAlive) {
            //std::cout << "This enemy is already dead and can`t attack\n";
            return 0;
        }
        int damage = rand() % 11 + 5; //Урон: случайное значение от 5 до 15
        //std::cout << "Enemy attacks with " << damage << " damage\n";
        return damage;
    }

    // Метод получения урона
    void takeDamage(int damage) {
        if (!isAlive) {
            //std::cout << "This enemy is already dead and cannot take damage\n";
            return;
        }

        health -= damage;
        if (health <= 0) {
            isAlive = false;
            //std::cout << "Enemy has been killed\n";
        } else {
            //std::cout << "Enemy's health after damage: " << health << "\n";
        }
    }

    // Метод для восстановления здоровья (при победе над муравьём)
    void restoreHealth(int amount) {
        if (isAlive) {
            health += amount;
            if (health > 40) {
                health = 40; // Здоровье не может превышать 40
            }
            //std::cout << "Enemy restores health to " << health << ".\n";
        }
    }

    //Метод проверки расширения опасной зоны
    bool shouldExpandDangerZone() const {
        return health == 40 || health <= 10; // Расширение при макс. здоровье или критическом здоровье
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Enemy enemy;

    enemy.growOlder();

    int damage = enemy.attack();

    enemy.takeDamage(damage);

    if (enemy.shouldExpandDangerZone()) {
        //std::cout << "Danger zone should expand.\n";
    }

    enemy.restoreHealth(20);

    return 0;
}