#!/bin/bash

if [ ! -e /sys/class/gpio/gpio15 ]; then
    echo 15 > /sys/class/gpio/export
fi

echo out > /sys/class/gpio/gpio15/direction

if [ "$1" == "1" ]; then
    echo 1 > /sys/class/gpio/gpio15/value
elif [ "$1" == "0" ]; then
    echo 0 > /sys/class/gpio/gpio15/value
fi

