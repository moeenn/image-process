## image-process
A CLI utility to convert & compress images to uniform output.


### Usage

```
usage: image-process [-h] [-i INPUT] [-c] [-d DIMENSIONS]
Compress and convert image files

options:
  -h, --help            show this help message and exit
  -i INPUT, --input INPUT
                        path to input directory
  -c, --compress        Apply compression on input images
  -d DIMENSIONS, --dimensions DIMENSIONS
                        Max dimensions for compressed images (format: width,heigth)

example:
  image-compress --input . --compress -dimensions 1024,768
  image-compress -c
```


### Setup

```bash
# create a new virutual environment
$ python -m venv .venv

# activate the environment
$ source .venv/bin/activate

# install project dependencies
$ pip install .

# install optional dependencies
$ pip install .[dev]
```


### Development commands

```bash
# run the project
$ invoke start

# run tests
$ invoke test

# format and lint code
$ invoke fmt 
$ invoke lint

# compile to stand-alone binary
$ invoke build

# perform temporary files cleanup
$ invoke clean
```
