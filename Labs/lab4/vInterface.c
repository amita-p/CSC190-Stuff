#include "lab4.h"

struct vInterface initVInterface(int (*sS)(int), int (*sG)(int), int (*sP)(int))
{
	struct vInterface v={sS,sG,sP};
	return v;
}
