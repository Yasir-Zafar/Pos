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
              bear
              
              #debugger
              gdb

              #fix headers not found
              clang-tools_17
              llvm.libllvm
              
              #LSP and compiler
              llvm.libstdcxxClang
              
              #stdlib for cpp
              llvm.libcxx
              
              #sql
              sqlite
              
              #qt
              qt5.full
            ];
            
            shellHook = ''
#Any shellHook commands you want to add
        '';
          };
        }
      );
}
  
