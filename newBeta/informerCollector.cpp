// InformerCollector.cpp
#include "InformerCollector.h"
#include "Role.h"

void InformerCollector::subscribe(Role* role) {
    subscribers.push_back(role);
}

void InformerCollector::unsubscribe(Role* role) {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), role), subscribers.end());
}

void InformerCollector::notify(const std::string& message) {
    for (auto role : subscribers) {
        role->receiveNotification(message);
    }
}