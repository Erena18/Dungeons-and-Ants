// InformerCleaner.h
#ifndef INFORMERCLEANER_H
#define INFORMERCLEANER_H

#include "Informer.h"
#include <vector>

class Role;

class InformerCleaner : public Informer {
public:
    void subscribe(Role* role) override;
    void unsubscribe(Role* role) override;
    void notify(const std::string& message) override;

private:
    std::vector<Role*> subscribers;
};

#endif // INFORMERCLEANER_H