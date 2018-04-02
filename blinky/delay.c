#include <stdint.h>
#include "delay.h"

//--------------------------------------------------
//--------- Delay Generating function --------------
void ms_delay(uint32_t msTime)
{
for (uint32_t i =0; i<msTime*4000; i++);
}	
//---------------------------------------------------

