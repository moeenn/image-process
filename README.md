# image-process
A C++ program for processing PPM (portable pixel map) images and applying gray-scale effect.

## Compilation
```bash
$ ./script/setup
$ make
```

*Note*: The program binary will be placed in ```bin/```

## What are PPM images
PPM is a simple, text-based, uncompressed image format. Pixel RGB values are layed out sequentially. Calculating grayscale value or a color is as simple as averaging the RBG values of the color i.e. ```(r + g + b) / 3```.
