#include "Gameplay.h"
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Gameplay game;
    game.play();
    return 0;
}
