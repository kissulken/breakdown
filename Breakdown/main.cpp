#include "src/Gameplay.h"
#include "time.h"
#include <iostream>

int main()
{
	srand(time_t(NULL));
	Gameplay gp;
	gp.Run();
	return 0;
}
