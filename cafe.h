#pragma once
#include <string>
#include <map>

// Класс для представления съестной зоны
class FoodZone {
public:
    FoodZone();

    // Метод для сбора еды
    int collectFood(int amount);

    // Метод для пополнения еды (у Насти в тз каждые 50 дней)
    void replenishFood();

    // Метод для проверки, доступна ли еда
    bool hasFood() const;

    // Получения текущего количества еды
    int getFoodAmount() const;

private:
    std::string zoneType; // Тип зоны ("food")
    int capacity;         // Максимальная вместимость еды
    int currentFood;      // Текущее количество еды
};