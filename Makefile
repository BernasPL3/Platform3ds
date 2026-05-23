TARGET  := Platform3DS
BUILD   := build
SOURCES := source
INCLUDES :=

LIBS := -lcitro2d -lcitro3d

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

include $(DEVKITPRO)/3ds_rules
