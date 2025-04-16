class Ant
{
public:
    Ant();
    Ant(int initHp, int initAge, std::unique_ptr<Role> initRole);

    int getHp() const { return hp; }
    int getAge() const { return age; }

    bool isAlive() const;
    void growth();
    void updateRole();
    void loseHpEndDay();
    void loseHp(int damageHp);
    void restoreHp(int point);
    void die();
    void move(); //движение

    void subscribeToInformer(Informer* informer);
    void unsubscribeFromInformer();

    // Виртуальные методы
    virtual void Work();
    virtual void Eat(Food& food);

    void draw(sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition() const;

    // метод установки цели))
    void setTarget(const sf::Vector2f& newTarget);

private:
    int hp, age;
    std::unique_ptr<Role> role;
    Informer* currentInformer = nullptr;
    CollectorInformer* collectorInformer;
    NannyInformer* nannyInformer;
    CleanerInformer* cleanerInformer;
    SoldierInformer* soldierInformer;

    sf::CircleShape shape;
    sf::Vector2f position;

    // Новые переменные для движения
    sf::Vector2f velocity;
    sf::Vector2f target;
    float ant_speed = 1.0f; // Скорость муравья 
    bool has_target = false;
};