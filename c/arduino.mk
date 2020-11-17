# Ejecutar make desde el directorio del proyecto
# (donde se encuentra el código fuente y el Makefile).
#
# El Makefile define las variables PROG y SRC
# e incluye este archivo.

# Si no está definida la variables PROG
ifeq (${PROG},)
$(error Please specify PROG = ... in your main Makefile.)
endif

# Si no está definida la variables SRC
ifeq (${SRC},)
$(error Please specify SRC += ... in your main Makefile.)
endif

# El primer target (objetivo) es el objetivo por defecto.
all:

# Toolchain.
CC = avr-gcc
OBJCOPY = avr-objcopy
MCU = atmega328p
F_CPU = 16000000UL

# Grabador.
AVRDUDE = avrdude

# Arduino UNO Rev3
#PORT = /dev/ttyACM0
# Arduino UNO CH430
PORT = /dev/ttyUSB0
BAUD = 115200
PROTOCOL = arduino
PART = ATMEGA328P

# Variables generales.
AVRDUDEFLAGS = -F -V -c ${PROTOCOL} -p ${PART} -P ${PORT} -b ${BAUD}
CFLAGS += -g
CPPFLAGS += -DF_CPU=${F_CPU}
TARGET_ARCH = -mmcu=${MCU}
COPTFLAG = -Os
CFLAGS += ${COPTFLAG}
WFLAGS += -Wall -Wextra
CFLAGS += ${WFLAGS}
LDFLAGS += ${WFLAGS}
ASFLAGS += ${WFLAGS}

# Filtra archivos .c, .S y .s de SRC
SRC_C = $(filter %.c,${SRC})
SRC_s = $(filter %.s,${SRC})
SRC_S = $(filter %.S,${SRC})

# Listado de archivos .c, .S y .s convertidos a .o
OBJ = $(SRC_C:.c=.o) $(SRC_s:.s=.o) $(SRC_S:.S=.o)

# Targets que no son archivos.
.PHONY: all clean grabar

all: ${PROG} ${PROG}.hex

${PROG}: ${OBJ}

%.hex: %
	${OBJCOPY} -O ihex -R .eeprom $< $@

clean:
	rm -f ${PROG} $(addprefix ${PROG}, .elf .hex) ${OBJ}

grabar: ${PROG}.hex
	${AVRDUDE} ${AVRDUDEFLAGS} -U flash:w:$<

