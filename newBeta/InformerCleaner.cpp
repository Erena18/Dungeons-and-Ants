// InformerCleaner.cpp
#include "InformerCleaner.h"
#include "Role.h"

void InformerCleaner::subscribe(Role* role) {
    subscribers.push_back(role);
}

void InformerCleaner::unsubscribe(Role* role) {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), role), subscribers.end());
}

void InformerCleaner::notify(const std::string& message) {
    for (auto role : subscribers) {
        role->receiveNotification(message);
    }
}