#!/bin/bash

echo none > /sys/class/leds/work/trigger
echo $1 > /sys/class/leds/work/brightness

