## image-converter
Take input of various types of images and convert them to uniform output format.


### Setup

```bash
# create a new virutual environment
$ python -m venv .venv

# activate the environment
$ source .venv/bin/activate

# install project dependencies
$ pip install .
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
$ invoke compile

# perform temporary files cleanup
$ invoke clean
```
