CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -c -mcpu=cortex-m3
INCS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
Asm=$(wildcard *.s)
AsmObj=$(Asm:.s=.o)
ProjectName=Lab2

all:$(ProjectName).bin
	@echo "#########################Build Done###############################"

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $< -o $@ 
		
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(ProjectName).elf: $(OBJ) $(AsmObj)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsmObj) -o $@ -Map=map_file
	
$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin