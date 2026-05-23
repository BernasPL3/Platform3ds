TARGET      := Platform3DS
BUILD       := build
SOURCES     := source
DATA        := data
INCLUDES    := include

ARCH        := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS      := -g -Wall -O2 \
               -mword-relocations \
               -ffunction-sections \
               $(ARCH)

CXXFLAGS    := $(CFLAGS) -fno-rtti -fno-exceptions

LDFLAGS     := -specs=3dsx.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map)

LIBS        := -lcitro2d -lcitro3d -lctru -lm

DEVKITPRO ?= /opt/devkitpro

include $(DEVKITPRO)/3ds_rules
