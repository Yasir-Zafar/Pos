# default.nix

{ lib, buildInputs ? [], ... }:

lib.mkShell {
  buildInputs = buildInputs ++ [ (import ./flake.nix) ];
  shellHook = ''
    echo "Entering C++ project environment."

    # Create project directories if they don't exist
    mkdir -p src lib include

    # Optionally set additional environment variables
    export MY_PROJECT_VAR="my_value"

    # Run any additional setup commands here

    # Example: Configure and build the project with CMake
    mkdir -p build
    cd build
    cmake ..
    make
  '';
}
