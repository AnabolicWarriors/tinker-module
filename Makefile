

.PHONY: build init windows linux
windows: 
	cd build && \
	cmake .. -G \
		"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release && \
	make

linux: 
	cd build && \
	cmake .. -G \
		"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release && \
	make

build: linux

	
init: 
	echo $(OS)
	ifeq ($(OS),Windows_NT)
		echo "!!"
		if not exist build\ ( \
    		echo "!!!" \
		) else ( \
			echo "@@@" \
		)
	else
		echo "@@"

		if ! [ -d "build" ]; then \
			mkdir build; \
		fi
	endif
	