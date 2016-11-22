# libs Makefile
include ../Makefile.common
LIBS+=libstm32.a
LIBS+=libFreeRTOS.a
CFLAGSlib+=-c
all: libs
libs: $(LIBS)
libstm32.a:
	@echo -n "Building $@ ..."
	@cd $(STMLIB)/CMSIS/CM3/DeviceSupport/ST/STM32F10x && \
		$(CC) $(CFLAGSlib) \
			system_stm32f10x.c
	@cd $(STMLIB)/STM32F10x_StdPeriph_Driver/src && \
		$(CC) $(CFLAGSlib) \
			-D"assert_param(expr)=((void)0)" \
			-I../../CMSIS/CM3/CoreSupport \
			-I../../CMSIS/CM3/DeviceSupport/ST/STM32F10x \
			-I../inc \
			*.c
	@$(AR) cr $(LIBDIR)/$@ \
		$(STMLIB)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.o \
		$(STMLIB)/STM32F10x_StdPeriph_Driver/src/*.o 
	@echo "done."
libFreeRTOS.a:
	@echo -n "Building $@ ..."
	@cd $(FREERTOSLIB)/Source && \
		$(CC) $(CFLAGSlib) \
			-I./include/ \
			-I./portable/GCC/ARM_CM3 \
			./portable/GCC/ARM_CM3/port.c \
			./portable/MemMang/heap_4.c \
			*.c
	@$(AR) cr $(LIBDIR)/$@ \
		$(FREERTOSLIB)/Source/port.o \
		$(FREERTOSLIB)/Source/heap_4.o \
		$(FREERTOSLIB)/Source/*.o
	@echo "done"
.PHONY: libs clean tshow
clean:
	rm -f $(STMLIB)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.o
	rm -f $(STMLIB)/STM32F10x_StdPeriph_Driver/src/*.o
	rm -f $(FREERTOSLIB)/Source/portable/GCC/ARM_CM3/port.o
	rm -f $(FREERTOSLIB)/Source/portable/MemMang/heap_4.o
	rm -f $(FREERTOSLIB)/Source/*.o
	rm -f $(LIBS)
tshow:
	@echo "######################################################################################################"
	@echo "######## optimize settings: $(InfoTextLib), $(InfoTextSrc)"
	@echo "######################################################################################################"
