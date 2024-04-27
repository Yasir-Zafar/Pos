{
    description = "A Nix Flake of a Point of Sales System";
    inputs = {
      nixpkgs = {
        url = "github:nixos/nixpkgs/nixos-unstable";
      };
      utils = {
        url = "github:numtide/flake-utils";
      }
      ;
    };
    
    outputs = { nixpkgs, utils, ... }:
      utils.lib.eachDefaultSystem (system:
        let
          p = import nixpkgs { inherit system; };
          llvm = p.llvmPackages_latest;
        in {
          devShell = p.mkShell.override { stdenv = p.clangStdenv; } {
            name = "piece_of_shit";

            packages = with p; [
              #builder
              gnumake
              cmake
              
              #fix headers not found
              clang-tools_17

              #stdlib for cpp
              llvm.libcxx
              
              #sql
              sqlite
              
              llvm.libcxxabi
              qt5.full
            ];
            
            shellHook = ''
#Any shellHook commands you want to add
        '';
          };
        }
      );
}
  
