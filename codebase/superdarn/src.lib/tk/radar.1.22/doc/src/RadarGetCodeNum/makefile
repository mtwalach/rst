# Makefile for RadarGetCodeNum
# ============================
# by R.J.Barnes
#
#
include $(MAKECFG).$(SYSTEM)

INCLUDE=-I$(IPATH)/base -I$(IPATH)/superdarn 
IGNVER=1
OBJS = RadarGetCodeNum.o
OUTPUT = RadarGetCodeNum
LIBS=-lradar.1 -lrtime.1 -lrcnv.1 
SLIB=-lm
 
include $(MAKELIB).$(SYSTEM)
