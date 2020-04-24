#include "ResourceManager.h"
#include "Game.h"

int main(int argc, char const *argv[]) {
    ResourceManager resources;
    Game game(resources);
    game.start();
    while (!game.isFinished()) {
        game.play();
    }
    game.end();
}
