CC = @ g++ -MMD -O3
LD = @ ld -r
MKDIR = @ mkdir -p
ECHO = @ echo
ifeq ($(shell sw_vers 2>/dev/null | grep Mac | awk '{ print $$2}'), Mac)
CFLAGS = -g -DGL_GLEXT_PROTOTYPES -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -DOSX -Wno-deprecated-register -Wno-deprecated-declarations -Wno-shift-op-parentheses
INCFLAGS = -I./lib/glm-0.9.7.1 -I/usr/X11/include -I./src/class
endif

CPP_FILES := $(wildcard ./src/private/*/*.cpp)
OBJ_FILES := $(patsubst ./src/private/%.cpp, ./build/bin/%.o, $(CPP_FILES))
DIRECTORIES := $(sort $(dir $(OBJ_FILES)))
TEST_CPP_FILES := $(wildcard ./test/*.cpp)
TESTS := $(basename $(notdir $(TEST_CPP_FILES)))
RAYTRACER := ./build/raytracer.o
RM = /bin/rm -rf

all: $(TESTS)

$(TESTS): raytracer
	$(ECHO) "Building Test File $@"
	$(CC) $(CFLAGS) ./test/$@.cpp $(RAYTRACER) -o ./build/$@ $(INCFLAGS)
	
raytracer: $(OBJ_FILES)
	$(ECHO) "Linking Raytracer"
	$(LD) $(OBJ_FILES) -o $(RAYTRACER)
	
./build/bin/%.o: ./src/private/%.cpp | directory
	$(ECHO) "Building $@"
	$(CC) $(CFLAGS) -c $< -o $@ $(INCFLAGS)
	
directory:
	$(ECHO) "Creating Directories"
	$(MKDIR) $(DIRECTORIES)

print:
	$(ECHO) "cpp files: $(CPP_FILES)"
	$(ECHO) "obj files: $(OBJ_FILES)"
	$(ECHO) "directories: $(DIRECTORIES)"

clean:
	$(RM) $(BUILD_FILES) $(OBJ_FILES) *.d *.DSYM
