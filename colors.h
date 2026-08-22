#ifndef COLORS_H
#define COLORS_H
//#################################################################################
                 //NOTE: ONE OF THIS FLAGS MUST STAY BEFORE EVERY PRINT!!!
//#################################################################################
/// DEFINING COLORS FOR PRINTF
#define _BLACK printf("\e[0;30m");
#define _RED printf("\e[0;31m");	
#define _GREEN printf("\e[0;32m");	
#define _YELLOW printf("\e[0;33m");	
#define _BLUE printf("\e[0;34m");
#define _PURPLE printf("\e[0;35m");
#define _CYAN printf("\e[0;36m");
#define _WHITE printf("\e[0;37m");

//use RED for errors, WHITE for input words, YELLOW for output result
#endif
