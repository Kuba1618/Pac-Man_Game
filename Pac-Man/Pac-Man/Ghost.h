#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Ghost : public Object 
{
public:
	Ghost(int posX = 0, int posY = 0);
	~Ghost();
};
