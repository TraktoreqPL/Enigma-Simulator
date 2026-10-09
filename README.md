# Enigma-Simulator

## What is it?
This is an Enigma machine simulator written in *ANSI C*.

## How to use it?
Download or clone this repository, then unpack it.

### On Windows
Go to the repository folder in **File Explorer**, click on the address bar (where the folder path is shown), type `"cmd"`, and press *Enter*. This will open the **Command Prompt** in that directory.

Next, run the following command:
`enigma.exe 0 1 2 0 0 0 0 A B C D E F G H I J K L M N O P R S T U`

You might be interested in what those numbers and letters mean, but I will explain that later. 

After running the command, you will see a new line. Now you can type the text that you want to encrypt or decrypt using **only uppercase letters and spaces**. Press *Enter* and, if there are no errors, you will see the encrypted text. 

Since the Enigma cipher is symmetrical, if you run the encrypted text through the simulator again with the exact same settings, it will decrypt it.

### On POSIX
I don't provide a precompiled executable for POSIX systems, but you can easily compile it yourself. For example:
`clang main.c rotors.c reflector.c plugboard.c -Os -flto -ansi -o enigma -static`

This is the command that I used, but you can use other flags and different compilers like `gcc` or `cc`. Run the compiled program the same way as on Windows, but without the `.exe` extension.

## What do those numbers and letters mean?
These are the machine settings:
* The first **3 numbers** represent the mounted rotors. They have IDs from `0` to `4`.
* The next **3 numbers** are the rotor shifts (starting positions), ranging from `0` to `25`.
* The next number is the mounted reflector ID, from `0` to `2`.
* The **letters** represent the plugboard configuration. There must be exactly 20 of them. The first 10 are the input pins and the remaining 10 are the output pins. An input pin index matches its connected output pin index. For example, if the input pin is `A` and the output pin is `K`, `A` will be swapped with `K` and `K` will be swapped with `A`.

## What do I want to add?
* **Configuration files** - This will eliminate the risk of typos. You will be able to just send a configuration file to someone and it will work out of the box.
* **Advanced error handling** - Currently, the project only has basic error handling, but it's possible to add a more robust system.
* **Easy and lightweight GUI** - So regular users can operate it without reading this technical tutorial.

## How to help me with this project?
If you know *ANSI C* and want to work on one of these tasks, just open a **Pull Request**. If you don't know the language yet, you can learn it (it's quite simple!) or share your ideas with me in the **Issues** tab.
