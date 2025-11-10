NAME=goglwrapper
SOURCEDIR := src
BUILDDIR := build
HEADERS_INSTALL_DIR := include

CC_NATIVE := g++
BUILDDIR_NATIVE := $(BUILDDIR)/native
TARGET_NATIVE := $(BUILDDIR_NATIVE)/bin/lib$(NAME).a

CC_WASM := em++
BUILDDIR_WASM := $(BUILDDIR)/wasm
TARGET_WASM := $(BUILDDIR_WASM)/bin/lib$(NAME).a

SOURCES := $(shell find $(SOURCEDIR) -name "*.cpp")
HEADERS_INSTALL := $(shell find $(HEADERS_INSTALL_DIR) -name "*.h")
OBJECTS_NATIVE := $(patsubst $(SOURCEDIR)/%, $(BUILDDIR_NATIVE)/%, $(SOURCES:.cpp=.o))
OBJECTS_WASM := $(patsubst $(SOURCEDIR)/%, $(BUILDDIR_WASM)/%, $(SOURCES:.cpp=.o))

# compiler flags
DEBUG_FLAGS := -g -O0
COMPILER_FLAGS := -std=gnu++20 -fPIC $(DEBUG_FLAGS)

ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

all: $(TARGET_NATIVE) $(TARGET_WASM)

$(TARGET_NATIVE): $(OBJECTS_NATIVE)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

$(BUILDDIR_NATIVE)/%.o: $(SOURCEDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC_NATIVE) $(COMPILER_FLAGS) -c $< -o $@

$(TARGET_WASM): $(OBJECTS_WASM)
	@mkdir -p $(dir $@)
	emar rcs $@ $^

$(BUILDDIR_WASM)/%.o: $(SOURCEDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC_WASM) $(COMPILER_FLAGS) -c $< -o $@

install:
	install -d $(DESTDIR)$(PREFIX)/include/$(NAME)/
	install -m 644 $(HEADERS_INSTALL) $(DESTDIR)$(PREFIX)/include/$(NAME)/
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $(TARGET_NATIVE) $(DESTDIR)$(PREFIX)/lib/
	install -d $(DESTDIR)$(PREFIX)/wasm/lib/
	install -m 644 $(TARGET_WASM) $(DESTDIR)$(PREFIX)/wasm/lib/

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
