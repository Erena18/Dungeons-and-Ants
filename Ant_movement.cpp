#include "Ant.h"
#include <cmath>
#include <cstdlib>

Ant::Ant() : hp(100), age(0), role(nullptr), velocity(0.f, 0.f), speed(2.0f) {
    shape.setRadius(5.f);
    shape.setOrigin(5.f, 5.f);
    shape.setFillColor(Color::White);
}

Ant::Ant(int initHp, int initAge, unique_ptr<Role> initRole)
    : hp(initHp), age(initAge), role(move(initRole)), velocity(0.f, 0.f), speed(2.0f) {
    shape.setRadius(5.f);
    shape.setOrigin(5.f, 5.f);

    if (dynamic_cast<Builder*>(role.get())) {
        shape.setFillColor(Color::Blue);
    } else if (dynamic_cast<Collector*>(role.get())) {
        shape.setFillColor(Color::Green);
    } else if (dynamic_cast<Child*>(role.get())) {
        shape.setFillColor(Color::Magenta);
    } else if (dynamic_cast<Nanny*>(role.get())) {
        shape.setFillColor(Color::Cyan);
    } else if (dynamic_cast<Soldier*>(role.get())) {
        shape.setFillColor(Color::Red);
    } else {
        shape.setFillColor(Color::White);
    }
}

void Ant::move() {
    if (hp <= 0 || !has_target) return;

    // Вычисляем направление к цели
    float dx = target.x - position.x;
    float dy = target.y - position.y;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance > 5.f) {
        // Нормализуем вектор направления и умножаем на скорость
        velocity.x = (dx / distance) * speed;
        velocity.y = (dy / distance) * speed;
    } else {
        // Если цель достигнута, останавливаемся
        velocity.x = 0;
        velocity.y = 0;
        has_target = false;
    }

    // Обновляем позицию
    position.x += velocity.x;
    position.y += velocity.y;
    shape.setPosition(position);
}

void Ant::draw(RenderWindow& window) {
    window.draw(shape);
}

void Ant::setPosition(Vector2f pos) {
    position = pos;
    shape.setPosition(position);
}

bool Ant::isAlive() const {
    return hp > 0;
}

void Ant::growth() {
    age++;
    updateRole();
    if (hp <= 0 || age > 100) {
        die();
    }
}

void Ant::die() {
    delete this;
}

void Ant::updateRole() {
    if ((role != nullptr) && (dynamic_cast<Queen*>(role.get()))) {
        return;
    }

    Informer* previousInformer = currentInformer;
    if (age < 20) {
        role = make_unique<Child>();
    } else if ((age >= 20) && (age < 39)) {
        role = make_unique<Nanny>();
    } else if ((age >= 40) && (age < 59)) {
        int check = rand() % 2;
        if (check == 0) {
            role = make_unique<Soldier>();
        } else {
            role = make_unique<Heardsant>();
        }
    } else if ((age >= 60) && (age < 79) && (dynamic_cast<Soldier*>(role.get()))) {
        role = make_unique<Builder>();
    } else if ((age >= 60) && (age < 79) && (dynamic_cast<Heardsant*>(role.get()))) {
        role = make_unique<Collector>();
    } else if ((age >= 80) && (age < 100)) {
        role = make_unique<Cleaner>();
    } else if (age >= 100) {
        if (currentInformer) {
            currentInformer->unsubscribe(role.get());
        }
        die();
        return;
    }

    if (previousInformer) {
        previousInformer->unsubscribe(role.get());
    }
}

void Ant::loseHpEndDay() {
    hp -= rand() % 11;
    if (hp < 0) {
        die();
    }
}

void Ant::loseHp(int damageHp) {
    hp -= damageHp;
    if (hp < 0) {
        die();
    }
}

void Ant::restoreHp(int point) {
    hp += point;
    if (hp > 100) {
        hp = 100;
    }
}

void Ant::subscribeToInformer(Informer* informer) {
    if (currentInformer) {
        currentInformer->unsubscribe(role.get());
    }
    currentInformer = informer;
    if (currentInformer) {
        currentInformer->subscribe(role.get());
    }
}

void Ant::unsubscribeFromInformer() {
    if (currentInformer) {
        currentInformer->unsubscribe(role.get());
        currentInformer = nullptr;
    }
}

void Ant::Work() {
    if (role != nullptr) {
        role->Work();
    }
}

void Ant::Eat(Food& food) {
    if (role != nullptr) {
        role->Eat(*this, food);
    }
}