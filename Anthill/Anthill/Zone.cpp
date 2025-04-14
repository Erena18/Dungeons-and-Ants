#include "Zone.h"

ZoneManager& ZoneManager::getInstance()
{
    static ZoneManager instance;
    return instance;
}
