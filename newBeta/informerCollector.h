#ifndef INFORMER_COLLECTOR_H
#define INFORMER_COLLECTOR_H

#include <vector>
#include <string>

class Collector;

class InformerCollector {
public:
    void subscribe(Collector* collector);
    void unsubscribe(Collector* collector);
    void notifyCollectors(const std::string& message);

private:
    std::vector<Collector*> collectors;
};
#endif