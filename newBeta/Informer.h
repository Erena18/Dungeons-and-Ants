// Informer.h
#ifndef INFORMER_H
#define INFORMER_H

#include <string>
#include <vector>

class Role;

class Informer {
public:
    virtual ~Informer() {}
    virtual void subscribe(Role* role) = 0;
    virtual void unsubscribe(Role* role) = 0;
    virtual void notify(const std::string& message) = 0;
};

#endif // INFORMER_H