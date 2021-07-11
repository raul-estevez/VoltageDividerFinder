# VoltageDividerFinder

#### Table of contents
- [Installation](#installation)  
    - [Uninstall](#uninstall) 
- [Usage](#usage)  
    - [Arguments](#arguments)  
    - [Resistor File](#resistor-file)  
    - [Example](#example)  
- [Author](#author)  
- [License](#license)  

## Installation 
For installing, clone this repository to your computer, enter in the folder
VoltageDividerFinder and type "make", then "make install" as root.

```bash
$ git clone https://github.com/SarKing/VoltageDividerFinder
$ cd VoltageDividerFinder
$ make
$ sudo make install
```
By default it's installed in /opt/vdf

#### Uninstall

If you want to uninstall the application enter with your terminal in the folder
that you downloaded and type:

```bash
$ sudo make uninstall
```

## Usage
The use is very simple you just need your Vin, the Vout you desire and a file containing all the resistors you have.
```bash
$ vdf Vin Vout filename
```
Then the program will print the 5 best pairs of resistors with less error.

### Arguments

    --verbose            -v      Prints verbose info.
    --help               -h      Displays the help page.
    --version                    Displays the version message.
    
### Resistor file

You enter the resistor you have using the resistor file, the format is as follows:
```bash
10,22,47,100,150,200,220,270,330,470,510,680,1000,2000,2200,3300,4700,5100...
```
You can name it wathever you want.

### Example
Lets say you have Vin = 12v and you want Vout = 8v, you resistors are in my_resistors.txt:
```bash
$ vdf 12 8 my_resistors.txt
```
An example output can be:
```bash
Vin: 12.00
Vout: 8.00
R1: 1000        R2: 2000        Error: 0.0000%
R1: 5100        R2: 10000       Error: 0.6623%
R1: 3300        R2: 6800        Error: 0.9901%
R1: 4700        R2: 10000       Error: 2.0408%
R1: 2200        R2: 4700        Error: 2.1739%
```
## Author 
Raul Estevez Gomez. Contact email: estevezgomezraul@gmail.com  
Please feel free to contact me if you have any type of suggestion or question. 

## License
You can read the license [here](LICENSE)
