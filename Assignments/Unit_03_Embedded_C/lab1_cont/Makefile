CC=arm-none-eabi-
CFLAGS=-g -c -mcpu=arm926ej-s
INCS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
Asm=$(wildcard *.s)
AsmObj=$(Asm:.s=.o)
ProjectName=Lab1
all:$(ProjectName).bin
	@echo "#########################Build Done###############################"

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $< -o $@ 
		
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(ProjectName).elf: $(OBJ) $(AsmObj)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsmObj) -o $@
	
$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin