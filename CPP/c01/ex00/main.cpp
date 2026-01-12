#include "Zombie.hpp"
#include "Zombie.h"

int	main()
{
	Zombie	*zombie;
	Zombie	*zomb;

	zombie = new_zombie("Jason");
	zombie->announce();
	randomChump("Nick");
	delete zombie;
	return 0;
}
