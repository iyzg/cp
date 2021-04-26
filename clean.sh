#!/usr/bin/env bash

folders=(ac/ )

for folder in "${folders[@]}"; do
    cd ${folder}
    find . -type f  ! -name "*.*"  -delete
    cd ".."
done
