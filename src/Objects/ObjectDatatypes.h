#ifndef OBJECT_DATATYPES_CLASS
#define OBJECT_DATATYPES_CLASS

#include <vector>
#include "WorldSpaceParticle.h"


struct worldContainers {
	std::vector<WorldSpaceParticle> worldParticles;
	std::vector<WorldSpaceStatic> worldStatics;
};


#endif
