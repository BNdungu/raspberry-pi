#!/bin/sh

# Disable screen blanking ans screen saver
    xset s 0
    xset s off
    xset dpms 0 0 0
    xset -dpms

# Set Display rotation:rotate 90 degrees
    xrandr -o 3

# Set touch Screen orientation rotate:90
    xinput set-prop "wch.cn ChipOne Hid DFU Tool" "Coordinate Transformation Matrix"  -1 0 1 0 -1 1 0 0 1
