#!/bin/bash

mv door_management_fi door_management_files


cd door_management_files
mkdir door_configuration
mkdir door_map
mkdir door_logs

mv door_*.conf door_configuration
mv door_map_1.1 door_map
mv door_*.log door_logs

cxmod 777 ai_door_control.sh
