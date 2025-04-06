#ifndef GARBAGE_H
#define GARBAGE_H

#include <string>

class Garbage {
private:
    std::string type;  // ��� ������ (����������� ��� ��� ����)
    int weight;        // ��� ������

public:
    Garbage(const std::string& type, int weight);

    // ������� � �������
    std::string getType() const;
    int getWeight() const;
    void setWeight(int weight);
};

#endif // GARBAGE_H