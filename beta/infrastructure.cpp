#include "Infrastructure.h"
#include <iostream>

// ������� ����� Infrastructure
Infrastructure::Infrastructure(const std::string& name) : name(name) {}

void Infrastructure::update(const std::string& message) {
    std::cout << "[" << name << "] new message" << message << std::endl;
}

// Orphanage
Orphanage::Orphanage() : Infrastructure("priut") {}

void Orphanage::work() {
    // ������ ������ �������� ����
}

void Orphanage::eat() {
    // ������ ����������� �������� ������� �����
}

// Barracks
Barracks::Barracks() : Infrastructure("kazarma") {}

void Barracks::work() {
    // ������ ������ �������
}

void Barracks::eat() {
    // ������ ����������� �������� ��������
}

// CleaningCompany
CleaningCompany::CleaningCompany() : Infrastructure("cleaning company") {}

void CleaningCompany::work() {
    // ������ ������ ����������� ��������
}

void CleaningCompany::eat() {
    // ������ ����������� �������� ����������� ���������
}

// ConstructionCompany
ConstructionCompany::ConstructionCompany() : Infrastructure("construction company") {}

void ConstructionCompany::work() {
    // ������ ������ ������������ �����
}

void ConstructionCompany::eat() {
    // ������ ����������� �������� ������������ ������
}

// AphidPen
AphidPen::AphidPen() : Infrastructure("zagon dlya tli") {}

void AphidPen::work() {
    // ������ ������ ������ ��� ���
}

void AphidPen::eat() {
    // ������ ����������� �������� ������� ��� ���
}

// ResidentialHouse
ResidentialHouse::ResidentialHouse() : Infrastructure("Residential House") {}

void ResidentialHouse::work() {
    // ������ ������ ������ ����
}

void ResidentialHouse::eat() {
    // ������ ����������� �������� ����� �����
}