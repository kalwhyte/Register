## Register Program ##

The Register program is a simple command-line application written in C that allows users to manage a register of people. Users can add new people to the register, print the contents of the register, and quit the program.

## Table of Contents ##
- Introduction
- Functionality
- Usage

**Introduction**
The program uses a struct called `Person` to represent an individual in the register. Each `Person` struct contains the following information:

- `name`: The person's name.
- `surname`: The person's surname.
- `cohort`: The person's cohort.
- `location`: The person's location.

The program allows users to interact with the register through a simple menu system. Users can choose from the following options:

1. **Add person to register**: Users can enter the person's details (name, surname, cohort, and location) and add them to the register. The program checks if the register is full before allowing the addition.
2. **Print register**: Users can view the contents of the register, which displays the name, surname, cohort, and location of each person.
3. **Quit**: Users can choose to exit the program.

## Functionality ##
The program provides the following functionality:

- **Adding a person to the register**: Users can add a new person to the register by entering their name, surname, cohort, and location. The program validates the input and ensures that the register is not full before adding the person.
- **Printing the register**: Users can print the contents of the register, which displays the details of each person currently in the register. The information displayed includes the person's name, surname, cohort, and location.
- **Quitting the program**: Users can choose to exit the program at any time by selecting the "Quit" option from the menu.
##Usage##
To compile the program, use the following command:

`gcc register.c -o register`

To run the program, execute the following command:
```
./register
```
Once the program is running, follow the on-screen prompts and select the desired options from the menu. You can add new people to the register, print the register's contents, or quit the program.

Note: The register has a maximum capacity defined by the `MAX_SIZE` constant. If the register is full, you will not be able to add additional people until some space becomes available.

Enjoy using the Register program to manage your list of people!

More updates to come, next will be to add a database for storage purpose!!!

##Do Hard THings##
