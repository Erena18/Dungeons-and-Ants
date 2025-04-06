#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include <string>
#include "Observer.h"

class Infrastructure : public Observer {
protected:
    std::string name;

public:
    Infrastructure(const std::string& name);
    virtual ~Infrastructure() {}

    virtual void work() = 0;
    virtual void eat() = 0;

    // Реализация паттерна Наблюдатель
    void update(const std::string& message) override;
};

// Классы-наследники инфраструктуры

class Orphanage : public Infrastructure {
public:
    Orphanage();
    void work() override;
    void eat() override;
};

class Barracks : public Infrastructure {
public:
    Barracks();
    void work() override;
    void eat() override;
};

class CleaningCompany : public Infrastructure {
public:
    CleaningCompany();
    void work() override;
    void eat() override;
};

class ConstructionCompany : public Infrastructure {
public:
    ConstructionCompany();
    void work() override;
    void eat() override;
};

class AphidPen : public Infrastructure {
public:
    AphidPen();
    void work() override;
    void eat() override;
};

class ResidentialHouse : public Infrastructure {
public:
    ResidentialHouse();
    void work() override;
    void eat() override;
};

#endif // INFRASTRUCTURE_H