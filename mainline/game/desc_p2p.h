#ifndef __INC_METIN_II_GAME_DESC_P2P__H__
#define __INC_METIN_II_GAME_DESC_P2P__H__

#include "desc.h"

class DESC_P2P : public DESC
{
	public:
		virtual ~DESC_P2P();

		virtual void	Destroy();
		virtual void	SetPhase(int iPhase);
		bool		Setup(LPFDWATCH _fdw, socket_t fd, const char * host, WORD wPort);
};

#endif
