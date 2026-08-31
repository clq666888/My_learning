#!/bin/bash

if [ ! -e /sys/class/pwm/pwmchip0/pwm0 ]; then
  echo 0 > /sys/class/pwm/pwmchip0/export
fi

echo 1000000 > /sys/class/pwm/pwmchip0/pwm0/period
echo normal > /sys/class/pwm/pwmchip0/pwm0/polarity
echo $1 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable
