#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {
private:
    std::string type;    // Тип еды (я хз нужно ли это, но мое воображение сказало, что почему бы и нет)
    int quantity;        // Количество
    bool isSpoiled;      // Состояние еды (свежая или испорченная)

public:
    Food(const std::string& type, int quantity, bool isSpoiled = false);

    // Методы
    void spoil();                // Еда портится
    void consume(int amount);    // Потребление еды

    // Геттеры и сеттеры
    std::string getType() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    bool getIsSpoiled() const;
};

#endif // FOOD_H