## image-converter
Take input of various types of images and convert & compress them to uniform output.


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


### Usage

```bash
# start the project
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
