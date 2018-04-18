LOCAL_PATH := $(call my-dir)

MAIN_FBA_DIR         := $(LOCAL_PATH)/../../../src
FBA_BURN_DIR         := $(MAIN_FBA_DIR)/burn
FBA_BURN_DRIVERS_DIR := $(MAIN_FBA_DIR)/burn/drv
FBA_BURNER_DIR       := $(MAIN_FBA_DIR)/burner
LIBRETRO_DIR         := $(FBA_BURNER_DIR)/libretro
LIBRETRO_COMM_DIR    := $(LIBRETRO_DIR)/libretro-common
FBA_CPU_DIR          := $(MAIN_FBA_DIR)/cpu
FBA_LIB_DIR          := $(MAIN_FBA_DIR)/dep/libs
FBA_INTERFACE_DIR    := $(MAIN_FBA_DIR)/intf
FBA_GENERATED_DIR    := $(MAIN_FBA_DIR)/dep/generated
FBA_SCRIPTS_DIR      := $(MAIN_FBA_DIR)/dep/scripts
M68K_DIR             := $(FBA_CPU_DIR)/m68k
CPS2_DIR             := $(FBA_BURN_DRIVERS_DIR)/capcom
CPS3_DIR             := $(FBA_BURN_DRIVERS_DIR)/cps3
GALAXIAN_DIR         := $(FBA_BURN_DRIVERS_DIR)/galaxian
NEOGEO_DIR           := $(FBA_BURN_DRIVERS_DIR)/neogeo
PGM_DIR              := $(FBA_BURN_DRIVERS_DIR)/pgm
SNES_DIR             := $(FBA_BURN_DRIVERS_DIR)/snes

BURN_BLACKLIST := $(FBA_BURNER_DIR)/un7z.cpp \
	$(FBA_CPU_DIR)/arm7/arm7exec.c \
	$(FBA_CPU_DIR)/arm7/arm7core.c \
	$(FBA_CPU_DIR)/hd6309/6309tbl.c \
	$(FBA_CPU_DIR)/hd6309/6309ops.c \
	$(FBA_CPU_DIR)/konami/konamtbl.c \
	$(FBA_CPU_DIR)/konami/konamops.c \
	$(FBA_CPU_DIR)/m68k/m68k_in.c \
	$(FBA_CPU_DIR)/m6800/6800ops.c \
	$(FBA_CPU_DIR)/m6800/6800tbl.c \
	$(FBA_CPU_DIR)/m6805/6805ops.c \
	$(FBA_CPU_DIR)/m6809/6809ops.c \
	$(FBA_CPU_DIR)/m6809/6809tbl.c \
	$(FBA_CPU_DIR)/sh2/mksh2.cpp \
	$(FBA_CPU_DIR)/sh2/mksh2-x86.cpp \
	$(FBA_CPU_DIR)/m68k/m68kmake.c \
	$(FBA_BURNER_DIR)/wave_writer.cpp \
	$(FBA_CPU_DIR)/m68k/m68kdasm.c \
	$(FBA_LIBRETRO_DIR)/menu.cpp \
	$(FBA_CPU_DIR)/sh2/mksh2.cpp \
	$(FBA_BURNER_DIR)/sshot.cpp \
	$(FBA_BURNER_DIR)/conc.cpp \
	$(FBA_BURNER_DIR)/dat.cpp \
	$(FBA_BURNER_DIR)/cong.cpp \
	$(FBA_BURNER_DIR)/image.cpp \
	$(FBA_BURNER_DIR)/misc.cpp \
	$(FBA_CPU_DIR)/c68k/c68k_ini.c \
	$(FBA_CPU_DIR)/c68k/c68k_op.c \
	$(FBA_CPU_DIR)/h6280/tblh6280.c \
	$(FBA_CPU_DIR)/m6502/t65sc02.c \
	$(FBA_CPU_DIR)/m6502/t65c02.c \
	$(FBA_CPU_DIR)/m6502/tdeco16.c \
	$(FBA_CPU_DIR)/m6502/tn2a03.c \
	$(FBA_CPU_DIR)/m6502/t6502.c \
	$(FBA_CPU_DIR)/nec/v25sfr.c \
	$(FBA_CPU_DIR)/nec/v25instr.c \
	$(FBA_CPU_DIR)/nec/necinstr.c \
	$(FBA_BURN_DIR)/drv/capcom/ctv_make.cpp

