/*
  Copyright 2009-2010, Ifcaro, jimmikaelkael & Polo
  Copyright 2006-2008 Polo
  Licenced under Academic Free License version 3.0
  Review OpenUsbLd README & LICENSE files for further details.
  
  Some parts of the code are taken from HD Project by Polo
*/

#ifndef IOPMGR_H
#define IOPMGR_H

#define RESET_ARG_MAX	79

struct _iop_reset_pkt {
	struct t_SifCmdHeader header;
	int	arglen;
	int	mode;
	char	arg[RESET_ARG_MAX + 1];
} ALIGNED(16);

void InitSIF0(void);
void SyncSIF0(void);
int  New_Reset_Iop(const char *arg, int arglen);
int  Reset_Iop(const char *arg, int flag);

#endif /* IOPMGR */