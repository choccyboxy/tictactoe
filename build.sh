#!/bin/sh

mkdir -p bin

gcc src/main.c src/game.c src/computer.c -o bin/main