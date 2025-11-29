#!/usr/bin/env bash

function do_it() {
    clang++ -std=c++17 -Wall -Wextra -Wpedantic $1 -o out && ./out
}

do_it "$@"