FBA_BURN_DIRS := $(FBA_BURN_DIR) \
	$(FBA_BURN_DIR)/devices \
	$(FBA_BURN_DIR)/snd \
	$(CPS2_DIR) \
	$(FBA_BURN_DRIVERS_DIR)/cave \
	$(CPS3_DIR) \
	$(FBA_BURN_DRIVERS_DIR)/dataeast \
	$(GALAXIAN_DIR) \
	$(FBA_BURN_DRIVERS_DIR)/irem \
	$(FBA_BURN_DRIVERS_DIR)/konami \
	$(FBA_BURN_DRIVERS_DIR)/megadrive \
	$(NEOGEO_DIR) \
	$(FBA_BURN_DRIVERS_DIR)/pce \
	$(PGM_DIR) \
	$(FBA_BURN_DRIVERS_DIR)/pre90s \
	$(FBA_BURN_DRIVERS_DIR)/psikyo \
	$(FBA_BURN_DRIVERS_DIR)/pst90s \
	$(FBA_BURN_DRIVERS_DIR)/sega \
	$(SNES_DIR) \
	$(FBA_BURN_DRIVERS_DIR)/taito \
	$(FBA_BURN_DRIVERS_DIR)/toaplan

FBA_CPU_DIRS := $(FBA_CPU_DIR) \
	$(FBA_CPU_DIR)/arm \
	$(FBA_CPU_DIR)/arm7 \
	$(FBA_CPU_DIR)/h6280 \
	$(FBA_CPU_DIR)/hd6309 \
	$(FBA_CPU_DIR)/i8039 \
	$(FBA_CPU_DIR)/konami \
	$(M68K_DIR) \
	$(FBA_CPU_DIR)/m6502 \
	$(FBA_CPU_DIR)/m6800 \
	$(FBA_CPU_DIR)/m6805 \
	$(FBA_CPU_DIR)/m6809 \
	$(FBA_CPU_DIR)/nec \
	$(FBA_CPU_DIR)/s2650 \
	$(FBA_CPU_DIR)/sh2 \
	$(FBA_CPU_DIR)/z80

FBA_SRC_DIRS := $(FBA_BURNER_DIR) $(FBA_BURN_DIRS) $(FBA_CPU_DIRS) $(FBA_BURNER_DIRS)

INCDIRS := -I$(FBA_BURNER_DIR)/win32 \
	-I$(LIBRETRO_DIR) \
	-I$(LIBRETRO_DIR)/tchar \
	-I$(FBA_BURN_DIR) \
	-I$(MAIN_FBA_DIR)/cpu \
	-I$(FBA_BURN_DIR)/snd \
	-I$(FBA_BURN_DIR)/devices \
	-I$(FBA_INTERFACE_DIR) \
	-I$(FBA_INTERFACE_DIR)/input \
	-I$(FBA_INTERFACE_DIR)/cd \
	-I$(FBA_BURNER_DIR) \
	-I$(FBA_CPU_DIR) \
	-I$(FBA_CPU_DIR)/i8039 \
	-I$(FBA_LIB_DIR)/zlib \
	-I$(FBA_BURN_DIR)/drv/capcom \
	-I$(FBA_BURN_DIR)/drv/dataeast \
	-I$(FBA_BURN_DIR)/drv/cave \
	-I$(FBA_BURN_DIR)/drv/neogeo \
	-I$(FBA_BURN_DIR)/drv/psikyo \
	-I$(FBA_BURN_DIR)/drv/sega \
	-I$(FBA_BURN_DIR)/drv/toaplan \
	-I$(FBA_BURN_DIR)/drv/taito \
	-I$(FBA_GENERATED_DIR) \
	-I$(LIBRETRO_COMM_DIR)/include \
	-I$(FBA_LIB_DIR)

COREFLAGS := $(INCDIRS) -fno-stack-protector -DUSE_SPEEDHACKS -D__LIBRETRO_OPTIMIZATIONS__ -D__LIBRETRO__ -Wno-write-strings -DUSE_FILE32API -DANDROID -DFRONTEND_SUPPORTS_RGB565 -DFBACORES_CPS -DEMU_M68K

GIT_VERSION := " $(shell git rev-parse --short HEAD || echo unknown)"
ifneq ($(GIT_VERSION)," unknown")
  COREFLAGS += -DGIT_VERSION=\"$(GIT_VERSION)\"
endif

include $(CLEAR_VARS)
LOCAL_MODULE       := retro
LOCAL_SRC_FILES    := $(filter-out $(BURN_BLACKLIST),$(foreach dir,$(FBA_SRC_DIRS),$(wildcard $(dir)/*.cpp))) $(filter-out $(BURN_BLACKLIST),$(foreach dir,$(FBA_SRC_DIRS),$(wildcard $(dir)/*.c))) $(LIBRETRO_DIR)/libretro.cpp
LOCAL_CXXFLAGS     := $(COREFLAGS)
LOCAL_CFLAGS       := $(COREFLAGS)
LOCAL_LDFLAGS      := -Wl,-version-script=$(LIBRETRO_DIR)/link.T
LOCAL_LDLIBS       := -lz
LOCAL_CPP_FEATURES := exceptions rtti
include $(BUILD_SHARED_LIBRARY)
