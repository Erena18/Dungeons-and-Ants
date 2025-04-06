// Garbage.h
#ifndef GARBAGE_H
#define GARBAGE_H

class Garbage {
public:
    enum class Type {
        RottenFood,
        RottenMaterial,
        Corpse
    };

    Garbage(Type type, int weight);

    Type getType() const;
    int getWeight() const;

private:
    Type type;
    int weight;
};

#endif // GARBAGE_H