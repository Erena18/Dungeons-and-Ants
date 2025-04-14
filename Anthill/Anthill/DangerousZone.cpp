#include "DangerousZone.h"

void DangerousZone::update()
{
    static int daysSinceLastUpdate = 0;
    ++daysSinceLastUpdate;
    if (daysSinceLastUpdate % 5 == 0) {
        enemyHealth -= 10;
        if (enemyHealth <= 0) {
                //std::cout << "Enemy is critically weak. Expanding dangerous zone!" << std::endl;
                // Расширение опасной зоны
            }
        }

        if (enemyHealth >= maxHealth) {
            //std::cout << "Enemy reached max health. Expanding dangerous zone!" << std::endl;
            // Расширение опасной зоны
        }
}
