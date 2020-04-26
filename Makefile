SRC_PATH=src
SOURCES=$(wildcard $(SRC_PATH)/*.cpp)
BUILD_PATH=build
OBJECTS=$(patsubst $(SRC_PATH)/*.cpp, $(BUILD_PATH)/*.o, $(SOURCES))
RES_PATH=res

CXX=clang++ -std=c++17
TARGET=$(BUILD_PATH)/themazegame

all: build_dir resources $(TARGET)

build_dir:
	@echo Creating build dir...
	mkdir -p $(BUILD_PATH)

resources: clean_resources
	@echo Copying resources...
	cp -v -r $(RES_PATH) $(BUILD_PATH)/$(RES_PATH)


$(TARGET): $(OBJECTS)
	@echo Compiling executable...
	$(CXX) $^ -o $@

$(OBJECTS): $(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo Compiling objects...
	$(CXX) $(CXXFLAGS) $< -o $@

clean_resources:
	@echo Cleaning resources...
	rm -f -r $(BUILD_PATH)/$(RES_PATH)

clean_objects:
	@echo Cleaning objects...
	rm -f -r $(BUILD_PATH)/$(RES_PATH)

clean_target:
	@echo Cleaning target...
	rm -f -r $(BUILD_PATH)/$(RES_PATH)

clean: clean_resources clean_objects clean_target
