#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Anthill.h"
#include "Collector.h"
#include "Cleaner.h"

int main() {
    // ������������� ���������� ��������� �����
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // �������� �����������
    Anthill anthill("Anthill #1");

    // ���������� ���������
    for (int i = 0; i < 5; ++i) {
        Collector* collector = new Collector(&anthill);
        anthill.addCollector(collector);
    }

    // ������������� ������ ����������� � ������� 30 ����
    for (int day = 1; day <= 30; ++day) {
        std::cout << "\nDay " << day << ":\n";
        anthill.dailyUpdate();

        // �� 10-� ���� �������� ��������� ����� �����
        if (day == 10) {
            std::cout << "Attempting to build a new warehouse...\n";
            anthill.buildWarehouse();
        }

        // �� 20-� ���� �������� ��������� ����������� �����
        if (day == 20) {
            std::cout << "Attempting to expand the central warehouse...\n";
            anthill.expandCentralWarehouse();
        }
    }

    return 0;
}