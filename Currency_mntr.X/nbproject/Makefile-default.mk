#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/ext_int.c mcc_generated_files/i2c1.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr1.c mcc_generated_files/traps.c mcc_generated_files/uart2.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/spi1.c WINC1500/Board_driver/wf_mcu_driver_stub.c WINC1500/Driver/wf_asic.c WINC1500/Driver/wf_hif.c WINC1500/Driver/wf_ota.c WINC1500/Driver/wf_socket.c WINC1500/Driver/wf_spi.c WINC1500/Driver/wf_spi_flash.c WINC1500/Driver/wf_utils.c WINC1500/Driver/wf_wifi.c WINC1500/Example/winc1500_fw_update_over_serial.c WINC1500/Example/winc1500_http_download.c WINC1500/Example/winc1500_locate_ip_address.c WINC1500/Example/winc1500_mac_address.c WINC1500/Example/winc1500_mode_ap.c WINC1500/Example/winc1500_mode_change.c WINC1500/Example/winc1500_mode_p2p.c WINC1500/Example/winc1500_mode_sta.c WINC1500/Example/winc1500_ota_firmware_update.c WINC1500/Example/winc1500_power_save_mode.c WINC1500/Example/winc1500_provision_http.c WINC1500/Example/winc1500_security_wep_wpa.c WINC1500/Example/winc1500_security_wps.c WINC1500/Example/winc1500_send_email.c WINC1500/Example/winc1500_signal_strength.c WINC1500/Example/winc1500_ssl_connect.c WINC1500/Example/winc1500_tcp_client.c WINC1500/Example/winc1500_tcp_server.c WINC1500/Example/winc1500_time_client.c WINC1500/Example/winc1500_weather_client.c WINC1500/Support/winc1500_support_stub.c bsp.c main.c ST7735_TFT.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/ext_int.o ${OBJECTDIR}/mcc_generated_files/i2c1.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o ${OBJECTDIR}/WINC1500/Driver/wf_asic.o ${OBJECTDIR}/WINC1500/Driver/wf_hif.o ${OBJECTDIR}/WINC1500/Driver/wf_ota.o ${OBJECTDIR}/WINC1500/Driver/wf_socket.o ${OBJECTDIR}/WINC1500/Driver/wf_spi.o ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o ${OBJECTDIR}/WINC1500/Driver/wf_utils.o ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o ${OBJECTDIR}/bsp.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ST7735_TFT.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/ext_int.o.d ${OBJECTDIR}/mcc_generated_files/i2c1.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/tmr1.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/uart2.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/spi1.o.d ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o.d ${OBJECTDIR}/WINC1500/Driver/wf_asic.o.d ${OBJECTDIR}/WINC1500/Driver/wf_hif.o.d ${OBJECTDIR}/WINC1500/Driver/wf_ota.o.d ${OBJECTDIR}/WINC1500/Driver/wf_socket.o.d ${OBJECTDIR}/WINC1500/Driver/wf_spi.o.d ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o.d ${OBJECTDIR}/WINC1500/Driver/wf_utils.o.d ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o.d ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o.d ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o.d ${OBJECTDIR}/bsp.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/ST7735_TFT.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/ext_int.o ${OBJECTDIR}/mcc_generated_files/i2c1.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o ${OBJECTDIR}/WINC1500/Driver/wf_asic.o ${OBJECTDIR}/WINC1500/Driver/wf_hif.o ${OBJECTDIR}/WINC1500/Driver/wf_ota.o ${OBJECTDIR}/WINC1500/Driver/wf_socket.o ${OBJECTDIR}/WINC1500/Driver/wf_spi.o ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o ${OBJECTDIR}/WINC1500/Driver/wf_utils.o ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o ${OBJECTDIR}/bsp.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ST7735_TFT.o

