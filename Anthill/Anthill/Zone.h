#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

// Базовый класс для всех зон
class Zone 
{
public:
    virtual ~Zone() = default;

    // Обновление состояния зоны (For instance: восстановление ресурсов или расширение)
    virtual void update() = 0;

    // Получен. типа зоны
    virtual string getType() const = 0;

    // Проверка простоты зоны
    virtual bool isEmpty() const { return false; }

    // Что будет, если муравей попал в зону
    virtual void onAntEnter() = 0;
};