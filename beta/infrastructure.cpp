#include "Infrastructure.h"
#include <iostream>

// Базовый класс Infrastructure
Infrastructure::Infrastructure(const std::string& name) : name(name) {}

void Infrastructure::update(const std::string& message) {
    std::cout << "[" << name << "] new message" << message << std::endl;
}

// Orphanage
Orphanage::Orphanage() : Infrastructure("priut") {}

void Orphanage::work() {
    // Логика работы детского дома
}

void Orphanage::eat() {
    // Логика потребления ресурсов детским домом
}

// Barracks
Barracks::Barracks() : Infrastructure("kazarma") {}

void Barracks::work() {
    // Логика работы казармы
}

void Barracks::eat() {
    // Логика потребления ресурсов казармой
}

// CleaningCompany
CleaningCompany::CleaningCompany() : Infrastructure("cleaning company") {}

void CleaningCompany::work() {
    // Логика работы клининговой компании
}

void CleaningCompany::eat() {
    // Логика потребления ресурсов клининговой компанией
}

// ConstructionCompany
ConstructionCompany::ConstructionCompany() : Infrastructure("construction company") {}

void ConstructionCompany::work() {
    // Логика работы строительной фирмы
}

void ConstructionCompany::eat() {
    // Логика потребления ресурсов строительной фирмой
}

// AphidPen
AphidPen::AphidPen() : Infrastructure("zagon dlya tli") {}

void AphidPen::work() {
    // Логика работы загона для тли
}

void AphidPen::eat() {
    // Логика потребления ресурсов загоном для тли
}

// ResidentialHouse
ResidentialHouse::ResidentialHouse() : Infrastructure("Residential House") {}

void ResidentialHouse::work() {
    // Логика работы жилого дома
}

void ResidentialHouse::eat() {
    // Логика потребления ресурсов жилым домом
}