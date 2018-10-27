# What is it?

This application can be used to download data from on-line shop vubu.pl.
The data contains all the offers you can find there.

This project was made by:  
* Jakub Rak
* Marcin Stanuch
* Maciej Małochleb

# How to install?

## Requirements for Linux (Ubuntu) enviroment

Python3 applications

    sudo apt install python3 python3-venv

Git

    sudo apt install git

Postgresql (if needed):

    sudo apt install postgresql
    pgadmin III (use app store)

## Creating project enviroment

First, create folder for the project

    mkdir vubuetl
    cd vubuetl

Then, prepare python 3.x virtual enviroment

    python3 -m venv virt

Activate the enviroment

    source virt/bin/activate

Deactivating under `deactivate` command
Then clone the project:

    git clone git@github.com:einstein13/vubuetl.git (for ssh connection, recommended)
    git clone https://github.com/einstein13/vubuetl.git (for https connection)
    cd vubuetl

Install all required python3 packages

    pip install -r requirements.txt

Then it is a time for setting up a postgresql database.  
After proper installation, migrate the data

    python manage.py migrate

Then your project is ready to run:

    python manage.py runserver

You can open your browser and open `127.0.0.1:8000` address. The project will work there.

# How to run installed project?

First, go to the proper directory

    cd vubuetl/vubuetl

Activate python enviroment

    source ../virt/bin/activate

And runs server

    python manage.py runserver

# How to close/reset the server running?

Most of the cases when you change the code, the server will restart automaticly.
But if you have to force-reset, use `Ctrl+C` combination to kill it and

    python manage.py runserver

To close the server (fully), use `Ctrl+C` and `deactivate` command.

# Other useful commands

All possible django commands are listed after typing

    python manage.py

The most useful command is opening python shell under this enviroment with all possible models:

    python manage.py shell

To run any user script (from file) under this shell, you can type just

    import SCRIPT_NAME.py
