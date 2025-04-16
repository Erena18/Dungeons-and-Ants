#include "Informers.h"

void Informer::subscribe(Role* role)
{
    if (role && std::find(subs.begin(), subs.end(), role) == subs.end()) {
        subs.push_back(role);
    }
}

void Informer::unsubscribe(Role* role)
{
    subs.erase(std::remove(subs.begin(), subs.end(), role), subs.end());
}

void Informer::notify(Ant& ant)
{
    for (Role* r : subs) {
        if (r) r->onNotify(ant);
    }
}
