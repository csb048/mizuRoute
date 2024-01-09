# Install Mizuroute-OpenWQ

mizuroute link https://github.com/csb048/mizuRoute/tree/main_openwq_develop

openwq link https://github.com/csb048/openwq/tree/develop_revised_install

### Installation instuctions derived from...
https://simcity.usask.ca/trac/ticket/3207

## Docker

Ensure that Docker is installed on your machine. LINK TO DOCKER

## Installation

### Obtaining Scource Code
* Clone Mizuroute -> https://github.com/csb048/mizuRoute.git
    > Use the main_openwq_develop branch until updated, remember to remove this line
    
    `git clone https://github.com/csb048/mizuRoute.git`

    his will add a folder containg the Summa souce code into the current working dirrectory


* Clone OpenWQ -> https://github.com/csb048/openwq.git
    * cd into `mizuroute/route/build/openwq`
        
        `cd mizuroute/route/build/openwq`
    * Clone OpenWq into the `openwq` folder
        > Use the develop_revised_install branch until updated, remember to remove this line
    
        `git clone https://github.com/csb048/openwq.git` 
    

### The Docker Enviroment

In `mizuroute/utils/` are the files needed for creating and launching the docker container.

*  Open `launch_docker_container.sh` in a text editor
    * Change the `PROJECT_DIR` variable to the dirrectory containing the vesion of `mizuroute` that was cloned (not `OpenWQ`).
    * Change the `DATA_DIR` variable to a dirrectory contiaing the data you want to use for running the simulations
    
    Now these two dirrectories can be accses and modified from within the container.

* Run the `build_docker_container.sh` script to build the container
    `./build_docker_container.sh`

* Now run the `launch_docker_container.sh` script **AFTER** modifying it to match your enviroment
    `./launch_docker_container.sh`
### Compiling Mizuroute-OpenWQ



### Setup Synthetic Tests


### Running Summa-OpenWQ


# Common Issues