# Source Files
SOURCEFILES=mcc_generated_files/ext_int.c mcc_generated_files/i2c1.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr1.c mcc_generated_files/traps.c mcc_generated_files/uart2.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/spi1.c WINC1500/Board_driver/wf_mcu_driver_stub.c WINC1500/Driver/wf_asic.c WINC1500/Driver/wf_hif.c WINC1500/Driver/wf_ota.c WINC1500/Driver/wf_socket.c WINC1500/Driver/wf_spi.c WINC1500/Driver/wf_spi_flash.c WINC1500/Driver/wf_utils.c WINC1500/Driver/wf_wifi.c WINC1500/Example/winc1500_fw_update_over_serial.c WINC1500/Example/winc1500_http_download.c WINC1500/Example/winc1500_locate_ip_address.c WINC1500/Example/winc1500_mac_address.c WINC1500/Example/winc1500_mode_ap.c WINC1500/Example/winc1500_mode_change.c WINC1500/Example/winc1500_mode_p2p.c WINC1500/Example/winc1500_mode_sta.c WINC1500/Example/winc1500_ota_firmware_update.c WINC1500/Example/winc1500_power_save_mode.c WINC1500/Example/winc1500_provision_http.c WINC1500/Example/winc1500_security_wep_wpa.c WINC1500/Example/winc1500_security_wps.c WINC1500/Example/winc1500_send_email.c WINC1500/Example/winc1500_signal_strength.c WINC1500/Example/winc1500_ssl_connect.c WINC1500/Example/winc1500_tcp_client.c WINC1500/Example/winc1500_tcp_server.c WINC1500/Example/winc1500_time_client.c WINC1500/Example/winc1500_weather_client.c WINC1500/Support/winc1500_support_stub.c bsp.c main.c ST7735_TFT.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA705
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA705.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/ext_int.o: mcc_generated_files/ext_int.c  .generated_files/flags/default/7cfe24b63bf6026e3559c08db86274d284d7cc1d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ext_int.c  -o ${OBJECTDIR}/mcc_generated_files/ext_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ext_int.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/i2c1.o: mcc_generated_files/i2c1.c  .generated_files/flags/default/b54ceb5b9dab0323f4759171f0526e74aee46eb2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/i2c1.c  -o ${OBJECTDIR}/mcc_generated_files/i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/684116c95aeba73d85468278130a3971f502d9d6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/d976565ddf9bbc6fa3ce77e2eaa4cffba6335ad1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/a16ffab1c52b49087ef0e4c5ce97018426b35276 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/d113ea70879a6de28f1169a2817a1c4372720164 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/default/b84e0931d51b524242ec0cdb48f6e5b92181adee .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/flags/default/cd65b934d8188f838a7343348e165480a0a6b8d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart2.c  -o ${OBJECTDIR}/mcc_generated_files/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/1431030733783954ee913fc7b3c1d333d42d1110 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/782302b564eb35f2c9d1a7f9d29c31756a8cd2ab .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/default/8bdd4375c1dfc2189f1e9304f6947b5804631542 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o: WINC1500/Board_driver/wf_mcu_driver_stub.c  .generated_files/flags/default/25040ec090eed2d1afa7cfafd5d686ebfbfd0c90 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Board_driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Board_driver/wf_mcu_driver_stub.c  -o ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_asic.o: WINC1500/Driver/wf_asic.c  .generated_files/flags/default/1053af0a42aad90b0cfe1d3f7fae592817540fe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_asic.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_asic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_asic.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_asic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_asic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_hif.o: WINC1500/Driver/wf_hif.c  .generated_files/flags/default/cc0af62b60980a10ec3a454011f7fc3d4efa371 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_hif.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_hif.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_hif.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_hif.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_hif.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_ota.o: WINC1500/Driver/wf_ota.c  .generated_files/flags/default/4a27238ded066d6ca9cc225827670b97f99c673b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_ota.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_ota.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_ota.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_ota.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_ota.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_socket.o: WINC1500/Driver/wf_socket.c  .generated_files/flags/default/e72498771fdd3261b22af816bed329b4491ff150 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_socket.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_socket.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_socket.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_socket.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_socket.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_spi.o: WINC1500/Driver/wf_spi.c  .generated_files/flags/default/ac184beef2a8d49a3a690c1b22b8f0c906dfaa7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_spi.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o: WINC1500/Driver/wf_spi_flash.c  .generated_files/flags/default/dc79bc1f2f9edfff0f8620b9be92911d93bfdce3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_spi_flash.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_utils.o: WINC1500/Driver/wf_utils.c  .generated_files/flags/default/4252e4aed75dab08bee32f252a68b2579fae0964 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_utils.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_utils.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_utils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_wifi.o: WINC1500/Driver/wf_wifi.c  .generated_files/flags/default/ed8d6af9d49c7674bc87df2725fb49cd3be7ec9a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_wifi.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_wifi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o: WINC1500/Example/winc1500_fw_update_over_serial.c  .generated_files/flags/default/eddfe1a9c5deff7c4d5b828f8963538872f1eb83 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_fw_update_over_serial.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o: WINC1500/Example/winc1500_http_download.c  .generated_files/flags/default/d140d528c52def54d6e03cf3bdcfcb2c0daeb214 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_http_download.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o: WINC1500/Example/winc1500_locate_ip_address.c  .generated_files/flags/default/5470c03613bb9b84557157304bf498544d37bc1a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_locate_ip_address.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o: WINC1500/Example/winc1500_mac_address.c  .generated_files/flags/default/41f27ba145473238d6d517e84840ff43f7ed2941 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mac_address.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o: WINC1500/Example/winc1500_mode_ap.c  .generated_files/flags/default/781aa25a2adf74475b422da21d9fddf2e6ed4ac3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_ap.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o: WINC1500/Example/winc1500_mode_change.c  .generated_files/flags/default/80634917c980130770106d62103334d29f469ee0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_change.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o: WINC1500/Example/winc1500_mode_p2p.c  .generated_files/flags/default/d95e6f0cc76f12dcee5f39ff732403a89c56755e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_p2p.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o: WINC1500/Example/winc1500_mode_sta.c  .generated_files/flags/default/fbabafeed0275152ac91f08a5fe4cd07aa65137c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_sta.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o: WINC1500/Example/winc1500_ota_firmware_update.c  .generated_files/flags/default/d8a811b86b468d355e2db2e08095bdad10239b11 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_ota_firmware_update.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o: WINC1500/Example/winc1500_power_save_mode.c  .generated_files/flags/default/302f34b6f542a56c5aff447d66395d53ec2f7853 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_power_save_mode.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o: WINC1500/Example/winc1500_provision_http.c  .generated_files/flags/default/d04051d0fbe584ac0e3fd09eb611c82112a26497 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_provision_http.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o: WINC1500/Example/winc1500_security_wep_wpa.c  .generated_files/flags/default/db1d7c62a77f31054e4a628f8b6fd610339dadcf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_security_wep_wpa.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o: WINC1500/Example/winc1500_security_wps.c  .generated_files/flags/default/c5cde202b73691e2411eca23e24589326d765a43 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_security_wps.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o: WINC1500/Example/winc1500_send_email.c  .generated_files/flags/default/3a101af9ba2634b715ace46103f3d25b7e3fb827 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_send_email.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o: WINC1500/Example/winc1500_signal_strength.c  .generated_files/flags/default/ceeb75da1fcaedbdf84dcbe63d9a35d3c1281d4e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_signal_strength.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o: WINC1500/Example/winc1500_ssl_connect.c  .generated_files/flags/default/7c440138ea67ee11a1bae8378e4ea41980732e9f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_ssl_connect.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o: WINC1500/Example/winc1500_tcp_client.c  .generated_files/flags/default/2481e2151eebbd2c1f0544c5ca6dd47fe982503b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_tcp_client.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o: WINC1500/Example/winc1500_tcp_server.c  .generated_files/flags/default/9d5a31ded4e0fff12d2af065d027201390f76f6e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_tcp_server.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o: WINC1500/Example/winc1500_time_client.c  .generated_files/flags/default/301d5a71788889a3fc33194bfc52cdbd31e990be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_time_client.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o: WINC1500/Example/winc1500_weather_client.c  .generated_files/flags/default/8c4fafc0b8d34a0ebbb4994e350e85b91e6b5fc2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_weather_client.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o: WINC1500/Support/winc1500_support_stub.c  .generated_files/flags/default/b4103c92070267b3c41902126808ba7a6ee7d127 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Support" 
	@${RM} ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Support/winc1500_support_stub.c  -o ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp.o: bsp.c  .generated_files/flags/default/db45af7d9ffd53698c4d04ec0c8bb0e64b5e4dfd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bsp.o.d 
	@${RM} ${OBJECTDIR}/bsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp.c  -o ${OBJECTDIR}/bsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/10641ab0e93e61efbb697f0756fc06e6e268dbb2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ST7735_TFT.o: ST7735_TFT.c  .generated_files/flags/default/571d3152ff5f8ea1e74ee4b303bae147e4910fec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ST7735_TFT.o.d 
	@${RM} ${OBJECTDIR}/ST7735_TFT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ST7735_TFT.c  -o ${OBJECTDIR}/ST7735_TFT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ST7735_TFT.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/ext_int.o: mcc_generated_files/ext_int.c  .generated_files/flags/default/8e34b9a87556a3d1f9160dfbf88ef6b15b2cdfc9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ext_int.c  -o ${OBJECTDIR}/mcc_generated_files/ext_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ext_int.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/i2c1.o: mcc_generated_files/i2c1.c  .generated_files/flags/default/cbae5a8611e9f6275e9e2ad6878f01e2074a3829 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/i2c1.c  -o ${OBJECTDIR}/mcc_generated_files/i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/86588875576154ea9dd6dc25855ee96a47fa876e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/9c82eebdbeae93812ebfad0fcdf9d6dd027dc3a8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/3b8c7a001c4bef8e212ad2dd4aa2bb368984857b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/be16f8b90e6f414da4b3ff417eb4bc038a0a4504 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/default/c420cc1d85acaf08f60cad698c7ec58065146f75 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/flags/default/61e35594eb8e10cdedf1b02ea1baa36d6e4af029 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart2.c  -o ${OBJECTDIR}/mcc_generated_files/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/8f2bedcafe92e22ffe82201b82791733780f780 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/3f3e9157f0117ec1700b96ef8d597ece78465435 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/default/2f4e02176c614ee44fa80eba15fcccb96aab6f5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o: WINC1500/Board_driver/wf_mcu_driver_stub.c  .generated_files/flags/default/f312ef7e8c2f19a8d2c2d0df414f232f00b05858 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Board_driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Board_driver/wf_mcu_driver_stub.c  -o ${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Board_driver/wf_mcu_driver_stub.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_asic.o: WINC1500/Driver/wf_asic.c  .generated_files/flags/default/ef544420148291b68079c3b5026b4f3604836dba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_asic.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_asic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_asic.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_asic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_asic.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_hif.o: WINC1500/Driver/wf_hif.c  .generated_files/flags/default/babe78fbea8df92c1ca3e8ba275466b4965c509c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_hif.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_hif.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_hif.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_hif.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_hif.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_ota.o: WINC1500/Driver/wf_ota.c  .generated_files/flags/default/46654309fa5c1021b7d2891e7665959e1ba1a53 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_ota.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_ota.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_ota.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_ota.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_ota.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_socket.o: WINC1500/Driver/wf_socket.c  .generated_files/flags/default/a97d19be28eac72f04e4433cc88153d79bfdb540 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_socket.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_socket.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_socket.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_socket.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_socket.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_spi.o: WINC1500/Driver/wf_spi.c  .generated_files/flags/default/ce3fc2c602fb2f2ea558125d78c298ef5114e8fe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_spi.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o: WINC1500/Driver/wf_spi_flash.c  .generated_files/flags/default/756ef535b3cd3d7fac886512f3e12b76c1c330db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_spi_flash.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_spi_flash.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_utils.o: WINC1500/Driver/wf_utils.c  .generated_files/flags/default/df79e67ce0354f979fcb3ecfbf3679f430f4bbfd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_utils.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_utils.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_utils.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Driver/wf_wifi.o: WINC1500/Driver/wf_wifi.c  .generated_files/flags/default/8adbeb81126a3335a4752198e0cd9fc501d143db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Driver" 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Driver/wf_wifi.c  -o ${OBJECTDIR}/WINC1500/Driver/wf_wifi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Driver/wf_wifi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o: WINC1500/Example/winc1500_fw_update_over_serial.c  .generated_files/flags/default/4734141a62a3ae1439c4deeb224cd6cb17685498 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_fw_update_over_serial.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_fw_update_over_serial.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o: WINC1500/Example/winc1500_http_download.c  .generated_files/flags/default/2595b0d41be95ae59f9b14bc6f990f97b279f9a7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_http_download.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_http_download.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o: WINC1500/Example/winc1500_locate_ip_address.c  .generated_files/flags/default/b6d5dcf349ccfc7d7540a85565dfc26dbd7b612b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_locate_ip_address.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_locate_ip_address.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o: WINC1500/Example/winc1500_mac_address.c  .generated_files/flags/default/224f5a3e856a878b5e6e8b8a0eb358eb7f63fc39 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mac_address.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mac_address.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o: WINC1500/Example/winc1500_mode_ap.c  .generated_files/flags/default/4b6af6121587fcd4977090fb3193388948459d62 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_ap.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_ap.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o: WINC1500/Example/winc1500_mode_change.c  .generated_files/flags/default/4ce6814d0475b746a1245627bbe74f27fab99c1a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_change.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_change.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o: WINC1500/Example/winc1500_mode_p2p.c  .generated_files/flags/default/95d29529ddea84b100899972feee420c5fd253d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_p2p.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_p2p.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o: WINC1500/Example/winc1500_mode_sta.c  .generated_files/flags/default/4c730ca5e77b22602add35a26d40a3f1f3bd3419 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_mode_sta.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_mode_sta.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o: WINC1500/Example/winc1500_ota_firmware_update.c  .generated_files/flags/default/15fade30593efed23c67c0a30d3b78dc2fa2d393 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_ota_firmware_update.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_ota_firmware_update.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o: WINC1500/Example/winc1500_power_save_mode.c  .generated_files/flags/default/3f5ab4e1e2954965e5c666d7ffff50f64641afe1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_power_save_mode.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_power_save_mode.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o: WINC1500/Example/winc1500_provision_http.c  .generated_files/flags/default/1893b6c27b958728ced9ec5acd225c4077a6c4e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_provision_http.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_provision_http.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o: WINC1500/Example/winc1500_security_wep_wpa.c  .generated_files/flags/default/3bce4fe90f6e0d459f32633bad2a7cf12f50b5cf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_security_wep_wpa.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_security_wep_wpa.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o: WINC1500/Example/winc1500_security_wps.c  .generated_files/flags/default/a4336e97fe2cf4d3a4240d1a04ca4e2ea1fc06b2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_security_wps.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_security_wps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o: WINC1500/Example/winc1500_send_email.c  .generated_files/flags/default/2b0042ad7b5b24a86b87814c0503700fed95aa6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_send_email.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_send_email.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o: WINC1500/Example/winc1500_signal_strength.c  .generated_files/flags/default/e7ac95606206722d430b72c626c3c6a11c3ce75d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_signal_strength.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_signal_strength.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o: WINC1500/Example/winc1500_ssl_connect.c  .generated_files/flags/default/92aefd8661fa031b6ba7a9af10d5790b238b190c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_ssl_connect.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_ssl_connect.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o: WINC1500/Example/winc1500_tcp_client.c  .generated_files/flags/default/ac80700925d4819dfebfab66a94e71f493a401b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_tcp_client.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_tcp_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o: WINC1500/Example/winc1500_tcp_server.c  .generated_files/flags/default/597d5ac9324f5cde7c95f6470c53f91fdae9b6bf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_tcp_server.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_tcp_server.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o: WINC1500/Example/winc1500_time_client.c  .generated_files/flags/default/dc553953822f25bc4f4ed74a287b66c1e6a34e5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_time_client.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_time_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o: WINC1500/Example/winc1500_weather_client.c  .generated_files/flags/default/c253533de3f2f2231ac7a4638074c9341b4236d1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Example" 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Example/winc1500_weather_client.c  -o ${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Example/winc1500_weather_client.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o: WINC1500/Support/winc1500_support_stub.c  .generated_files/flags/default/6c83f996d732fda70a343f33f15a4405912d390e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/WINC1500/Support" 
	@${RM} ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o.d 
	@${RM} ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WINC1500/Support/winc1500_support_stub.c  -o ${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/WINC1500/Support/winc1500_support_stub.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp.o: bsp.c  .generated_files/flags/default/11caea2ee3b03706fd492571346ef89eb8086728 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bsp.o.d 
	@${RM} ${OBJECTDIR}/bsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp.c  -o ${OBJECTDIR}/bsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a26d3d1c855cad2c46955009136f11384cb304e4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ST7735_TFT.o: ST7735_TFT.c  .generated_files/flags/default/1619b67a44e52fd22c3c27353f795cdbefeee50f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ST7735_TFT.o.d 
	@${RM} ${OBJECTDIR}/ST7735_TFT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ST7735_TFT.c  -o ${OBJECTDIR}/ST7735_TFT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ST7735_TFT.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common"     -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"WINC1500" -I"WINC1500/Board_driver" -I"WINC1500/Example" -I"WINC1500/Support" -I"WINC1500/Driver" -I"WINC1500/Timer1" -I"WINC1500/Common" -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Pure_AC164164.X3.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
