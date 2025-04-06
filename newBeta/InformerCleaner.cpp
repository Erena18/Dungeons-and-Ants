#include "InformerCleaner.h"
#include "Cleaner.h"
#include <algorithm>

void InformerCleaner::subscribe(Cleaner* cleaner) {
    cleaners.push_back(cleaner);
}

void InformerCleaner::unsubscribe(Cleaner* cleaner) {
    cleaners.erase(std::remove(cleaners.begin(), cleaners.end(), cleaner), cleaners.end());
}

void InformerCleaner::notifyCleaners(const std::string& message) {
    for (Cleaner* cleaner : cleaners) {
        cleaner->receiveNotification(message);
    }
}