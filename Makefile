ARCHS = arm64
TARGET = iphone:clang:16.5:14.0

TWEAK_NAME = standarling

standarling_FILES = $(shell find src/cpp -name "*.cpp" -o -name "*.mm" 2>/dev/null) \
                    $(shell find src/objc -name "*.mm" 2>/dev/null)

standarling_CFLAGS = -fobjc-arc \
                     -Isrc/cpp \
                     -Isrc/cpp/game \
                     -Isrc/cpp/game/sdk \
                     -w

standarling_CCFLAGS = -std=c++20 \
                      -Isrc/cpp \
                      -Isrc/cpp/game \
                      -Isrc/cpp/game/sdk \
                      -w

standarling_FRAMEWORKS = UIKit Foundation CoreGraphics

include $(THEOS)/makefiles/common.mk
include $(THEOS)/makefiles/tweak.mk
