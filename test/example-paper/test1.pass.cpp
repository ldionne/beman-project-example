//
// This test gets built and run. The test succeeds if the program
// terminates normally with a 0 exit code. The test fails if it
// doesn't compile, link or if it exits with an error.
//

#include <cassert>
#include <example-paper>

int main() {
    assert(foo<int>());
}
