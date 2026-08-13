#!/bin/bash

if [ ! -e /sys/class/gpio/gpio15 ]; then
    echo 15 > /sys/class/gpio/export
fi

echo in > /sys/class/gpio/gpio40/direction

cat /sys/class/gpio/gpio40/value


