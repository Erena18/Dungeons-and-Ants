#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

// Базовый класс для всех зон
class Zone {
public:
    virtual ~Zone() = default;

    // Обновление состояния зоны (For instance: восстановление ресурсов или расширение)
    virtual void update() = 0;

    // Получен. типа зоны
    virtual std::string getType() const = 0;

    // Проверка простоты зоны
    virtual bool isEmpty() const { return false; }

    // Что будет, если муравей попал в зону
    virtual void onAntEnter() = 0;
};

// Пустая зона
class EmptyZone : public Zone {

public:
    std::string getType() const override { return "Empty"; }

    bool isEmpty() const override { return true; }

    void update() override {
        ++daysSinceLastUpdate;
        if (daysSinceLastUpdate >= 50) { //в тз 50 дней написано, поэтому пока 50 дней и будет
            // Зона обновляется и становится одной из трех случайных зон
            //std::cout << "Empty zone has been refreshed!" << std::endl;
            daysSinceLastUpdate = 0;
        }
    }

    void onAntEnter() override {
        //std::cout << "An ant entered an empty zone." << std::endl;

    }

private:
    int daysSinceLastUpdate = 0;
};

// Съестная зона
class FoodZone : public Zone {

public:
    FoodZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Food"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
            //std::cout << "Food zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant collected food. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No food left in this zone." << std::endl;
        }
    }

private:
    int capacity; // Вместимость еды

};

// Материальная зона
class MaterialZone : public Zone {

public:
    MaterialZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Material"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
            //std::cout << "Material zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant collected materials. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No materials left in this zone." << std::endl;
        }
    }

private:
    int capacity; // Вместимость материалов

};

// Пастбищная зона
class PastureZone : public Zone {


public:
    PastureZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Pasture"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
            //std::cout << "Pasture zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant grazed in the pasture. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No grazing available in this zone." << std::endl;
        }
    }

private:
    int capacity; // Вместимость корма
};

// Опасная зона
class DangerousZone : public Zone {


public:
    DangerousZone(int initialHealth, int maxHealth) : enemyHealth(initialHealth), maxHealth(maxHealth) {}

    std::string getType() const override { return "Dangerous"; }

    void update() override {
        static int daysSinceLastUpdate = 0;
        ++daysSinceLastUpdate;

        if (daysSinceLastUpdate % 5 == 0) {
            enemyHealth -= 10; // Уменьшение здоровья врага
            //std::cout << "Enemy health decreased to " << enemyHealth << "." << std::endl;

            if (enemyHealth <= 0) {
                //std::cout << "Enemy is critically weak. Expanding dangerous zone!" << std::endl;
                // Расширение опасной зоны
            }
        }

        if (enemyHealth >= maxHealth) {
            //std::cout << "Enemy reached max health. Expanding dangerous zone!" << std::endl;
            // Расширение опасной зоны
        }
    }

    void onAntEnter() override {
        //std::cout << "An ant entered a dangerous zone and died!" << std::endl;
    }

private:
    int enemyHealth;
    int maxHealth;
};

// Мусорная зона
class GarbageZone : public Zone {


public:
    GarbageZone(int initialGarbage) : garbageAmount(initialGarbage) {}

    std::string getType() const override { return "Garbage"; }

    void update() override {
        // Логика обновления мусорной зоны
    }

    void onAntEnter() override {
        //std::cout << "An ant entered a garbage zone." << std::endl;
    }

private:
    int garbageAmount;
};

int main() {
    srand(time(0));

    std::vector<std::shared_ptr<Zone>> zones;
    zones.push_back(std::make_shared<EmptyZone>());
    zones.push_back(std::make_shared<FoodZone>(5));
    zones.push_back(std::make_shared<DangerousZone>(50, 100));

    for (auto& zone : zones) {
        zone->update();
        zone->onAntEnter();
    }

    return 0;
}