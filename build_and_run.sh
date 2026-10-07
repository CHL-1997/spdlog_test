#!/bin/bash

app="spdlog_test"

function func_run()
{
    echo "start runing...";echo
    ./${app}
    echo;echo "done"
}

if [ ! -d "build" ]; then
    mkdir build
    cd build
    cmake ..
    if [ $? -ne 0 ]; then
        echo "cmake failed"
        exit 1
    fi
else
    cd build
fi

#make -j$(nproc)
cmake --build . --parallel
if [ $? -ne 0 ]; then
    echo "make failed"
    exit 1
fi

func_run