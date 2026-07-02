{
  description = "AtCoder development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      systems = [
        "aarch64-darwin"
        "x86_64-darwin"
      ];

      forAllSystems = f:
        nixpkgs.lib.genAttrs systems (system:
          f (import nixpkgs { inherit system; }));
    in
    {
      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {

          packages = with pkgs; [

            #### Compiler ####
            clang
            clang-tools
            llvmPackages.lldb

            #### Build ####
            cmake
            ninja

            #### Git ####
            git
            curl
            cacert

            #### Python ####
            python3
            python3Packages.online-judge-tools

            #### Node ####
            nodejs_22

            #### Editor ####
            vim
            tmux
          ];

          shellHook = ''
            if ! command -v acc >/dev/null 2>&1; then
              echo "Installing atcoder-cli..."
              npm install -g atcoder-cli
            fi

            echo
            echo "    ####  ##### #   # "
            echo "   #   # #     #   #  "
            echo "  #   # ####  #   #   "
            echo " #   # #      # #     "
            echo "####  #####   #       "
            echo "==============================="
            echo "AtCoder development environment"
            echo "==============================="
            echo "clang : Apple clang version 17.0.0 (clang-1700.6.4.2)"
            echo "lldb  : lldb-1703.0.236.103"
            echo "python: $(python3 --version)"
            echo "oj    : $(oj --version)"
            echo "acc   : $(command -v acc)"
            echo "==============================="
            echo
          '';
        };
      });
    };
}
