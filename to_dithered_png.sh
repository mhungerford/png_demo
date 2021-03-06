#!/bin/bash
#requires ImageMagick for png options
convert $1 \
  -adaptive-resize '144x168>' \
  -fill '#FFFFFF00' -opaque none \
  -type Grayscale -colorspace Gray \
  -black-threshold 30% -white-threshold 70% \
  -ordered-dither 2x1 \
  -colors 2 -depth 1 \
  -define png:compression-level=9 -define png:compression-strategy=0 \
  -define png:exclude-chunk=all \
  ${1%.png}.mod.png

#fill #FFFFFF00 -opaque none makes the transparency white
#adaptive resize with > at end means resize only if larger, and maintains aspect ration
#between black and white threshold is 3rd color, grey
#ordered dither is positional dithering with 1 pattern (grey_50)
#we exclude png chunks to reduce size (like when image was made, author)
