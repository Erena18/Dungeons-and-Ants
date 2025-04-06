#ifndef GARBAGE_H
#define GARBAGE_H

#include <string>

class Garbage {
private:
    std::string type;  // Тип мусора (испорченная еда или труп)
    int weight;        // Вес мусора

public:
    Garbage(const std::string& type, int weight);

    // Геттеры и сеттеры
    std::string getType() const;
    int getWeight() const;
    void setWeight(int weight);
};

#endif // GARBAGE_H