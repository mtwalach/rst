/* magcmp.c
   ========
   Author: R.J.Barnes
   Comments: E.G.Thomas (2016)
*/

/*
 LICENSE AND DISCLAIMER
 
 Copyright (c) 2012 The Johns Hopkins University/Applied Physics Laboratory
 
 This file is part of the Radar Software Toolkit (RST).
 
 RST is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.
 
 RST is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with RST.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <math.h>
#include <stdio.h>
#include "igrfcall.h"



/**
 * Calculates the IGRF magnetic field components at a given location in
 * geocentric coordinates.
 **/
int IGRFMagCmp(double date, double frho, double flat, double flon, 
               double *bx, double *by, double *bz, double *b) {

    int s;

    /* Calculate virtual height of range/beam measurement [km]
     * using fixed value for Earth radius */
    frho = frho - 6372.;

    /* Calculate magnetic field componenets at field point */
    s=IGRFCall(date, flat, flon, frho, bx, by, bz);

    /* Calculate magnitude of magnetic field vector */
    *b = sqrt(*bx * *bx + *by * *by + *bz * *bz);

    /* For some reason we reverse the sign of Bx and Bz components? */
    *bx = -*bx;
    *bz = -*bz;

    return s;

}
