cmake_minimum_required(VERSION 3.15.3)

# Optional: print out extra messages to see what is going on. Comment it to have less verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

# Path to toolchain file. This one has to be before 'project()' below
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake)

# Setup project, output and linker file
project(tk499)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/CMSIS_and_startup/TKM32F499_FLASH.ld)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Optional: issue a message to be sure it uses the correct toolchain file.
message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

# List of source files
set(SRC_FILES
        ./CMSIS_and_startup/startup_tkm32f499.s
        ./CMSIS_and_startup/sys.c
        ./project/bsp/main.c
        ./project/bsp/LCD/LCD.c
        ./Hal_lib/src/HAL_gpio.c
        ./Hal_lib/src/HAL_rcc.c
        ./Hal_lib/src/HAL_misc.c
        ./Hal_lib/src/HAL_uart.c
        ./Hal_lib/src/HAL_i2c.c
        ./Hal_lib/src/HAL_tim.c
        ./project/bsp/UART/UART.c
        ./project/bsp/TK499_I2C/TK499_I2C.c
        ./project/bsp/touch/touch_CTP.c
        ./project/bsp/timer/timer.c
        ./project/ui/ui_helpers.c
        ./project/ui/ui.c


        # ./project/lvgl/porting/lv_port_disp.c
        # ./project/lvgl/porting/lv_port_indev.c
        # ./project/lvgl/src/core/*.c
        # ./project/lvgl/src/draw/*.c
        # ./project/lvgl/src/extra/*.c
        # ./project/lvgl/src/font/*.c
        # ./project/lvgl/src/gpu/*.c
        # ./project/lvgl/src/hal/*.c
        # ./project/lvgl/src/misc/*.c
        # ./project/lvgl/src/widgets/*.c

        )

file(GLOB_RECURSE LVGL_SRC RELATIVE ${CMAKE_SOURCE_DIR} "./project/lvgl/*.c")

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES} ${LVGL_SRC})

# List of compiler defines, prefix with -D compiler option
target_compile_definitions(${EXECUTABLE} PRIVATE
        -DLV_LVGL_H_INCLUDE_SIMPLE
        )

# List of includ directories
target_include_directories(${EXECUTABLE} PRIVATE
        ./CMSIS_and_startup
        ./CMSIS_and_startup/CMSIS
        ./Hal_lib/inc/
        ./project/bsp/LCD
        ./project/bsp/UART
        ./project/bsp/TK499_I2C/
        ./project/bsp/touch/
        ./project/bsp/timer/
        ./project/ui/

        ./project/
        ./project/lvgl/
        ./project/lvgl/porting/
        ./project/lvgl/src/
        ./project/lvgl/src/core/
        ./project/lvgl/src/draw/
        ./project/lvgl/src/extra/
        ./project/lvgl/src/font/
        ./project/lvgl/src/gpu/
        ./project/lvgl/src/hal/
        ./project/lvgl/src/misc/
        ./project/lvgl/src/widgets/
        )

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard

        -fdata-sections
        -ffunction-sections

        -Wall
        -O1
        -g
        )

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
        -T${LINKER_FILE}
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -specs=nosys.specs
        -specs=nano.specs
        -lc
        -lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        -Xlinker -print-memory-usage -Xlinker
        )

# Optional: Print executable size as part of the post build process
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE})

# Optional: Create hex, bin and S-Record files after the build
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        # COMMAND ${CMAKE_OBJCOPY} -O srec --srec-len=64 ${EXECUTABLE} ${PROJECT_NAME}.s19
        # COMMAND ${CMAKE_OBJCOPY} -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)