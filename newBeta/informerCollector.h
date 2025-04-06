// InformerCollector.h
#ifndef INFORMERCOLLECTOR_H
#define INFORMERCOLLECTOR_H

#include "Informer.h"
#include <vector>

class Role;

class InformerCollector : public Informer {
public:
    void subscribe(Role* role) override;
    void unsubscribe(Role* role) override;
    void notify(const std::string& message) override;

private:
    std::vector<Role*> subscribers;
};

#endif // INFORMERCOLLECTOR_H