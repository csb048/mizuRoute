#! /bin/bash

export PROJECT_DIR=/home/cbaker/Hydro/mizuroute-openwq-revised-install
export DATA_DIR=/home/cbaker/Hydro/SUMMAapptainer/case_studies/mizuroute_Great_Slave_Lake

docker run -d -it --name mizuroute-openwq \
    --mount type=bind,source=${PROJECT_DIR},target=/code/mizuroute-openwq \
    --mount type=bind,source=${DATA_DIR},target=/code/data \
    mizuroute-openwq:latest