KEYMAP=zeal
PLATFORM=linux

firmware/${KEYMAP}.hex: keymaps/${KEYMAP}.c tmk/keyboard/gh60/config.h
	# define GH60_REV_CHN in config.h
	[ "$(grep GH60_REV_CHN tmk/keyboard/gh60/config.h | wc -l)" -eq "2" ] || echo '#define GH60_REV_CHN' >> tmk/keyboard/gh60/config.h
	# comment on unused features in Makefile
	sed -i \
		-e 's/^KEYMAP_IN_EEPROM_ENABLE/#&/' \
		-e 's/^KEYMAP_SECTION_ENABLE/#&/' \
		-e 's/^SOFTPWM_LED_ENABLE/#&/' \
		-e 's/^LEDMAP_ENABLE/#&/' \
		-e 's/^LEDMAP_IN_EEPROM_ENABLE/#&/' \
		-e 's/^FADING_LED_ENABLE/#&/' \
		-e 's/^BACKLIGHT_ENABLE/#&/' \
		-e 's/^BREATHING_LED_ENABLE/#&/' \
		tmk/keyboard/gh60/Makefile
	# copy keymap into place
	cp keymaps/${KEYMAP}.c tmk/keyboard/gh60/keymap_custom.c
	# build the keymap firmware
	make -C tmk/keyboard/gh60 KEYMAP=custom
	# copy out the resulting firmware file
	cp tmk/keyboard/gh60/gh60_lufa.hex $@

install: firmware/${KEYMAP}.hex tkg/${PLATFORM}/conf/default.ini
	# copy firmware into place
	cp firmware/${KEYMAP}.hex tkg/common/firmware/gh60-revchn.hex
	# run the reflash script (as root)
	sudo tkg/${PLATFORM}/reflash.sh

all: firmware/${KEYMAP}.hex install

tkg/${PLATFORM}/conf/default.ini: tkg/${PLATFORM}/conf
	echo 'Name="GH60 RevCHN"' >> $@
	echo 'MCU=atmega32u4' >> $@
	echo 'Firmware=gh60-revchn.hex' >> $@
	echo 'Bootloader=atmel_dfu' >> $@

tkg/${PLATFORM}/conf: tkg/${PLATFORM}
	mkdir -p $@

clean:
	rm -rf firmware
	rm -f tmk/keyboard/gh60/keymap_custom.c
	rm -f tkg/common/firmware/gh60-revchn.hex
	[ -d tmk/keyboard/gh60 ] && make -C tmk/keyboard/gh60 clean
	mkdir -p firmware

fullclean: clean
	cd tmk ; git checkout -- .
	cd tkg ; git checkout -- .

firmware:
	mkdir -p firmware

tmk/keyboard/gh60/config.h: modules

tkg/${PLATFORM}: modules

modules:
	git submodule init
	git submodule update
	cd tmk ; git submodule init ; git submodule update

.PHONY: install clean fullclean modules
