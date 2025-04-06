#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {
private:
    std::string type;    // ��� ��� (� �� ����� �� ���, �� ��� ����������� �������, ��� ������ �� � ���)
    int quantity;        // ����������
    bool isSpoiled;      // ��������� ��� (������ ��� �����������)

public:
    Food(const std::string& type, int quantity, bool isSpoiled = false);

    // ������
    void spoil();                // ��� ��������
    void consume(int amount);    // ����������� ���

    // ������� � �������
    std::string getType() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    bool getIsSpoiled() const;
};

#endif // FOOD_H