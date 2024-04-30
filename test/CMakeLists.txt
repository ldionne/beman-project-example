# Setup the `lit` tool
add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/venv/bin/lit"
    COMMAND python3 -m venv "${CMAKE_CURRENT_BINARY_DIR}/venv"
    COMMAND "${CMAKE_CURRENT_BINARY_DIR}/venv/bin/pip" install --upgrade pip
    COMMAND "${CMAKE_CURRENT_BINARY_DIR}/venv/bin/pip" install --upgrade lit
)

# Setup the test suite configuration
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/support/lit.cfg.in" "${CMAKE_CURRENT_BINARY_DIR}/lit.cfg")

add_custom_target(check
    COMMAND "${CMAKE_CURRENT_BINARY_DIR}/venv/bin/lit" -sv "${CMAKE_CURRENT_BINARY_DIR}"
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/venv/bin/lit"
            "${CMAKE_CURRENT_BINARY_DIR}/lit.cfg"
    COMMENT "Run all the tests"
    USES_TERMINAL
)
