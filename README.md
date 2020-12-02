[![Coverage Status](https://coveralls.io/repos/github/mrcaron/AdventOfCode/badge.svg?branch=main)](https://coveralls.io/github/mrcaron/AdventOfCode?branch=main)

# AdventOfCode
My journeys into Advent of Code

Using [this CMake tut as a starting point](https://riptutorial.com/cmake). 

## A Note on CMake
Codespaces use Debian 9, which have a default installation of CMake 3.7, so it doesn't support google test. Thing to do is use pip to install the latest cmake; 

     pip install cmake

Then use the codespace to edit your `~/.bashrc` file and update your `PATH` to include `/usr/local/bin`. You can simply append this line to the bottom of the `.bashrc`:

    export PATH="/usr/local/bin:$PATH"

Finally, you'll have to disconnet from your codespace session and reconnect. Then cmake will be latest.

## A Note on Google Test

This CMake project uses Google Test, but to get it to build, you need to first install Google Test. You can do this in the following way:

    sudo apt install libgtest-dev
    cd /usr/src/googletest
    sudo cmake .
    sudo cmake --build . --target install

## A Note on code coverage

I'm supporting code coverage... or at least trying to, with the help of [Coveralls.io](https://coveralls.io). Trying to wire it up at the moment.
    
## See Also

For future me...

* https://nnarain.github.io/2016/08/30/Using-GTest-with-CMake-and-Visual-Studio.html
* https://chromium.googlesource.com/external/github.com/google/googletest/+/HEAD/googlemock/docs/for_dummies.md
* https://gitlab.kitware.com/cmake/community/-/wikis/doc/ctest/Testing-With-CTest
* https://thoughts-on-coding.com/2020/04/20/a-cpp-github-template-repository-utilizing-circleci-cmake-docker-and-doxygen/
* https://medium.com/@naveen.maltesh/generating-code-coverage-report-using-gnu-gcov-lcov-ee54a4de3f11 
* https://dr-kino.github.io/2019/12/22/test-coverage-using-gtest-gcov-and-lcov/
