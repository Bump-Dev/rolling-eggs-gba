#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_egg.h"
#include "bn_backdrop.h"
#include "bn_display.h"
#include "bn_random.h"

const int NUM_EGGS = 10;
const int window_x = 240;
const int window_y = 160;

bn::random random;

class Egg
{
public:
    int x_offset = 6; // 8
    int y_offset = 6; // 6
    int x_direction = random.get_int(0, 1) * 2 - 1;
    int y_direction = random.get_int(0, 1) * 2 - 1;
    int speed = 1;
    bn::sprite_ptr sprite = bn::sprite_items::egg.create_sprite(
        random.get_unbiased_int((-window_x / 2) + x_offset, (window_x / 2) - x_offset),
        random.get_unbiased_int((-window_y / 2) + y_offset, (window_y / 2) - y_offset));

    void move()
    {
        if (sprite.x() >= window_x / 2 - x_offset)
            x_direction = -1;
        else if (sprite.x() <= -window_x / 2 + x_offset)
            x_direction = 1;
        if (sprite.y() >= window_y / 2 - y_offset)
            y_direction = -1;
        else if (sprite.y() <= -window_y / 2 + y_offset)
            y_direction = 1;

        if (sprite.rotation_angle() >= 360)
            sprite.set_rotation_angle(0);
        sprite.set_rotation_angle(sprite.rotation_angle() + 10);
        sprite.set_x(sprite.x() + speed * x_direction);
        sprite.set_y(sprite.y() + speed * y_direction);
    }
};

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 19, 0));

    Egg eggs[NUM_EGGS];
    // for (int i = 0; i < NUM_EGGS; ++i)
    // {
    // eggs[i].sprite.set_x(eggs[i].sprite.x() + 32 * i);
    // eggs[i].sprite.set_y(eggs[i].sprite.y() + 32 * i);
    // }

    while (true)
    {
        for (int i = 0; i < NUM_EGGS; ++i)
        {
            eggs[i].move();
        }
        bn::core::update();
    }
}
