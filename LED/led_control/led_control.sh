#!/bin/bash

echo none > /sys/class/leds/work/trigger

if [ "$1" = "1" ]; then
    echo 1 > /sys/class/leds/work/brightness
elif [ "$1" = "0" ]; then
    echo 0 > /sys/class/leds/work/brightness
fi