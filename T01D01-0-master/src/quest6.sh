#!/bin/bash

cd ai_help

bash keygen.sh

cd key

ls

find . -type f -empty

find . -type f -empty -exec rm {} \;

cd ..

bash unifier.sh

mv main.key key
