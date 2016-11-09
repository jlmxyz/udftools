#ifndef __UDFFSCK_H__
#define __UDFFSCK_H__

#include <ecma_167.h>
#include <libudffs.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

typedef enum {
    FIRST_AVDP = 0,
    SECOND_AVDP,
} avdp_type_e;

typedef enum {
    MAIN_VDS = 0,
    RESERVE_VDS,
} vds_type_e;

// Anchor volume descriptor points to Mvds and Rvds
int get_avdp(int fd, struct udf_disc *disc, int sectorsize, avdp_type_e type);

// Volume descriptor sequence
int get_vds(int fd, struct udf_disc *disc, int sectorsize, vds_type_e vds);
// load all of these descriptors
int get_pvd(int fd, struct udf_disc *disc, int sectorsize, vds_type_e vds);
int get_lvd(int fd, struct udf_disc *disc, int sectorsize, vds_type_e vds);
int get_pd();
int get_usd();
int get_iuvd();
int get_td();

// Logical Volume Integrity Descriptor
int get_lvid();


#endif //__UDFFSCK_H__
