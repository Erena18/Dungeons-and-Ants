#include "Anthill.h"

static Anthill* s_instance = nullptr;

Anthill::Anthill(GameDataRef data) :_data(data),
maxPopulation(500), durability(200), naturalDecayMin(1), naturalDecayMax(2)
{
    updateRadius();
    _nestCircle.setFillColor(Color(139, 69, 19));
}

Anthill& Anthill::getInstance(GameDataRef data)
{
    if (s_instance == nullptr) {
        s_instance = new Anthill(data);
    }
    return *s_instance;
}

Anthill& Anthill::getInstance()
{
    return *s_instance;
}

void Anthill::drawAnthill()
{
    _data->window.draw(_nestCircle);
}

void Anthill::drawAllAnts(RenderWindow& window)
{
    for (unique_ptr<Ant>& ant : ants)
    {
        ant->draw(window);
    }
}

void Anthill::spawnAnthill(float x, float y)
{
    _nestCircle.setPosition(x, y);
    _nestCircle.setOrigin(_nestCircle.getRadius(), _nestCircle.getRadius());
}

void Anthill::grow(float amount)
{
    radius += amount;
    _nestCircle.setRadius(radius);
    _nestCircle.setOrigin(radius, radius);
}

void Anthill::setCapacity(int newCapacity)
{
    curCapacity = newCapacity;
    updateRadius();
}

void Anthill::addAnt(unique_ptr<Ant> ant) 
{
    if (ants.size() >= curCapacity) return;
    ants.push_back(std::move(ant));
}

void Anthill::addFood(int amount) 
{
    food.addFood(amount);
}

void Anthill::addMaterials(int amount) 
{
    materials.addMaterial(amount);
}

Food& Anthill::getFood() 
{
    return food;
}

Materials& Anthill::getMaterials() 
{
    return materials;
}

Warehouse& Anthill::getWarehouse() 
{
    return warehouse;
}

AphidManager& Anthill::getAphidManager()
{
    return aphidManager;
}

void Anthill::repair(int amount) 
{
    int materialsAvailable = materials.getAmount();
    int materialsToUse = min(amount, materialsAvailable);

    if (materialsToUse > 0) 
    {
        materials.use(materialsToUse);
        durability += materialsToUse;
        maxPopulation = 12 + ((durability - 200) / 25) * 5;
    }
}

void Anthill::receiveDamage(int amount) 
{
    durability -= amount;
    if (durability < 0) 
        durability = 0;
    maxPopulation = 12 + ((durability - 200) / 25) * 5;
}

void Anthill::dailyUpdate() 
{
    int decay = naturalDecayMin + rand() % (naturalDecayMax - naturalDecayMin + 1);
    receiveDamage(decay);
    
    for (unique_ptr<Ant>& ant : ants) 
    {
        ant->growth();
        ant->Work();
        ant->Eat(food);
    }

    removeDeadAnts();
    warehouse.dailyUpdate();
    food.dailyUpdate();
    materials.dailyUpdate();

    /*if (GarbageManager::getInstance().getGarbageList().size() > 10)
    {
        CleanerInformer* cleanerInformer = getInformer();
        if (cleanerInformer)
        {
            cleanerInformer->notify();
        }
    }*/
}

Vector2f Anthill::getCenter() const
{
    return _nestCircle.getPosition();
}

void Anthill::updateRadius()
{
    float radius = curCapacity * radiusPerUnit;
    _nestCircle.setRadius(radius);
    _nestCircle.setOrigin(radius, radius);
}

void Anthill::removeDeadAnts()
{
    for (size_t i = 0; i < ants.size(); )
    {
        if (!ants[i]->isAlive())
        {
            GarbageManager::getInstance().addGarbage(Garbage::Type::Corpse, 1);
            ants.erase(ants.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}