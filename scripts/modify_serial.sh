#!/bin/bash 
cp ./serial_port.rules /etc/udev/rules.d/
service udev reload
service udev restart
echo "serial port setup success"
