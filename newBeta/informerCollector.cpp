#include "InformerCollector.h"
#include "Collector.h"
#include <algorithm>

void InformerCollector::subscribe(Collector* collector) {
    collectors.push_back(collector);
}

void InformerCollector::unsubscribe(Collector* collector) {
    collectors.erase(std::remove(collectors.begin(), collectors.end(), collector), collectors.end());
}

void InformerCollector::notifyCollectors(const std::string& message) {
    for (Collector* collector : collectors) {
        collector->receiveNotification(message);
    }
}