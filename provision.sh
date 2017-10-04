#!/bin/bash

# packages
sudo apt-get update
sudo apt-get -y install make module-assistant linux-headers-`uname -r`

# ssh helper
printf "\n#login directory\ncd %s\n" /vagrant >> /home/vagrant/.profile