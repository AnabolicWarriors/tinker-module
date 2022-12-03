

.PHONY: build init windows linux
windows: 
	cd build && \
	cmake .. -G \
		"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release && \
	make

linux: 
	cd build && \
	cmake .. -G \
		Ninja -DCMAKE_BUILD_TYPE=Release && \
	ninja

build: init linux

	
init: 
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi
