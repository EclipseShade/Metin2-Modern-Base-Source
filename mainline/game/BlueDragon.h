#ifndef __BLUE_DRAGON__H
#define __BLUE_DRAGON__H

extern int BlueDragon_StateBattle (LPCHARACTER);
extern time_t UseBlueDragonSkill (LPCHARACTER, unsigned int);
extern int BlueDragon_Damage (LPCHARACTER me, LPCHARACTER attacker, int dam);

#endif
