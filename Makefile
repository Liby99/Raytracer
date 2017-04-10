CC = @ g++ -MMD -O3
LD = @ ld -r
MKDIR = @ mkdir -p
ECHO = @ echo
RM = @ /bin/rm -rf
MAKE = @ make

ifeq ($(shell sw_vers 2>/dev/null | grep Mac | awk '{ print $$2}'), Mac)
CFLAGS = -g -DGL_GLEXT_PROTOTYPES -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -DOSX -Wno-deprecated-register -Wno-deprecated-declarations -Wno-shift-op-parentheses
INCFLAGS = -I./lib/glm-0.9.7.1 -I/usr/X11/include -I./src/class
endif

BUILD_DIRECTORY := ./build/

CPP_DIRECTORY := ./src/private/
BIN_DIRECTORY := ./build/bin/
CPP_FILES := $(wildcard $(CPP_DIRECTORY)*/*.cpp)
OBJ_FILES := $(patsubst $(CPP_DIRECTORY)%.cpp, $(BIN_DIRECTORY)%.o, $(CPP_FILES))
OBJ_DIRECTORIES := $(sort $(dir $(OBJ_FILES)))

TEST_DIRECTORY := ./test/
BUILD_TEST_DIRECTORY := ./build/test/
TEST_CPP_FILES := $(wildcard $(TEST_DIRECTORY)*.cpp)
TESTS := $(basename $(notdir $(TEST_CPP_FILES)))
TEST_OBJ_FILES := $(addprefix $(BUILD_TEST_DIRECTORY), $(TESTS))

RAYTRACER := ./build/raytracer.o

all: $(TEST_OBJ_FILES)
	$(MAKE) cleanCache

$(TESTS): $(patsubst $(TEST_DIRECTORY)%.cpp, $(BUILD_TEST_DIRECTORY)%, $@)
	
$(BUILD_TEST_DIRECTORY)%: $(TEST_DIRECTORY)%.cpp $(RAYTRACER) | $(BUILD_TEST_DIRECTORY)
	$(ECHO) "Building Test File $@"
	$(CC) $(CFLAGS) $(TEST_DIRECTORY)$(basename $(notdir $@)).cpp $(RAYTRACER) -o $@ $(INCFLAGS)
	
$(RAYTRACER): $(OBJ_FILES)
	$(ECHO) "Linking Raytracer"
	$(LD) $(OBJ_FILES) -o $(RAYTRACER)
	
$(BIN_DIRECTORY)%.o: $(CPP_DIRECTORY)%.cpp | $(OBJ_DIRECTORIES)
	$(ECHO) "Building $@"
	$(CC) $(CFLAGS) -c $< -o $@ $(INCFLAGS)
	
$(BUILD_TEST_DIRECTORY): | $(BUILD_DIRECTORY)
	$(ECHO) "Creating $@ Directory"
	$(MKDIR) $@
	
$(OBJ_DIRECTORIES): | $(BIN_DIRECTORY)
	$(ECHO) "Creating $@ Directories"
	$(MKDIR) $@

$(BIN_DIRECTORY): | $(BUILD_DIRECTORY)
	$(ECHO) "Creating $@ Directory"
	$(MKDIR) $@

$(BUILD_DIRECTORY):
	$(ECHO) "Creating $@ Directory"
	$(MKDIR) $@
	
cleanCache:
	$(ECHO) "Cleaning Caches"
	$(RM) $(BUILD_TEST_DIRECTORY)*.dSYM $(BUILD_TEST_DIRECTORY)*.d $(BIN_DIRECTORY)*/*.d .d

cleanRaytracer:
	$(RM) $(RAYTRACER)
	
cleanTest:
	$(RM) $(addprefix $(BUILD_TEST_DIRECTORY), $(TESTS)) $(addprefix $(BUILD_TEST_DIRECTORY), $(addsuffix .dSYM, $(TESTS)))

cleanObj:
	$(RM) $(OBJ_FILES) $(OBJ_FILES:.o=.d) .d

clean:
	$(MAKE) cleanRaytracer
	$(MAKE) cleanTest
	$(MAKE) cleanObj

removeBuild:
	$(RM) $(BUILD_DIRECTORY)
