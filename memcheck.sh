#!/bin/bash
make && valgrind -s --track-origins=yes --leak-check=full \
--show-leak-kinds=all ./monty bytecodes/01.m
