#include "Projectile.hpp"

Projectile::Projectile(const unsigned long _id) : Entity::Entity(_id) {}

Projectile::Projectile(const unsigned long _id, Azimuth _or) : Entity::Entity(_id) {
    Entity::setOrientation(_or);
}

void Projectile::forward() {
    switch(orientation) {
        case North :
            goNorth(2);
            break;
        case East :
            goEast(2);
            break;
        case South :
            goSouth(2);
            break;
        case West:
            goWest(2);
            break;
    }
}
