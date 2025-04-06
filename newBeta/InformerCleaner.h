#ifndef INFORMER_CLEANER_H
#define INFORMER_CLEANER_H

#include <vector>
#include <string>

class Cleaner;

class InformerCleaner {
public:
    void subscribe(Cleaner* cleaner);
    void unsubscribe(Cleaner* cleaner);
    void notifyCleaners(const std::string& message);

private:
    std::vector<Cleaner*> cleaners;
};

#endif // INFORMER_CLEANER_H