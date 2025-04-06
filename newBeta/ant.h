#ifndef ANT_H
#define ANT_H

#include "Role.h"
#include "Food.h"
#include <memory>

class InformerAnt;

class Ant {
public:
    Ant(int initHp, int initAge, std::unique_ptr<Role> initRole);
    ~Ant(); // ��������� ����������

    int getHp() const { return hp; }
    int getAge() const { return age; }

    void growth();          // ����������� �������
    void updateRole();      // ��������� ����, ���� ����������
    void loseHpEndDay();    // ������ �������� � ����� ���
    void loseHp(int damageHp);
    void restoreHp(int point);
    void die();

    void Work();
    void Eat(Food& food);

    std::unique_ptr<Role>& getRole() { return role; }

private:
    int hp, age;
    bool isAlive;
    std::unique_ptr<Role> role;
    std::unique_ptr<InformerAnt> informer;
};

#endif // ANT_H