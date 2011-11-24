#ifndef __XBEE_H
#define __XBEE_H

/*
  libxbee - a C library to aid the use of Digi's Series 1 XBee modules
            running in API mode (AP=2).

  Copyright (C) 2009  Attie Grande (attie@attie.co.uk)

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdarg.h>

struct xbee;

struct xbee_pkt_ioSample {
	unsigned char d0 : 1;
	unsigned char d1 : 1;
	unsigned char d2 : 1;
	unsigned char d3 : 1;
	unsigned char d4 : 1;
	unsigned char d5 : 1;
	unsigned char d6 : 1;
	unsigned char d7 : 1;
	unsigned char d8 : 1;
	unsigned short a0;
	unsigned short a1;
	unsigned short a2;
	unsigned short a3;
	unsigned short a4;
	unsigned short a5;
};
struct xbee_pkt_ioData {
	unsigned char d0_enabled : 1;
	unsigned char d1_enabled : 1;
	unsigned char d2_enabled : 1;
	unsigned char d3_enabled : 1;
	unsigned char d4_enabled : 1;
	unsigned char d5_enabled : 1;
	unsigned char d6_enabled : 1;
	unsigned char d7_enabled : 1;
	unsigned char d8_enabled : 1;
	unsigned char a0_enabled : 1;
	unsigned char a1_enabled : 1;
	unsigned char a2_enabled : 1;
	unsigned char a3_enabled : 1;
	unsigned char a4_enabled : 1;
	unsigned char a5_enabled : 1;

	unsigned char sampleCount;
	struct xbee_pkt_ioSample sample[1];
};

struct xbee_pkt {
	unsigned char status;
	unsigned char options;
	unsigned char rssi;

	struct xbee_pkt_ioData *ioData;

	int datalen;
	unsigned char data[1];
};

/* --- xbee.c --- */
int xbee_setup(struct xbee **retXbee);
void xbee_freePkt(struct xbee_pkt *pkt);

/* --- mode.c --- */
char **xbee_getModes(void);
char *xbee_getMode(struct xbee *xbee);
int xbee_setMode(struct xbee *xbee, char *name);

/* --- conn.c --- */
int xbee_conTypeIdFromName(struct xbee *xbee, char *name, unsigned char *id);

/* --- log.c --- */
void xbee_logSetTarget(FILE *f);

#endif /* __XBEE_H */

