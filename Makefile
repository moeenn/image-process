NAME=image-process
APP=./app
MAIN=./main.py
INSTALL_PREFIX=${HOME}/.local/bin
BUILD_DIR=./build

run:
	python ${MAIN}

test:
	python -m unittest discover -s ${APP} -p '*_test.py'

fmt:
	python -m ruff format ${APP}

lint:
	python -m ruff check ${APP}

build:
	pyinstaller --onefile --specpath=${BUILD_DIR} ${MAIN}

install:
	mv -v ./dist/main ${INSTALL_PREFIX}/${NAME}

clean:
	find . -type d -name '__pycache__' -exec rm -r {} + && \
	rm -rvf ./dist && \
	rm -rvf ./build && \
	rm -rvf ./image_process.egg-info && \
	rm -rvf ./.*_cache && \
	rm -vf ./${NAME}	
	
.PHONY: run fmt lint test build install clean
