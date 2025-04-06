// MaterialItem.h
#ifndef MATERIALITEM_H
#define MATERIALITEM_H

class MaterialItem {
public:
    MaterialItem(int amount);

    int getAmount() const;
    int getAge() const;

    void increaseAge();
    bool isSpoiled() const;
    void reduceAmount(int amountToReduce);

private:
    int amount;
    int age; // Возраст материалов в днях
};

#endif // MATERIALITEM_H