
#pragma once


#include <cmath>
#include <vector>

#include "kyo/frame_clock.h"
#include "kyo/common.h"
#include "player.h"
#include "platform.h"
#include "level.h"
#include "menu.h"
#include "enemy.h"
#include "editor.h"
#include "obstacle.h"
#include "kyo/entity/manager.h"

class HUD;


class Game {
private:

    sf::RenderWindow* window;

    FrameClock fc;

    sf::View view;
    sf::View hud_view;

    EntityManager em;

    Level* level;
    Player *player;
    Button start;
    HUD* hud;
    Menu menu;

    Editor* editor = NULL;

    Obstacle obstacle;

    void processEvents();

    /**
     * @brief Process game logic with the given change in time
     * from the last frame.
     *
     * @param delta
     */
    void update(float delta);

    /**
     * @brief Render a frame.
     */
    void render();

public:

    Game(const Game&) = delete;

    Game& operator=(const Game&) = delete;

    Game();

    ~Game();

    void run();

    Player& get_player() { return *player; }

    Level& get_level() { return *level; }

    EntityManager& get_entity_manager() { return em; }
};
