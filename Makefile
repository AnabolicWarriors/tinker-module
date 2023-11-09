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

run: build
	./build/chacha -c "/dev/ttyUSB0" -b 19200 -v 220.68.5.97 -p 5001 -l 113.198.229.227 -a 30000

