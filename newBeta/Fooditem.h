// FoodItem.h
#ifndef FOODITEM_H
#define FOODITEM_H

class FoodItem {
public:
    FoodItem(int amount);

    int getAmount() const;
    int getAge() const;

    void increaseAge();
    bool isSpoiled() const;
    void reduceAmount(int amountToReduce);

private:
    int amount;
    int age; // Возраст еды в днях
};

#endif // FOODITEM_H