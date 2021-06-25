#!/usr/bin/env bash

folders=(ac/ cf/ cses/ ucf/ usaco/)

for folder in "${folders[@]}"; do
    cd ${folder}
    find . -type f  ! -name "*.*"  -delete
    find . -type f  -name "*.in"  -delete
    find . -type f  -name "*.out"  -delete
    cd ".."
done

git add .
git commit -m "update"
git push
