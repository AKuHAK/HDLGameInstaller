/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright (c) 2003 Marcus R. Brown <mrbrown@0xd6.org>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
# $Id$
# ATA Device Driver definitions and imports.
*/

#ifndef IOP_ATAD_H
#define IOP_ATAD_H

#include <types.h>
#include <irx.h>

/* These are used with the dir parameter of ata_device_sector_io().  */
#define ATA_DIR_READ	0
#define ATA_DIR_WRITE	1

#define ATAD_XFER_MODE_PIO	0x08
#define ATAD_XFER_MODE_MDMA	0x20
#define ATAD_XFER_MODE_UDMA	0x40

typedef struct _ata_devinfo {
	int	exists;		/* Was successfully probed.  */
	int	has_packet;	/* Supports the PACKET command set.  */
	unsigned int	total_sectors;	/* Total number of user sectors.  */
	unsigned int	security_status;/* Word 0x100 of the identify info.  */
} ata_devinfo_t;

int atad_start(void);
ata_devinfo_t * ata_get_devinfo(int device);
int ata_io_start(void *buf, unsigned int blkcount, unsigned short int feature, unsigned short int nsector, unsigned short int sector, unsigned short int lcyl, unsigned short int hcyl, unsigned short int select, unsigned short int command);
int ata_io_finish(void);
int ata_get_error(void);
int ata_device_sector_io(int device, void *buf, unsigned int lba, unsigned int nsectors, int dir);

// APA Partition
#define APA_MAGIC		0x00415041	// 'APA\0'
#define APA_IDMAX		32
#define APA_MAXSUB		64		// Maximum # of sub-partitions
#define APA_PASSMAX		8
#define APA_FLAG_SUB		0x0001
#define APA_MBR_VERSION		2

typedef struct {
	u8	unused;
	u8	sec;
	u8	min;
	u8	hour;
	u8	day;
	u8	month;
	u16	year;
} ps2time;

typedef struct {
	u32 part_offset; 	// in MB
	u32 data_start; 	// in sectors
	u32 part_size; 		// in KB
} hdl_partspecs_t;

#define HDL_NUM_PART_SPECS	65

typedef struct				// size = 1024
{
	u32	checksum;		// HDL uses 0xdeadfeed magic here
	u32	magic;
	char	gamename[160];
	u8	compat_flags;
	u8	pad[3];
	char	startup[60];
	u32	layer1_start;
	u32	discType;
	int	num_partitions;
	hdl_partspecs_t part_specs[HDL_NUM_PART_SPECS];
} hdl_apa_header;

#endif /* IOP_ATAD_H */
