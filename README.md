# /dev/groot

Linux pseudo-device for the monophrasal member of the Guardians of the Galaxy

## Installation


First, install the necessary packages:

```bash
sudo apt-get install make module-assistant linux-headers-`uname -r`
```

Then, install the device:

```bash
sudo make install
```

To uninstall the device:

```bash
sudo make uninstall
```

To install using [Vagrant](https://www.vagrantup.com/):

```bash
vagrant up && vagrant ssh
sudo make install
```

## Usage

```
$ cat /dev/groot
I am Groot
```

![I am Groot](https://i.imgur.com/P5SkXYi.gif)

## Acknowledgements

Main resource/inspiration can be found [here](http://www.linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html).

Also, all due credit to Marvel Comics, Stan Lee, and Drax the Destroyer.