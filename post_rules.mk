# Define your variant from the `make` command line `ISO_ENABLE=yes`
# or by adding `ISO_ENABLE yes` to the keymap rules.mk file.

ISO_ENABLE ?= no
ifeq ($(strip $(ISO_ENABLE)), yes)
	OPT_DEFS += -DISO_ENABLE
else
	OPT_DEFS += -DANSI_ENABLE
endif

# in case you forget the "_ENABLE" bit
ISO ?= no
ifeq ($(strip $(ISO)), yes)
	OPT_DEFS += -DISO_ENABLE
else
	OPT_DEFS += -DANSI_ENABLE
endif
